/*
 * Time Since Launch firmware for ATXMEGA63B3
 *
 * https://github.com/bigjosh/TSL
 *
 */

// Required AVR Libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "lcd.h"

#include "USI_TWI_Master.h"

#define F_CPU 2000000		// Default internal RC clock on startup

#define RX8900_TWI_ADDRESS 0b0110010        // RX8900 8.9.5 (datasheet page 29)

#define RX8900_FLAG_REG        0x0e
#define RX8900_CONTROL_REG     0x0f
#define RX8900_BACKUP_REG      0x18

#define RX8900_BACKUP_VDETOFF_bm   (1<<3)      // Setting to 1 disables the low voltage detect
#define RX8900_BACKUP_SWOFF_bm     (1<<4)      // Setting to 1 opens the MOS switch


#include <util/delay.h>

typedef __uint24  uint24_t;     // Make 24 bit type look normal

// Run RTC from internal 32KHz osc

void enable_rtc_in32() {

	//////////////////////////////////////////////////////////////////////
	//CLK.RTCCTRL
	//     7       6       5       4       3       2       1       0
	// |   -   |   -   |   -   |   -   |      RTCSRC[2:0]     |  RTCEN  |
	//     0       0       0       0       0       0       0       0
	// LCD Runs off the RTC


	// Enable RTC, source from 32kHz XTAL
    CCP = CCP_IOREG_gc; //Trigger protection mechanism
	CLK.RTCCTRL = CLK_RTCEN_bm | CLK_RTCSRC0_bm;
	// ~2.6uA

    // By default "1kHz from 32kHz internal ULP oscillator, but The LCD will always use the non-prescaled 32kHz oscillator output as clock source"


	//////////////////////////////////////////////////////////////////////
}


// Run RTC from external 32KHz xtal

void enable_rtc_32Kxtal() {

    //////////////////////////////////////////////////////////////////////
    //CLK.RTCCTRL
    //     7       6       5       4       3       2       1       0
    // |   -   |   -   |   -   |   -   |      RTCSRC[2:0]     |  RTCEN  |
    //     0       0       0       0       0       0       0       0
    // LCD Runs off the RTC

    // Set low power mode on XTAL drive
    //OSC.XOSCCTRL |= OSC_X32KLPM_bm;

    // Enable RTC, source from 32kHz XTAL
    CCP = CCP_IOREG_gc; //Trigger protection mechanism
    CLK.RTCCTRL = CLK_RTCEN_bm | CLK_RTCSRC_TOSC32_gc;
    // ~2.6uA


    // By default "1kHz from 32kHz internal ULP oscillator, but The LCD will always use the non-prescaled 32kHz oscillator output as clock source"

    //////////////////////////////////////////////////////////////////////
}

void switch2XtalSysClock() {


//    CCP = CCP_IOREG_gc; //Trigger protection mechanism
//    OSC.XOSCCTRL = OSC_XOSCSEL_32KHz_gc;       // Low power mode, 32KHZ XTAL

    CCP = CCP_IOREG_gc; //Trigger protection mechanism
    OSC.XOSCCTRL = OSC_X32KLPM_bm | OSC_XOSCSEL_32KHz_gc;       // Low power mode, 32KHZ XTAL

    OSC.CTRL |= OSC_XOSCEN_bm;      // Enable ext osc for sys clock

    while (! (OSC.STATUS & OSC_XOSCRDY_bm));       // Wait for osc to be ready

    CCP = CCP_IOREG_gc; //Trigger protection mechanism
    CLK.CTRL = CLK_SCLKSEL_XOSC_gc;             // Switch system clock to xternal osc


    // Takes two cycles on old clock to complete the switch
    //nop();
    //nop();

  // CCP = CCP_IOREG_gc; //Trigger protection mechanism
  // OSC.CTRL &= ~OSC_RC2MEN_bm;             // Clear 2mhz enable now that we dont need it anymore

}



#define PIN4_INIT()     PORTC.DIRSET = _BV( 3 )
#define PIN4_UP()       PORTC.OUTSET = _BV( 3 )
#define PIN4_DOWN()     PORTC.OUTCLR = _BV( 3 )


void enable_rtc_ulp() {

    //////////////////////////////////////////////////////////////////////
    //CLK.RTCCTRL
    //     7       6       5       4       3       2       1       0
    // |   -   |   -   |   -   |   -   |      RTCSRC[2:0]     |  RTCEN  |
    //     0       0       0       0       0       0       0       0
    // LCD Runs off the RTC


    // Enable RTC, source from 32kHz internal ULP osc
    CLK.RTCCTRL = CLK_RTCEN_bm; // 0x01

    // TODO: Try X32KLPM low power xtal drive in XOSCCTRL

    // By default "1kHz from 32kHz internal ULP oscillator, but The LCD will always use the non-prescaled 32kHz oscillator output as clock source"


    //////////////////////////////////////////////////////////////////////
}

void enable_rtc_TOSC1_32K() {

    //////////////////////////////////////////////////////////////////////
    //CLK.RTCCTRL
    //     7       6       5       4       3       2       1       0
    // |   -   |   -   |   -   |   -   |      RTCSRC[2:0]     |  RTCEN  |
    //     0       0       0       0       0       0       0       0
    // LCD Runs off the RTC

    // Enable RTC from external clock on TOSC1
    CCP = CCP_IOREG_gc; //Trigger protection mechanism
    CLK.RTCCTRL = CLK_RTCEN_bm | CLK_RTCSRC_EXTCLK_gc;


    // By default "1kHz from 32kHz internal ULP oscillator, but The LCD will always use the non-prescaled 32kHz oscillator output as clock source"

    //////////////////////////////////////////////////////////////////////
}

// Use external osc as system clock

void sysclk2osc() {
    CCP = CCP_IOREG_gc; //Trigger protection mechanism
    CLK.CTRL = CLK_SCLKSEL_XOSC_gc;
}



void pmic_init(void) {

	//////////////////////////////////////////////////////////////////////
	//PMIC.CTRL
	//     7       6       5       4       3        2         1         0
	// | RREN  | IVSEL |   -   |   -   |   -   | HILVLEN | MEDLVLEN | LOLVLEN |
	//     0       0       0       0       0        0         0         0
	// Enable all interrupt levels
	// Load Int vectors to application section of flash
	// Set interrupt priority to Static (lower address = higher priority)
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm; //0x07
	//////////////////////////////////////////////////////////////////////

}



void lcd_init(void) {

	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLA
	//     7        6       5        4        3        2       1       0
	// | ENABLE | XBIAS | DATCLK | COMSWP | SEGSWP | CLRDT | SEGON | BLANK|
	//     0        0       0        0        0        0       0       0
	// Clear the display memory
	LCD.CTRLA = LCD_CLRDT_bm; //0x04 - internal charge pump
    	//LCD.CTRLA = LCD_XBIAS_bm | LCD_CLRDT_bm; //0x04 - external bias voltage

	//////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLB
	//     7        6       5       4        3       2       1      0
	// | PRESC |       CLKDIV[2:0]       | LPWAV |   -   |   DUTY[1:0]   |
	//     0        0       0       0        0       0       0      0
	// Frame Rate set to 64 Hz
	// LP Wave Enabled
	// 1/4 Duty, 1/3 Bias, COM[0:3] used
//	LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV1_bm | LCD_CLKDIV0_bm ; //0xB8 -0 No Low Power, prescale 0 so 125Hz frame rate
//	LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV1_bm | LCD_CLKDIV0_bm ; //0xB8 -0 No Low Power
//	LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV2_bm |LCD_CLKDIV1_bm | LCD_CLKDIV0_bm ; //No Low power waveform         3.7uA



    LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV2_bm |LCD_CLKDIV1_bm | LCD_CLKDIV0_bm | LCD_LPWAV_bm; //0xB8   2.65uA
    // WORKS BEST FOR 32KHZ clock (ulp or xtal)
    // PRESC divides the 32khz clock /16 into the LCD to 2khz
    // Clockdiv 111 further /8 to 2KHz down to 256Hz
    // We are running 1/4 duty, so actual frame rate is /8 of 256Hz to 32Hz.
    // This give a slight flicker, but ok.


    // LCD.CTRLB = LCD_LPWAV_bm; //0xB8   ?uA
    // PREC = 0 means div 8, gets us to 1024/8= 128Hrz
    // CLKDIV = 0 means div 1, so stay at 128Hrz
    // Ends up with LCD clock=1/8 TOSC
    // TESTING 1KHz TOSC LCD clock. Uses more power!



	//////////////////////////////////////////////////////////////////////

    //TODO: Check impact of low power waveform here

	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLC
	//     7       6       5       4        3        2       1       0
	// |   -   |   -   |                   PMSK[5:0]                     |
	//     0       0       0       0        0        0       0       0
	// Enable all segment drivers on micro
	LCD.CTRLC = LCD_PMSK_gm; // 0x3F
	//////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////
	//LCD.INTCTRL
	//     7        6       5       4        3       2       1      0
	// |                XIME[4:0]                |   -   | FCINTLVL[1:0] |
	//     0        0       0       0        0       0       0      0
	// Set Frame Complete Interrupt
	// Default Waveforms:	Int Period = XIME[4:0] + 1
	// LP Waveform:			Int Period = (XIME[4:0] + 1) * 2
	//LCD.INTCTRL = LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 16 frames with high priority

    //LCD.INTCTRL =  LCD_XIME3_bm | LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 32 frames with high priority (1 Hz)

    // NO LCD INTERRUPT. We will update display based on FOE from RX8900 RTC.

    // For low power waveforms requiring 2 subsequent frames, the FCIF flag is generated every
    // 2 x ( XIME[4:0] + 1 ) frames. The range is 2 up to 64 frames

	//////////////////////////////////////////////////////////////////////

    //TODO: Confirm INT generated every 16 frames = 0.25 sec = 4 Hz
    //TODO: When we switch to normal run mode, then only INT once per second.

	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLD
	//     7       6       5       4        3        2       1       0
	// |   -   |   -   |   -   |   -   | BLINKEN |   -   | BLINKRATE[1:0] |
	//     0       0       0        0       0        0       0       0
	// Disable hardware blinking
	//LCD.CTRLD = ~LCD_BLINKEN_bm; // 0x00
    // Not needed, it is off by Default. -JL
	//////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLA
	//     7        6       5        4        3        2       1       0
	// | ENABLE | XBIAS | DATCLK | COMSWP | SEGSWP | CLRDT | SEGON | BLANK|
	//     0        0       0        0        0        0       0       0
	// Enable LCD
	// Enable all LCD segments
	LCD.CTRLA |= LCD_ENABLE_bm | LCD_SEGON_bm | LCD_CLRDT_bm; // 0x82
	//////////////////////////////////////////////////////////////////////

	// set LCD contrast with signed int value between -32 ~ 31
	// -32 corresponds to a segment voltage of approx 2.5V
	//   0 corresponds to a segment voltage of approx 3.0V
	//  31 corresponds to a segment voltage of approx 3.5V
	// Default is 0 (3.0V)
	LCD.CTRLF = 0;
    //TODO: Check contrast settings
}

//  Disable unused peripherals to save power

void prr_init() {

    // Disable everything but the LCD & RTC

    // Disabling RTC does not noticeably reduce power

    PR.PRGEN = PR_USB_bm | PR_AES_bm | PR_EVSYS_bm | PR_DMA_bm | PR_RTC_bm;


    // These following lines reduce power consumption during active mode
    // I do not understand why there are separate registers for the different ports.
    PR.PRPA = PR_ADC_bm | PR_AC_bm;
    PR.PRPB = PR_ADC_bm | PR_AC_bm;
    PR.PRPC = PR_TWI_bm | PR_USART0_bm | PR_SPI_bm | PR_HIRES_bm | PR_TC1_bm | PR_TC0_bm;
    PR.PRPE = PR_TWI_bm | PR_USART0_bm | PR_SPI_bm | PR_HIRES_bm | PR_TC1_bm | PR_TC0_bm;

}

// Disable JTAG interface as per 4.18.6
// Note that this does not seem to save any power, but it couldn't hurt neither.

void inline disableJTAG() {

    CCP = CCP_IOREG_gc;          // Enable change to IOREG
    MCU.MCUCR = MCU_JTAGD_bm;    // Setting this bit will disable the JTAG interface
}

inline void clearLCD() {
	LCD.CTRLA |= LCD_ENABLE_bm | LCD_SEGON_bm | LCD_CLRDT_bm; // 0x82
}

/*

inline void lcd_1hz(void) {
    LCD.INTCTRL = LCD_XIME4_bm | LCD_XIME3_bm | LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 64 frames with high priority (1 Hz)
}

inline void lcd_2hz() {
	LCD.INTCTRL = LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 16 frames with high priority - 2Hz
}

// Interrupt (or set FCIF flags) every time a frame is complete

inline void lcd_1frame() {
    LCD.INTCTRL = LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 16 frames with high priority - 2Hz
}

*/

// Save power by avoiding floating pins. Disables input buffers.
// appears to have no effect

void disableUnusedIOPins() {

    PORTB.PIN0CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTB.PIN1CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTB.PIN2CTRL = PORT_ISC_INPUT_DISABLE_gc;

    PORTC.PIN0CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTC.PIN1CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTC.PIN4CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTC.PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;

}


inline void showNowD( uint24_t d ) {

    uint8_t i=0;

    while ( i < 6 ) {      // Don't show leading zeros. No need to wipe because digits only go up.

        // TODO: unroll this so we only uses as many bits as nessisary

        uint24_t next = d / 10;

        uint8_t ones = d-(next*10);

        digitShow( 6+i , ones );

        i++;

        d = next;

    }

}


inline void showNowHMS( uint24_t d ) {

    uint8_t i=0;

    while ( i < 6 ) {      // Don't show leading zeros. No need to wipe because digits only go up.

        // TODO: unroll this so we only uses as many bits as nessisary

        uint24_t next = d / 10;

        uint8_t ones = d-(next*10);

        digitShow( i , ones );

        i++;

        d = next;

    }

}



inline void showNowS10s( uint8_t t) {

    // TODO: We need to write some code to write some code here.
    // We need to figure out the minimum segment transition from second to second
    // and emit the code to implement those transitions directly.


    digitShow( 1 , t );

}


inline void showNowS1s( uint8_t o) {

    // TODO: We need to write some code to write some code here.
    // We need to figure out the minimum segment transition from second to second
    // and emit the code to implement those transitions directly.
    digitShow( 0 , o );

}


inline void showNowS( uint8_t s) {

    // TODO: We need to write some code to write some code here.
    // We need to figure out the minimum segment transition from second to second
    // and emit the code to implement those transitions directly.


    uint8_t t;

    t = s/10;
    digitShow( 0 , s  - (t*10) );
    digitShow( 1 , t );

}

inline void showNowM( uint8_t m) {

    uint8_t t;

    t = m/10;
    digitShow( 2 , m  - (t*10) );
    digitShow( 3 , t );

}

inline void showNowH(  uint8_t h ) {

    uint8_t t;

    t = h/10;
    digitShow( 4 , h  - (t*10) );

    digitShow( 5 , t );

    // We do not need to explicitly blank the tens digit since we
    // always clear it on day increment and it only monotonically increments.

}

void initTestPins() {

    // These appear on ISP pins 3 & 4 respectively

    PORTC.PIN2CTRL = PORT_OPC_PULLUP_gc ;
    PORTC.PIN3CTRL = PORT_OPC_PULLUP_gc ;
}


inline uint8_t testPin3Grounded() {

    return ( ! (PORTC.IN & _BV(2) ));

}

void triggerPinDisable() {

    PORTC_INT0MASK &= ~PIN7_bm;                            // Disable interrupt
    PORTC.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc;            // Disable pull-up on trigger pin, disable input buffer

}

// Enable the pin on the XMEGA that gets the FOUT signal from the RX8900 and generates an inetrrupt to wake us

void FOUT_in_pin_enable() {
    PORTB.PIN2CTRL = PORT_ISC_RISING_gc  ;        // Only interrupt once per second on the rising edge of the 1Hz FOE signal from the RTC

    PORTB.INTCTRL = PORT_INT0LVL0_bm;            // PORTB int0 is low level
    PORTB_INT0MASK |= PIN2_bm;                   // Enable pin 7 to be int0
}


// Output a 1 on the pin connected to FOE
// The idea here is that when Vcc power is dropped duirring a battery change,
// The FOE signal will drop quickly and turn off the FOUT and make the RX8900
// coast longer

void output1onFOEpin() {
    PORTB.DIRSET = _BV(7);
    PORTB.OUTSET = _BV(7);
}

EMPTY_INTERRUPT(PORTB_INT0_vect);       // FOUT ISR. We don't care about ISR, just want to have the interrupt to wake us up.
                                        // TODO: Can we save some cycles by messing with the interrupt controller? Maybe the pending interrupt priority pins?

// Enable an interrupt from the RX8900 RTC chip
// We program it to output a 1Hz square wave on the FOE pin
// which is connected to PORTB.7. We will only generate an interrupt
// on the rising edge, otherwise we'd get woken twice per sec.
// The ISR is empty - we just use the INT to wake from sleep.

void triggerPinEnable() {
    PORTC.PIN7CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc ;        // Enable pull-up on trigger pin
    _delay_ms(1);          // Give the pullup a moment to do its thing
    PORTC.INTCTRL = PORT_INT0LVL0_bm;
    PORTC_INT0MASK |= PIN7_bm;
}


void triggerPinInit() {
    triggerPinEnable();
}

inline uint8_t triggerPinPressed() {
    return(  PORTC.IN & _BV(7) );
}

EMPTY_INTERRUPT(PORTC_INT0_vect);       // Trigger pin ISR. We don't care about ISR, just want to have the interrupt to wake us up.


// Returns when we hit 999999 days = 2739.72329 years. 

void run( uint24_t d , uint8_t h, uint8_t m , uint8_t s ) {
    
    uint8_t st = s/10;          // seconds tens place
    uint8_t so = s - (st*10);   // seconds ones place

    while (d<1000000) {

        showNowD( d );

        while (h<24) {

            showNowH(h);

            while (m<60) {

                showNowM(m);

                while (st<6) {

                    showNowS10s( st );

                    while (so<10) {

                        showNowS1s( so );

                        sleep_cpu();
                        
                        so++;

                    }
                    so=0; 
                    st++;
                }       // s
                
                st=0; 
                m++;
            }           // m
            
            m=0; 
            h++;
        }               // h
        h=0;
        d++;        
    }                   // d    
    
}



void FlashFetInit0(void) {
    PORTD.DIR |= _BV(0);
    // No will be driving low, which keeps the flash lamp off
}


void FlashFetInit1(void) {
    PORTD.DIR |= _BV(1);
    // No will be driving low, which keeps the flash lamp off
}

void FlashFetOn0() {
    PORTD.OUTSET |= _BV(0);
}

void FlashFetOff0() {
    PORTD.OUTCLR |= _BV(0);
}


void FlashFetOn1() {
    PORTD.OUTSET |= _BV(1);
}

void FlashFetOff1() {
    PORTD.OUTCLR |= _BV(1);
}


// Wait for next LCD frame to start
// not needed if we are sleeping since the interrupt will
// wake us at the begining of the frame anyway


/* THIS DOES NOT SEEM TO WORK

void inline verticalRetrace() {
    //This bit is set by hardware at the beginning of a frame.
    while ( ! LCD.INTFLAG & LCD_FCIF_bm );

    //writing a logical one to the flag clears FCIF.
    LCD.INTFLAG  |= LCD_FCIF_bm;
}

*/


void toggleP57() {

   // Toggle test to check clock speed
   PORTB.PIN0CTRL = PORT_OPC_TOTEM_gc;
   PORTB.DIR |= PIN0_bm;
   while (1) {
       PORTB.OUTSET = PIN0_bm;
       PORTB.OUTCLR = PIN0_bm;
   }

}

void initFlash() {

    FlashFetInit0();
    FlashFetInit1();

}

void flash() {
    // Flash

    FlashFetOn0();
    _delay_ms(20);
    FlashFetOff0();

    FlashFetOn1();
    _delay_ms(20);
    FlashFetOff1();

    FlashFetOn0();
    _delay_ms(20);
    FlashFetOff0();

    FlashFetOn1();
    _delay_ms(20);
    FlashFetOff1();


    // and fade...

    for( uint8_t b=30; b>0; b-=10) {

        FlashFetOn0();
        for( uint8_t d=b; d; d-- ) _delay_us(1000);
        FlashFetOff0();
        for( uint8_t d=100-b; d; d-- ) _delay_us(1000);
        FlashFetOn1();
        for( uint8_t d=b; d; d-- ) _delay_us(1000);
        FlashFetOff1();
        for( uint8_t d=100-b; d; d-- ) _delay_us(1000);

    }

}

// Set FOUT on the RX8900 to 1Khz (default 32Khz)

#define RX8900_EXTENTION_REG 0x0d

void rx8900_fout_1KHz(void) {

    uint8_t reg = 0b00000100;
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_EXTENTION_REG , &reg , 1 );

}

// Set FOUT on the RX8900 to 1Hz (default 32Khz)

void rx8900_fout_1Hz(void) {

    uint8_t reg = 0b00001000;
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_EXTENTION_REG , &reg , 1 );

}


uint8_t bcd2c( uint8_t bcd ) {

    uint8_t tens = bcd/16;
    uint8_t ones = bcd - (tens*16);

    return (tens*10) + ones;
}

uint8_t c2bcd( uint8_t c ) {

    uint8_t tens = c/10;
    uint8_t ones = c - (tens*10);

    return (tens*16) + ones;

}



// Set time, not BCD

void rx8900_setTime(uint8_t h , uint8_t m, uint8_t s) {

    uint8_t reg[3];

    reg[0] = c2bcd( s );
    reg[1] = c2bcd( m );
    reg[2] = c2bcd( h );

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0 , reg , 3 );

}


// Date in numbers (not BCD)

void rx8900_setDate( uint8_t y , uint8_t m , uint8_t d ) {

    uint8_t reg[3];

    reg[0] = c2bcd( d );
    reg[1] = c2bcd( m );
    reg[2] = c2bcd( y );
    
    // YMD in address 4,5,6 respectively - as BCD

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 4 , reg , 3 );

}

// Returns time as long number hhmmss

uint24_t rx8900_getTime() {

   uint8_t reg[3];

   USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0 , reg , 3 );

   return ( bcd2c( reg[0] ) + ( bcd2c( reg[1] ) * 100 ) + ( bcd2c( reg[2] ) * 10000UL) );

}

uint24_t rx8900_getDate() {

    uint8_t reg[3];

    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 4 , reg , 3 );

    return ( bcd2c( reg[0] ) + ( bcd2c( reg[1] ) * 100 ) + ( bcd2c( reg[2] ) * 10000UL) );

}


#define RX8900_FLAG_LV_BM (1<<1)       // The chip saw a low voltage so might have lost time/data
#define RX8900_FLAG_NT_BM (1<<0)       // Volatge is too low for temp compensation

// Check voltage state of RTC chip

uint24_t rx8900_getFlags() {

    uint8_t reg[1];

    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , RX8900_FLAG_REG , reg , 1 );

    return reg[0];

}


void rx8900_clearFlags() {

    uint8_t reg=0x00;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_FLAG_REG , &reg , 1 );

}

const uint8_t magicregs[] = {
    'T' ,      // RAM
    's' ,      // MIN Alarm
    'L' ,      // HOUR Alarm
    '3' ,      // DAY Alarm
};

void rx8900_set_magic() {

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0x08 , magicregs , 4 );

}

uint8_t rx8900_check_magic() {

    uint8_t regs[4];

    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0x08 , regs, 4 );

    return regs[0]==magicregs[0] && regs[1]==magicregs[1] && regs[2]==magicregs[2] && regs[3]==magicregs[3];

}


// Open the MOS switch between Vdd and Vbat

void rx8900_open_MOS() {

    uint8_t reg= RX8900_BACKUP_SWOFF_bm;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_BACKUP_REG , &reg , 1 );

}


// Initialize all regs to sane values at startup
// TODO: Keep overflow in TEMP reg so we can run for centuries?

void rx8900_init_regs() {

    uint8_t timeregs[] = {
        0x00 ,      // SEC
        0x00 ,      // MIN
        0x00 ,      // HOUR
        0x00 ,      // WEEK
        0x00 ,      // DAY
        0x00 ,      // MONTH        
        0x00 ,      // YEAR
        0x00 ,      // TEMP (we will use for overflow count)
    };

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0x00 , timeregs , 6 );

    rx8900_clearFlags();

    // Note here we add the RESET flag. This will start the timer at the begining of the first second. 

    uint8_t contrlreg = 0b01000001;     // 2s temp comp, no timers or interrupts or alarms, reset
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_CONTROL_REG, &contrlreg, 1 );

    rx8900_open_MOS();      // Set backup reg

    rx8900_fout_1Hz();      // Enable FOUT at 1Hz (sets extension reg)

}

/*

void makeDaysSoFarTable(void) {
   
   int days_in_month[] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
   
   int days=0;
   
   for( int m=0; m<12; m++ ) {
       
       days+=days_in_month[m];
       
       printf( "%d,", days );
       
   }
   
   printf("\r");   
    
} 

*/   


// If month is jan (1), then no days other than the days in this month. 
// If month is mar (3), then there have been 59 days so far plus what every day of the month it is now.
// First 00000 is just becuase month starts at 1
// DOES NOT COUNT LEAP DAYS - these are computed seporately
// This table of days per month came from the RX8900 datasheet page 9

static const unsigned int daysSoFarByMonth[] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };   

// Convert the y/m/d values from the RX8900 to a count of the number of days since 00/1/1
// rx8900_date_to_days( 0 , 1, 1 ) = 0
// rx8900_date_to_days( 0 , 1, 31) = 30
// rx8900_date_to_days( 0 , 2, 1 ) = 31
// rx8900_date_to_days( 1 , 1, 1 ) = 366 (00 is a leap year!)

static inline uint24_t rx8900_date_to_days( uint8_t y , uint8_t m, uint8_t d ) {
    
    uint24_t dayCount=0;
           
    // Count days in years past (not counting leap years yet)
               
    dayCount += (uint24_t)y * 365;      // 365 days per year past in normal years


    if (y) {   // Don't even look if year is 0 
        
        dayCount += 1;              // Add the extra leap day for year 00, which is past since y>0
        
        dayCount += ((y-1)/4);     // Every 4th year is a leap year, so pick up an extra day for each. -1 because we don't want to count this year yet.
        
    }       
        
    if ( (y%4) == 0) {  // Is this a leap year?
            
        if (m>2) {      // Past feb 29th this year?
                
            dayCount++;        // Count the extra leap day
                
        }
            
    }
            
    dayCount += daysSoFarByMonth[ m ];          // Days until the 1st day of this month
    
    dayCount += (d-1);                          // On the 1st of the month, there are no days yet so -1
        
    return dayCount;                                     
    
}    


void digitPatternUntilPressed() {
    // Show a marching countdown pattern until button pressed...
    // TOOD: we will load UTC time during this step

    uint8_t n=9;
    uint8_t d=11;


    do {

        clearLCD();
        digitShow( d , n );

        sleep_cpu();        // We will wake on next second, or when switch changes state

        if (n==0) {
            n=9;
            } else {
            n--;
        }

        if (d==0) {
            d=11;
            } else {
            d--;
        }

    } while ( !triggerPinPressed() );     // Repeat until pin pressed
}



void figure8PatternUntilReleased() {
    // Show figure 8 pattern until pin pulled

    // TODO: unroll this for efficiency

    uint8_t s=0;

    do {
        clearLCD();
        for( uint8_t d=0;d<12;d+=2) {
            figure8On( d , s );
            figure8On( d+1 , (s+6)%8 );
        }

        sleep_cpu();

        s++;

        if (s==8) {
            s=0;
        }

    } while ( triggerPinPressed() );     // Repeat until pin pressed

}



// Read out the current time from the RX8900 registers and save it to XMEGA EEPROM

void saveCurrentTimeFromRX8900ToEEPROM() {
    // TODO: This
    
}    

// Check if RX8900 considers 00 as a leap year

void leaptester() {
    
    
    rx8900_init_regs();
    
    rx8900_setDate( 0  , 2 , 28 );
    
    rx8900_setTime( 23 , 59 , 50 );
    
    
    while (1) {
        
        showNowD( rx8900_getDate() );
        showNowHMS( rx8900_getTime() );
        
        sleep_cpu();
        
        
    }        
    
    
}    


void contrastTest() {
    
    // Contrast test pattern
    clearLCD();
    showNowD( 123456 );
    showNowH( 99 );
    showNowM( 88 );
    showNowS (77 );
    char contrast =0;
    while (1) {
          contrast+=32;

        lcd_set_contrast( contrast );
        showNowD( 127+ contrast );

        sleep_cpu();


    }

}
 
// Just a standardized run to measure power usage that should be close to real usage in run mode. 

void powerTest() {

    // LOW POWER TEST CODE
    // Meant to simulate a normal count

    PIN4_INIT();

    triggerPinDisable();

    while (1) {
        PIN4_UP();
        displaydigit02F();
        displaydigit01O();
        PIN4_DOWN();
        sleep_cpu();
        //_delay_ms(1000);
        displaydigit01F();
        displaydigit02O();
        sleep_cpu();
    }    
    
}    

/////////////////////////////////////////////////////////////////////
// The main function follows a work flow that has been standardized
// within the ASF for Xmega devices. This means that when searching
// through Xmega example projects in ASF, you will find a main
// function with the same general flow:
//
// sysclk_init();
// pmic_init();
// board_init();
// -- peripheral initialization --
// while(1) {
//     -- application code --
// }
//
/////////////////////////////////////////////////////////////////////
int main(void)
{


    // Enable the ultra low power RTC clock
    // We will drive the LCD from this
    //enable_rtc_ulp();

    enable_rtc_ulp();

    //enable_rtc_32Kxtal();     // Saves 0.3uA over ULP. Worth the savings for the extra part?

    //switchSysclk2Xtal();      // Massively not worth it!

    // enable_rtc_TOSC1_32K();  // Also massively not worth it!

    disableUnusedIOPins();      // Save a little power

    USI_TWI_Master_Initialise();        // Init TWO pins to pullup. Keep them from floating to save power.

    initTestPins();             // Set pullups on the 2 extra pins on the ISP just to keep them from floating. We can also uses these for diagnostics and programming.

    // Disable unused peripherals to save power
    prr_init();
    disableJTAG();

	// Initialize the LCD Controller
	lcd_init();

	// Enable LOW priority interrupts (we only use low)
    CPU_CCP = CCP_IOREG_gc;             // TODO: I think this is not needed?
    PMIC.CTRL |= PMIC_LOLVLEN_bm;
	sei();

	set_sleep_mode( SLEEP_SMODE_PSAVE_gc );     // Lowest power sleep with LCD

	sleep_enable();

    initFlash();


    triggerPinInit();       // Enable pullup and interrupts on trigger pin

    FOUT_in_pin_enable();

    output1onFOEpin();

/*

    // Drop clock to 1mhz for fcc part 15 exemption
    // This increases power ~0.2uA
    CCP = CCP_IOREG_gc; //Trigger protection mechanism
    CLK.PSCTRL = CLK_PSADIV0_bm;             // Switch system clock /2

*/

    while (0) {
        // Output pattern on pin 4 to check sys clock freq
        PIN4_INIT();
        while (1) {
            PIN4_UP();
            PIN4_DOWN();
        };
    }


    //powerTest();
    

    // First check if this is our first time waking up ever...

    uint8_t flagreg = rx8900_getFlags();
    
    // Default to zero start count. We will update these from the RX8900 if this is a warm start. 
    uint24_t d=0;
    uint8_t h=0;
    uint8_t m=0;
    uint8_t s=0;
    
    // For now, you can hold the trigger pin down while inserting the battery to simulate a fresh power-up

    if ( triggerPinPressed() || flagreg & RX8900_FLAG_LV_BM) {

        // We are new to the world (or our batteries were out too long)

        // For now we will just go into wait-for-trigger mode
        // TODO: If we are just manufactured, then set local clock to UTC. Otherwise display a sad message telling people to return unit.

        // For now, set time to 00:00:00 on power up

        rx8900_init_regs();

        // Show "ready to load" counting pattern until trigger pin is pushed in

        // Show a marching countdown pattern until pin pressed...
        // TOOD: we will load UTC time during this step

        digitPatternUntilPressed();

        clearLCD();

        _delay_ms(100);     // Debounce switch

        // PRESSED - ARMED AND READY!

        figure8PatternUntilReleased();
        
        // Ok! We are live now, people!
        
        // Save this moment so we do not forget it ever.
        
        saveCurrentTimeFromRX8900ToEEPROM();
                
        clearLCD();

        flash();

    } else {
        
        // TODO: Show something on warm start?
        
        // Read current time from RX8900. Since we started at 00:00:00 1/1/00, we can figure out what our current count is
        // at least for the first 100 years....
        
        uint8_t reg[8];

        USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0 , reg , 8 );      // Read ssmmhhwwddmmyycc from RX8900 (BCD values!)
        
        s = bcd2c( reg[0] );
        m = bcd2c( reg[1] );
        h = bcd2c( reg[2] );
        // Skip weeks
        uint8_t day  = bcd2c( reg[4] );
        uint8_t mon  = bcd2c( reg[5] );
        uint8_t year = bcd2c( reg[6] );
        
        d = rx8900_date_to_days( year , mon , day );        
        
        // TODO: Add centry count here (and update century count in year increment)

    }


    triggerPinDisable();           // So we do not waste current running though pull up and the switch forevermore....

    run( d , h , m , s );

}


// Subroutine for handling LCD Frame Interrupts
// This is a user configurable interrupt based
// on the frame rate of the LCD. It can be used
// as a miscellaneous timer by the user since it
// occurs at a constant rate.

// We leave it empty and just do all our processing when it returns.
// It would be nice to avoid this alltoether, but I do not think it is possible on AVR.

EMPTY_INTERRUPT(LCD_INT_vect);


