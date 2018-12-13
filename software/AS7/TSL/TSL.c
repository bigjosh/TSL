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
#include <avr/eeprom.h>

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


// Diagnostic use of the extra middle pins on the ISP
//
//   VCC  |   [TOP]  |    GND
//   DTA  |   [BOT]  |    CLK

#define PINTOP_OUT()      (PORTC.DIRSET = _BV( 3 ))
#define PINTOP_UP()       (PORTC.OUTSET = _BV( 3 ))
#define PINTOP_DOWN()     (PORTC.OUTCLR = _BV( 3 ))

#define PINTOP_IN()       (PORTC.PIN3CTRL = PORT_OPC_PULLUP_gc)  // As pull-up
#define PINTOP_TEST()     (!(PORTC.IN & _BV( 3 )))              // Grounded?


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
    // PORTB.2 is connected to FOUT from the RX8900. It is input with pn change interrupt.
    PORTB.PIN3CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTB.PIN4CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTB.PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTB.PIN6CTRL = PORT_ISC_INPUT_DISABLE_gc;
    // PORTB.2 is connected to FOE to the RX8900. It is driven high. .


    // PORTC.0 is connected to SDA on RX8900. It has pullup.
    // PORTC.1 is connected to SCL on RX8900. It has pullup.
    // PORTC.2 is connected to PIN3 on ISP. It has pullup.
    // PORTC.3 is connected to PIN4 on ISP. It has pullup.
    PORTC.PIN4CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTC.PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTC.PIN6CTRL = PORT_ISC_INPUT_DISABLE_gc;
    // PORTC.7 is connected to the trigger switch. It has pullup until pin is pulled, then input disabled.

    // PORTD.0 is connected to flash EFT. It has driven LOW.
    // PORTD.1 is connected to flash EFT. It has driven LOW.


    // PORTG and PORTM are alternate functions on the LCD pins
    // Do we need to disable them when LCD function is in use?
    // I really could not find out from the datasheet so better safe than
    // sorry since these pins have intermediate voltages on them all the time
    // from the LCD phases

    PORTG.PIN0CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTG.PIN1CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTG.PIN2CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTG.PIN3CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTG.PIN4CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTG.PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTG.PIN6CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTG.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc;

    PORTM.PIN0CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTM.PIN1CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTM.PIN2CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTM.PIN3CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTM.PIN4CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTM.PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;
    PORTM.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc;

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

// Show a 6 digit number on the right LCD

inline void showNowRight( uint24_t d ) {

    uint8_t i=0;

    while ( i < 6 ) {      // Don't show leading zeros. No need to wipe because digits only go up.

        // TODO: unroll this so we only uses as many bits as necessary

        uint24_t next = d / 10;

        uint8_t ones = d-(next*10);

        digitShow( i , ones );

        i++;

        d = next;

    }

}


inline void showNowMDY( uint8_t o , uint8_t d , uint8_t y ) {

    digitShow( 6 , y % 10);
    digitShow( 7 , y / 10 );

    digitShow( 8 , d % 10);
    digitShow( 9 , d / 10 );


    digitShow(10 , o % 10);
    digitShow(11 , o / 10 );


}


inline void showNowHMS( uint8_t h , uint8_t m , uint8_t s ) {

    digitShow( 0 , s % 10);
    digitShow( 1 , s / 10 );

    digitShow( 2 , m % 10);
    digitShow( 3 , m / 10 );


    digitShow( 4 , h % 10);
    digitShow( 5 , h / 10 );


}



inline void showNowHMSx( uint24_t d ) {

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

// Test pins are label T & B on the ISP6 connector
// They are pulled up internally

void initTestPins() {

    // These appear on ISP pins 3 & 4 respectively

    PORTC.PIN2CTRL = PORT_OPC_PULLUP_gc ;
    PORTC.PIN3CTRL = PORT_OPC_PULLUP_gc ;
}


inline uint8_t testPinBGrounded() {

    return ( ! (PORTC.IN & _BV(2) ));

}


inline uint8_t testPinTGrounded() {

    return ( ! (PORTC.IN & _BV(3) ));

}

// Enable the pin on the XMEGA that gets the FOUT signal from the RX8900 and generates an interrupt to wake us once per second

void FOUT_in_pin_enable() {
    PORTB.PIN2CTRL = PORT_ISC_RISING_gc  ;        // Only interrupt once per second on the rising edge of the 1Hz FOE signal from the RTC

    PORTB.INTCTRL = PORT_INT0LVL0_bm;            // PORTB int0 is low level interrupt
    PORTB_INT0MASK |= PIN2_bm;                   // Enable pin 7 to be int0
}


// Output a 1 on the pin connected to FOE
// The idea here is that when Vcc power is dropped during a battery change,
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


// We enable an interrupt on the trigger pin so that the user gets immediate feedback rather than having to
// wait for the 1-second interrupt to wake us up and check it.

void triggerPinEnable() {
    PORTC.PIN7CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc ;        // Enable pull-up on trigger pin
    _delay_ms(1);          // Give the pullup a moment to do its thing
    PORTC.INTCTRL = PORT_INT0LVL0_bm;
    PORTC_INT0MASK |= PIN7_bm;
}

// Turn off interrupt, disable input buffer

void triggerPinDisable() {

    PORTC_INT0MASK &= ~PIN7_bm;                            // Disable interrupt
    PORTC.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc;            // Disable pull-up on trigger pin, disable input buffer

}

inline uint8_t triggerPinPresent() {
    return(  PORTC.IN & _BV(7)  );   // Switch grounds pin when closed. The pin presses open the switch.
}

EMPTY_INTERRUPT(PORTC_INT0_vect);       // Trigger pin ISR. We don't care about ISR, just want to have the interrupt to wake us up.




// Pattern to show when we run out of digits in 2300 years...

void showGoodbye() {

    while (1) {

        showNowD( 999999 );
        showNowRight( 0 );
        sleep_cpu();
        showNowD( 0 );
        showNowRight( 999999 );
        sleep_cpu();
    }

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

//Note that flash should take significantly less than 1 sec so we don't miss a tick

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
        for( uint8_t d=b; d; d-- ) _delay_us(500);
        FlashFetOff0();
        for( uint8_t d=100-b; d; d-- ) _delay_us(500);
        FlashFetOn1();
        for( uint8_t d=b; d; d-- ) _delay_us(500);
        FlashFetOff1();
        for( uint8_t d=100-b; d; d-- ) _delay_us(500);

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


// Grabs the current time from the RX8900 and shows it on the LCD
// NOT POWER EFFICIENT - ONLY FOR TESTING

void show_time_for_testing() {

    uint8_t reg[8];

    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0 , reg , 8 );      // Read ssmmhhwwddmmyycc from RX8900 (BCD values!)

    uint8_t s = bcd2c( reg[0] );
    showNowS10s( s / 10 );
    showNowS1s( s % 10 );


    uint8_t m = bcd2c( reg[1] );
    showNowM( m );


    uint8_t h = bcd2c( reg[2] );
    showNowH( h );

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


#define RX8900_FLAG_VLF_BM  (1<<1)       // The chip saw a low voltage so might have lost time/data (1.8V)
#define RX8900_FLAG_VDET_BM (1<<0)       // Voltage is too low for temp compensation (2.4V)

const uint8_t magicregs[] = {
    'T' ,      // MIN Alarm
    's' ,      // HOUR Alarm
    'L' ,      // DAY Alarm
    '3' ,      // Week Alarm
};

/*

    We use the alarm regs to store a magic value that we can check to see if registers are still good.

    "If an alarm function is not used, registers 08h-0Ah can be used as RAM. ( AIE : "0" )"

*/


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

    // Turn off the switch and disable the voltage detection system
    // The datasheet strongly suggests that the switch can not be opened unless
    // the voltage detect is disabled, which is a shame because we'd like to
    // have the chip go into backup made when the voltage drops below 2.4V

    uint8_t reg= RX8900_BACKUP_SWOFF_bm & RX8900_BACKUP_VDETOFF_bm;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_BACKUP_REG , &reg , 1 );

}


// Close the MOS switch between Vdd and Vbat. Leaves voltage detector off

void rx8900_close_MOS() {

    // Turn on the switch and disable the voltage detection system

    uint8_t reg= RX8900_BACKUP_VDETOFF_bm;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_BACKUP_REG , &reg , 1 );

}


// Returns 1 if the RX8900 has seen a low voltage - which means its data is not trustworthy
// and it needs a RESET.

uint8_t rx8900_check_low_voltage() {

    uint8_t save_flags_reg;

    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , RX8900_FLAG_REG , &save_flags_reg , 1 );

    return (save_flags_reg & RX8900_FLAG_VLF_BM);

}


// Returns 1 if the RX8900 has seen a voltage below 2.4V - which means
// that it is no longer doing temperature corrections

uint8_t rx8900_check__voltage_24() {

    uint8_t save_flags_reg;

    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , RX8900_FLAG_REG , &save_flags_reg , 1 );

    return (save_flags_reg & RX8900_FLAG_VLF_BM);

}


// Clears the VLF (voltage to low for operation) and VDET (voltage was too low for temp compensation) flags

void rx8900_clear_voltage_flags() {

    uint8_t zero=0;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_FLAG_REG , &zero , 1 );


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


// This table of days per month came from the RX8900 datasheet page 9

static uint8_t daysInMonth( uint8_t m , uint8_t y) {

    switch ( m ) {

        case  1:
        case  3:
        case  5:
        case  7:
        case  8:
        case 10:
        case 12:    // Interestingly, we will never hit 12. See why?
                    return 31 ;

        case  4:
        case  6:
        case  9:
        case 11:
                    return 30 ;

        case  2:

                    if ( y % 4 == 0 ) {         // "A leap year is set whenever the year value is a multiple of four (such as 04, 08, 12, 88, 92, or 96)."
                                                // Empirical testing also shows that 00 is a leap year to the RX8900
                                                // https://electronics.stackexchange.com/questions/385952/does-the-epson-rx8900-real-time-clock-count-the-year-00-as-a-leap-year

                        return 29 ;             // "February in leap year 01, 02, 03 ... 28, 29, 01

                    } else {

                        return 28;              // February in normal year 01, 02, 03 ... 28, 01, 02
                    }

    }

    __builtin_unreachable();

}

static const uint32_t rx8900_days_per_century = ( 100UL * 365 ) + 25;       // 25 leap years in every RX8900 century

// Convert the y/m/d values from the RX8900 to a count of the number of days since 00/1/1
// rx8900_date_to_days( 0 , 1, 1 ) = 0
// rx8900_date_to_days( 0 , 1, 31) = 30
// rx8900_date_to_days( 0 , 2, 1 ) = 31
// rx8900_date_to_days( 1 , 1, 1 ) = 366 (00 is a leap year!)

static uint32_t rx8900_date_to_days( uint8_t c , uint8_t y , uint8_t m, uint8_t d ) {

    uint32_t dayCount=0;

    // Count days in centuries past

    dayCount += rx8900_days_per_century * c;

    // Count days in years past this century

    for( uint8_t y_scan = 0; y_scan < y ; y_scan++ ) {

        if ( y_scan % 4 == 0 ) {
            // leap year every 4 years on RX8900
            dayCount += 366UL;      // 366 days per year past in leap years

        } else {

            dayCount += 365UL;      // 365 days per year past in normal years
        }

    }


    // Now accumulate the days in months past so far this year

    for( uint8_t m_scan = 1; m_scan < m ; m_scan++ ) {      // Don't count current month

        dayCount += daysInMonth( m_scan , y );       // Year is needed to count leap day in feb in leap years.


    }

    // Now include the passed days so far this month

    dayCount += (uint32_t) d-1;     // 1st day of a month is 1, so if it is the 1st of the month then no days has elapsed this month yet.

    return dayCount;

}

// Used for reading and writing registers 0-7 to the RX8900.
// These are the registers that hold the time, plus the RAM reg that we can use to put stuff in

typedef  struct  {

    uint8_t time_regs[8];

} rx8900_time_regs_block_t;

// Set to Midnight Jan 1 00

static void rx8900_time_regs_reset( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    rx8900_time_regs_block->time_regs[0] = c2bcd(  0 ),      // SEC
    rx8900_time_regs_block->time_regs[1] = c2bcd(  0 ),      // MIN
    rx8900_time_regs_block->time_regs[2] = c2bcd(  0 ),      // HOUR
    rx8900_time_regs_block->time_regs[3] = c2bcd(  1 ),      // WEEK
    rx8900_time_regs_block->time_regs[4] = c2bcd(  1 ) ,     // DAY
    rx8900_time_regs_block->time_regs[5] = c2bcd(  1 ),      // MONTH
    rx8900_time_regs_block->time_regs[6] = c2bcd(  0 ),      // YEAR
    rx8900_time_regs_block->time_regs[7] = c2bcd(  0 ),      // RAM (we use for century interlock)

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0x00 , rx8900_time_regs_block->time_regs , 8 );

}



/*

Century interlock explained:

The RX8900 only saves 2 digits for the year, so when we roll from 2099 to 2100, the year will go from 99 to 0.
This would make us loose 100 years worth of days on the first battery change of the new century when we go to
compute how long since the pin was pulled.

To buy ourselves extra centuries, we use a century interlock stored in the RAM register of the RX8900.
When we first program a unit (presumably in the 21st century), we set the interlock to '00' BCD (0x3030).

On every power up (typically due to battery change) every 10 - 30 years(? We'll see!), we check the current year. If it is greater than 50
and the century interlock is even, then we increment the century interlock. If it is less than 50  and the century
interlock is odd, then we increment the century interlock. This also has the effect of re-writing the EEPROM every few decades, which may
or may not extend the retention. https://electronics.stackexchange.com/questions/411616/for-maximum-eeprom-readability-into-the-future-is-it-better-to-write-once-and-le

When we want to compute the total days elapsed since epoch Jan 1, 2000 then we just divide the century interlock by
2 and drop the remainder. We when multiply this by the number of days in an RX8900 century and we will get the correct value.

This will get us an additional 127 centuries of run time, which puts us at the year 14700. We will need to patch the firmware before
then if we want to continue to keep accurate count.

*/




// Save to chip

static void rx8900_time_regs_set( const rx8900_time_regs_block_t *rx8900_time_regs_block ) {
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0x00 , rx8900_time_regs_block->time_regs, 8 );
}


// Load from chip

static void rx8900_time_regs_get( rx8900_time_regs_block_t *rx8900_time_regs_block ) {
    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0x00 , rx8900_time_regs_block->time_regs, 8 );
}



// Load from chip, update century interlock if necessary

static void rx8900_time_regs_get_and_update_century_interlock( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

        rx8900_time_regs_get( rx8900_time_regs_block );

    uint8_t y = bcd2c( rx8900_time_regs_block->time_regs[6] );
    uint8_t i = bcd2c( rx8900_time_regs_block->time_regs[7] );     // Century interlock flag

    if (
        (y >=50 && !( i & 0x01 )) // If the year is 50-99 and the interlock is currently even...
        ||                        // ...or...
        ( y<50  &&  ( i & 0x01 )) // If the year is 00-49 and the interlock is currently odd...
    ) {
        // Increment the century interlock and write back to eeprom
        i++;
        rx8900_time_regs_block->time_regs[7] = c2bcd( i );
        rx8900_time_regs_set( rx8900_time_regs_block );         // Here we rewrite the whole block. Maybe this will extend retention because we are refreshing the cells?
    }

}


/*

    Layout of EEPROM:

*/

#define TIMEBLOCK_SIZE 8

#define EEPROM_ADDRESS(x) (( void *) x )

#define EEPROM_ADDRESS_STARTIME     EEPROM_ADDRESS( 0)  // Set by the at the Factory to real time GMT when initially programmed. RX8900 register block layout. Values are BCD.
#define EEPROM_ADDRESS_STARTFLAG    EEPROM_ADDRESS( 8)  // Set 0x00 to indicate that STARTTIME block has time in it, set to 0x01 when STARTTIME set to the RTC the first time we power up

#define EEPROM_ADDRESS_TRIGGERTIME  EEPROM_ADDRESS(10)  // Set to RTC time when the trigger pin is pulled. RX8900 register block layout. Values are BCD.
#define EEPROM_ADDRESS_TRIGGERFLAG  EEPROM_ADDRESS(18)  // Set to 0x01 when the trigger pin is pulled and the RTC time is aves to the TRIGGER_TIME block

#define EEPROM_ADDRESS_LOWVOLTFLAG  EEPROM_ADDRESS(20)  // Set to 0x01 if we ever power up and find a low voltage condition.


static void load_time_regs_from_EEPROM( void *eeprom_start_address , rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    eeprom_read_block( rx8900_time_regs_block->time_regs , eeprom_start_address,  TIMEBLOCK_SIZE );

}

static void save_time_regs_to_EEPROM( void *eeprom_start_address , const rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    eeprom_write_block( rx8900_time_regs_block->time_regs , eeprom_start_address,  TIMEBLOCK_SIZE );

}


static void load_starttime_from_EEPROM( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    load_time_regs_from_EEPROM( EEPROM_ADDRESS_STARTIME , rx8900_time_regs_block );

}

static void save_starttime_to_EEPROM( const rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    save_time_regs_to_EEPROM( EEPROM_ADDRESS_STARTIME , rx8900_time_regs_block );

}


static void load_triggertime_from_EEPROM( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    load_time_regs_from_EEPROM( EEPROM_ADDRESS_TRIGGERTIME , rx8900_time_regs_block );

}

static void save_triggertime_to_EEPROM( const rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    save_time_regs_to_EEPROM( EEPROM_ADDRESS_TRIGGERTIME , rx8900_time_regs_block );

}





static void save_start_flag_to_EEPROM() {
    eeprom_write_byte( EEPROM_ADDRESS_STARTFLAG , 0x01 );
}

static uint8_t load_start_flag_from_EEPROM() {
    return eeprom_read_byte( EEPROM_ADDRESS_STARTFLAG );
}

static void save_trigger_flag_to_EEPROM() {
    eeprom_write_byte( EEPROM_ADDRESS_TRIGGERFLAG , 0x01 );
}

static uint8_t load_trigger_flag_from_EEPROM() {
    return eeprom_read_byte( EEPROM_ADDRESS_TRIGGERFLAG  );
}

static void save_low_voltage_flag_to_EEPROM() {
    eeprom_write_byte( EEPROM_ADDRESS_LOWVOLTFLAG , 0x01 );
}

static uint8_t load_low_voltage_flag_from_EEPROM() {
    return eeprom_read_byte( EEPROM_ADDRESS_LOWVOLTFLAG );
}



// Convert to days since Midnight Jan 1, 2000
// including the century interlock

// Relies on both the data sheet's description of days per month and also
// empirical testing of leap years on century turns.
// https://electronics.stackexchange.com/questions/385952/does-the-epson-rx8900-real-time-clock-count-the-year-00-as-a-leap-year

static uint32_t rx8900_time_regs_days_since_epoch( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    uint8_t d = bcd2c( rx8900_time_regs_block->time_regs[4] );     // DD
    uint8_t o = bcd2c( rx8900_time_regs_block->time_regs[5] );     // MM
    uint8_t y = bcd2c( rx8900_time_regs_block->time_regs[6] );     // YY
    uint8_t i = bcd2c( rx8900_time_regs_block->time_regs[7] );     // Century interlock flag

    uint8_t c = i / 2;              // Interlock clicks twice per century.

    return rx8900_date_to_days( c , y , o , d );

}


// Convert to days since Midnight Jan 1, 2000
// including the century interlock

static uint32_t rx8900_time_regs_secs_since_midnight( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    uint8_t s = bcd2c( rx8900_time_regs_block->time_regs[0] );
    uint8_t m = bcd2c( rx8900_time_regs_block->time_regs[1] );
    uint8_t h = bcd2c( rx8900_time_regs_block->time_regs[2] );

    return s + ( m * 60 ) + ( h * 3600 );               // Easy peasy

}


typedef struct {

    uint8_t s;
    uint8_t m;
    uint8_t h;

    uint32_t d;

} time_count_t;


// Returns 1 if all regs are in bounds,
// 0 if an error

uint8_t rx8900_time_regs_valid( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    uint8_t y = bcd2c( rx8900_time_regs_block->time_regs[6] );     // YY

    if ( y > 99 ) return 0;

    uint8_t o = bcd2c( rx8900_time_regs_block->time_regs[5] );     // MM

    if ( o <1 || o > 12 ) return 0;

    uint8_t d = bcd2c( rx8900_time_regs_block->time_regs[4] );     // DD

    if ( d < 1 || d > daysInMonth( o , y ) ) return 0;

    uint8_t i = bcd2c( rx8900_time_regs_block->time_regs[7] );     // Century interlock flag

    // This can't really be invalid, just just sanity check to make sure we are in the right millenniums

    if ( i > 20 ) return 0;


    uint8_t s = bcd2c( rx8900_time_regs_block->time_regs[0] );

    if (s>59) return 0;

    uint8_t m = bcd2c( rx8900_time_regs_block->time_regs[1] );

    if (m>59) return 0;

    uint8_t h = bcd2c( rx8900_time_regs_block->time_regs[2] );

    if (h>23) return 0;

    return 1;

}


void rx8900_time_regs_to_count( time_count_t *count , rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    count->s = bcd2c( rx8900_time_regs_block->time_regs[0] );
    count->m = bcd2c( rx8900_time_regs_block->time_regs[1] );
    count->h = bcd2c( rx8900_time_regs_block->time_regs[2] );

    count->d = rx8900_time_regs_days_since_epoch( rx8900_time_regs_block );
}

// difference = minuend - subtrahend
// returns 1 if subtrahend  >  minuend (error)

// Note that max value for any of these elements is 60, so borrowing can not overflow a uint8_t (255)

static uint8_t time_count_subtract( time_count_t *difference , time_count_t *minuend ,  time_count_t *subtrahend ) {

    uint8_t borrowed_minutes =0;

    if ( subtrahend->s > minuend->s ) {

        minuend->s += 60;

        borrowed_minutes =1;

    }

    difference->s = minuend->s - subtrahend->s;

    uint8_t borrowed_hours =0;

    if ( (subtrahend->m + borrowed_minutes) > minuend->m ) {

        minuend->m += 60;

        borrowed_hours = 1;

    }

    difference->m = minuend->m - ( subtrahend->m + borrowed_minutes );

    uint8_t borrowed_days =0;

    if ( (subtrahend->h + borrowed_hours ) > minuend->h ) {

        minuend->h += 24;

        borrowed_days = 1;

    }

    difference->h = minuend->h - ( subtrahend->h + borrowed_hours );

    if ( (subtrahend->d + borrowed_days) > minuend->d ) {

        // Error! subtrahend was bigger than minuend!

        return 1;

    }

    difference->d =  minuend->d - ( subtrahend->d + borrowed_days );

    return 0;

}

// Reset RX8900 and initialize all regs to sane values at startup
// TODO: also clears the VLF flag which is set by reset
// TODO: Keep overflow in TEMP reg so we can run for centuries?

void rx8900_init() {

    // Note here we add the RESET flag. This will start the timer at the beginning of the first second.

    uint8_t contrlreg = 0b01000001;     // 2s temp comp, no timers or interrupts or alarms, reset

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_CONTROL_REG, &contrlreg, 1 );

    // Set registers to sensical initial values

    /*

    rx8900_time_regs_block_t rx8900_time_regs_block;

    rx8900_time_regs_reset( &rx8900_time_regs_block );

    */

    // Enable FOUT at 1Hz (sets extension reg)

    rx8900_fout_1Hz();

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

    } while ( !triggerPinPresent() );     // Repeat until pin pressed
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

    } while ( triggerPinPresent() );     // Repeat until pin pressed

}

// Check if RX8900 considers 00 as a leap year

void leaptester() {

    rx8900_init();

    rx8900_setDate( 0  , 2 , 28 );

    rx8900_setTime( 23 , 59 , 50 );


    while (1) {

        showNowD( rx8900_getDate() );
        showNowHMSx( rx8900_getTime() );

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

// Look like a normal clock
// Read current time from RTC and show on the display
// INdicates clock time with blinking decimal point on left module and colon on right module

static void showClockTime( rx8900_time_regs_block_t *time_now ) {

    uint8_t s = bcd2c( time_now->time_regs[0] );
    uint8_t m = bcd2c( time_now->time_regs[1] );
    uint8_t h = bcd2c( time_now->time_regs[2] );
    // Skip weeks
    uint8_t d  = bcd2c( time_now->time_regs[4] );
    uint8_t o  = bcd2c( time_now->time_regs[5] );
    uint8_t y  = bcd2c( time_now->time_regs[6] );
    // TODO: Hmmm... We should really show the century interlock somehow...

    showNowMDY( o , d , y );
    showNowHMS( h , m , s );

}

// Blink the battery indicators on and off at 0.5Hz

void batterydescending() {

    battSegOn(0);       // Outline always on

    while (1) {

        battSegOn(3);
        battSegOn(2);
        battSegOn(1);
        sleep_cpu();


        battSegOff(1);
        sleep_cpu();

        battSegOff(2);
        sleep_cpu();

        battSegOff(3);
        sleep_cpu();



    };
}

void batteryemptyblink() {

    battSegOn(0);       // Outline always on

    while (1) {

        battSegOn(3);
        sleep_cpu();


        battSegOff(3);
        sleep_cpu();



    };
}

void blink_lcd_forever() {
    while (1) {

        lcd_blank();
        sleep_cpu();
        lcd_unblank();
        sleep_cpu();

    }

    __builtin_unreachable();
}


// We powered up to find that we have been triggered previously, but the RTC does not know what time it is
// This is because either the battery went so dead that the RTC stopped, or the batteries we removed too long
// and the RTC backup capacitor went dead.

void where_has_the_time_gone_mode( rx8900_time_regs_block_t *trigger_time ) {

    // "Where Has the Time Gone mode"

    showClockTime( trigger_time );

    // Show the trigger time blinking forever.
    // To fix this, they will need to reprogram the current time into this unit

    blink_lcd_forever();

    __builtin_unreachable();

}

// We powered up to find that we have never been triggered, and the RTC does not know what time it is
// This is because either the battery went completely flat or was left out too long on this unit that
// had never been fired. We choose to not let the person fire without knowing what time it is now because
// then there would be no way to get the count back if they ever had a flat or missing battery event again
// after they pulled the trigger.

void clockErrorMode() {

    // Show "cLoc Error"
    showClocError();

    blink_lcd_forever();

    __builtin_unreachable();

}

// Something in EEPROM is screwy. Maybe corruption? We need to see the unit.

void eepromErrorMode( uint8_t code ) {

    // Show "EEPro error"
    showEEProError( code );

    blink_lcd_forever();

    __builtin_unreachable();

}

// Blink "999999 999999" forevermore

void longNowMode() {

    showNowMDY( 99 , 99 , 99);
    showNowHMS( 99 , 99 , 99);

    blink_lcd_forever();

    __builtin_unreachable();

}

// Show "------ ------"

void showDashes() {

    for(uint8_t d=0; d<12 ; d++ ) {

        showDash(d);

    }

}


// Returns when we hit 999999 days = 2739.72329 years.

void run( uint24_t d , uint8_t h, uint8_t m , uint8_t s ) {

    // Enable pull-up on test pin for diagnostic time speed up for testing
    // TODO: remove this diagnostic code
    PINTOP_IN();

    uint8_t st = s/10;          // seconds tens place
    uint8_t so = s - (st*10);   // seconds ones place

    while (d<1000000 ) {

        // TODO: Check battery voltage here

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

        if ( (d & 0x7f) == 0x00 ) {     // Every 128 days....

            clearLCD();
            showc2018JOSH();            // Show copyright egg

            sleep_cpu();                // Show for 1 second
            clearLCD();

            so++;                       // Account for this second

        }

    }                   // d

}


int main(void)
{

    // Enable the ultra low power RTC clock
    // We will drive the LCD from this

    enable_rtc_ulp();

    //enable_rtc_32Kxtal();     // There is provision to install this on the PCB. Saves 0.3uA over ULP. Worth the savings for the extra part?

    disableUnusedIOPins();      // Save a little power by disabling the input buffers on all unused pins

    triggerPinDisable();        // Disable the input buffer on the trigger pin until we actually need it.

    USI_TWI_Master_Initialise();        // Init TWI pins to pullup.

    initTestPins();             // Set pullups on the 2 extra pins on the ISP just to keep them from floating. We can also uses these for diagnostics and programming.

    // Disable unused peripherals to save power
    prr_init();
    disableJTAG();

	// Initialize the LCD Controller
	lcd_init();

	// Enable LOW priority interrupts (we only use low)
    CPU_CCP = CCP_IOREG_gc;             // TODO: I think this is not needed?
    PMIC.CTRL |= PMIC_LOLVLEN_bm;

	set_sleep_mode( SLEEP_SMODE_PSAVE_gc );     // Lowest power sleep with LCD

	sleep_enable();         // This chip needs you to tell it that it is ok to sleep before the sleep instruction will actually work

    initFlash();            // Enable output on the pins that control the transistors that flash the flash LEDs

    output1onFOEpin();      // Enable the 1Hz output from the RTC via its Frequency Output Enable pin


    FOUT_in_pin_enable();   // Enable an interrupt on the rising edge of the 1Hz FOUT coming from the RTC


    rx8900_open_MOS();      // Open the switch that connects Vcc to Vbat. This way when the person pulls the battery out, the
    // capacitor connected to Vbat will not be connected to the XMEGA and will only be used to power the RTC

    // This also disables voltage detection because it seems you can not open the switch with it enabled.


    sei();                  // Note that all our ISR are empty, we only use interrupts to wake from sleep.
    
    // TODO: Find a way to stop ISR from running to save the power easted in all those pushes and pops


    showDashes();           // Show "------ ------" on the screen while we wait for the RTC to warm up

    _delay_ms(1000);        // tSTA RX8900 oscillator stabilization time 1s max at 25C
                            // "Please perform initial setting only tSTA (oscillation start time), when the
                            // built-in oscillation is stable."

    clearLCD();

    // Diagnostic functions

    while (testPinBGrounded()) {

        // Test pin B will show the current time in the RTC - even if it has not been set or reset yet
        // Right colon indicates RTC time
        // Left decimal point means low voltage flag set in RX8900
        // Right decimal point means low voltage flag set in EEPROM (we have seen a low voltage on RX8900 in the past)

        if ( rx8900_check_low_voltage()  ) {
            decimalLOn();
        }

        if ( load_low_voltage_flag_from_EEPROM() != 0x00 ) {
            decimalROn();
        }

        rx8900_time_regs_block_t time_now_reg_block;

        colonROn();
        rx8900_time_regs_get( &time_now_reg_block );
        showClockTime( &time_now_reg_block );
        sleep_cpu();

        clearLCD();

        // Next show the days since midnight 2000
        time_count_t time_now;
        rx8900_time_regs_to_count( &time_now , &time_now_reg_block );
        showNowD( time_now.d );
        sleep_cpu();
        clearLCD();

    }

    while (testPinTGrounded()) {

        // Test pin T will show the current trigger time - even if it has not been set yet
        // Left colon indicates trigger time
        // Right decimal point means trigger has been pulled

        if ( load_trigger_flag_from_EEPROM() ) {

            rx8900_time_regs_block_t trigger_time_reg_block;

            load_triggertime_from_EEPROM( &trigger_time_reg_block );
            colonLOn();
            showClockTime( &trigger_time_reg_block );
            sleep_cpu();
            clearLCD();

            // Next show the days since midnight 2000

            time_count_t time_trigger;
            rx8900_time_regs_to_count( &time_trigger, &trigger_time_reg_block );
            showNowD( time_trigger.d );
            sleep_cpu();
            clearLCD();

        } else {

            showNoTrig();
            sleep_cpu();
            clearLCD();

        }

    }


    // Sanity check EEPROM flags
    // Flags must all be either 0 or 1

    if ( load_low_voltage_flag_from_EEPROM() > 0x01 ) {
        eepromErrorMode( 1 );
        __builtin_unreachable();
    }

    if ( load_start_flag_from_EEPROM() > 0x01 ) {
        eepromErrorMode( 2 );
        __builtin_unreachable();
    }

    if ( load_trigger_flag_from_EEPROM() > 0x01 ) {
        eepromErrorMode( 3 );
        __builtin_unreachable();
    }


    if ( ! load_start_flag_from_EEPROM() ) {      // We have never set the RTC time.

        // This is our first power up in the factory. We need to init the RTC and set the current time

        if (load_trigger_flag_from_EEPROM() ) {

            // Hmmm.... We seem to have triggered even though we are in factory startup?
            // This is wonky

            eepromErrorMode(4);

            __builtin_unreachable();

        }

        // We have seen a low voltage, so we need to set up the rx8900
        rx8900_init();

        // Clear the low voltage flag from our initial powerup
        rx8900_clear_voltage_flags();

        /// This is our first startup at the factory! Set the current time into the RTC!

        rx8900_time_regs_block_t now;

        load_starttime_from_EEPROM( &now );

        if (!rx8900_time_regs_valid( &now ) ) {

            eepromErrorMode( 7 );

        }

        rx8900_time_regs_set( &now );

        //rx8900_set_magic();     // As a backup plan, also store our secret magic in the unused alarm registers
        // so we can check later

        // Mark that we used the start_time so we don't try to reuse it
        save_start_flag_to_EEPROM();

    } // if (load_start_flag_from_EEPROM() == 0x00 )


    // Do we have a low voltage condition now?

    if ( rx8900_check_low_voltage() ) {

        // Permanently remember this since we now do not know what time it is ever again
        save_low_voltage_flag_to_EEPROM();

        // Don't bother clearing the low voltage because the time is gone forever (or until
        // reset at factory) so nothing we can do about it now

    }

    if (load_low_voltage_flag_from_EEPROM() ) {

        // Oh no! RTC time was lost! We do not know what time it is!
        // We do not know what time it is now! No place good to go from here.

        if ( load_trigger_flag_from_EEPROM() ) {

            // We have triggered.

            // We have already triggered! There is not much we can do here except tell the user that we know
            // when they triggered, but can not show a count.  Hopefully they will get the current time programmed
            // back into the RTC and revive their count!

            rx8900_time_regs_block_t trigger_time;

            load_triggertime_from_EEPROM( &trigger_time );

            where_has_the_time_gone_mode(&trigger_time);

            __builtin_unreachable();

        } else {    // if ( !load_trigger_flag_from_EEPROM() )

            // RTC not set and trigger never pulled

            // (New old stock?)

            // Ok, we do not know what time it is but we have not triggered yet. This is a hard case.
            // We could start up and use a relative time to mark the trigger, but then we are
            // hosed if the RTC ever de-powers. I don't want a TSL that does not know what
            // time it is to look just like one that does since this is a latent and
            // invisible defect.

            // "cloc Error Mode"

            clockErrorMode();

            __builtin_unreachable();

        }  // if ( load_trigger_flag_from_EEPROM() )

        __builtin_unreachable();

    }

    // If we get here, then we know that the RTC has the correct time

    rx8900_time_regs_block_t time_trigger_reg_block;

    // Have we ever been triggered?

    if ( load_trigger_flag_from_EEPROM() ) {

        // We have triggered! They just changed the battery!

        // Load the trigger_time from EEPROM

        load_triggertime_from_EEPROM( &time_trigger_reg_block );

        if (!rx8900_time_regs_valid( &time_trigger_reg_block ) ) {

            eepromErrorMode( 8 );

        }
        // Fall though to normal run mode below...

    } else {

        // We are trigger virgins!

        // Before we continue to "Ready to Launch mode", we need the pin to be in so that it can be pulled out. so
        // show clock time a long as pin is out for double check it got set right and is running

        rx8900_time_regs_block_t now;

        uint8_t blink_toggle;

        triggerPinEnable();                 // Enable the pull-up, input buffer, and the interrupt
                                            // The interrupt wakes us from sleep the moment the pin is pulled
                                            // so there is not a lag until the next second.

        while ( !triggerPinPresent() ) {

            // Blink the colons to indicate clock mode

            blink_toggle = !blink_toggle;

            if ( blink_toggle ) {

                colonLOn();
                colonROn();

            }

            rx8900_time_regs_get( &now );
            showClockTime( &now );
            sleep_cpu();

            colonLOff();
            colonROff();

        }

        _delay_ms(100);         // Debounce the pin

        // if we get here, we know we have never been triggered and the pin is armed and ready

        // "Ready to Launch mode"

        while ( triggerPinPresent() ) {

            // Show a nice pattern until the pin is pulled that shows we are ready

            // TODO: Check for low battery in here?
            // TODO: Make more power efficient?

            figure8PatternUntilReleased();

        }

        // Trigger pin pulled!

        // Clear the display for instant feed back!

        clearLCD();

        // Grab the current time from RTC!

        rx8900_time_regs_block_t trigger_time;

        rx8900_time_regs_get( &trigger_time );

        rx8900_time_regs_set( &trigger_time );      // Set back the current time.
                                                    // This has the effect of restarting the current second
                                                    // so we are counting up from the exact sub-second moment that the pin was pulled.

        save_triggertime_to_EEPROM( &trigger_time );    // Save the time we triggered forever
        save_trigger_flag_to_EEPROM( );                 // Set the flag so we know that trigger_time in EEPROM is valid

        triggerPinDisable();                        // Disable interrupt, pull-up, and input buffer to save power
                                                    // Really important becuase the pull-up would be shorted to ground anytime the pin was back in
                                                    // and the input buffer is going to float without a pull-up.

        // Flash bulb party!!!

        flash();

        // Note that it is important that this complete within 1 second of the pull
        // or we will miss a second in our count this pass (it would come back on next battery change)
        // This deadline is no problem with current flash pattern.

    }

    // When we get here, we know that the RTC has a good time and trigger_time is set
    // Now we have to figure out what the display count looks like by subtracting the
    // time_trigger from the time_now to get the time_since_lanuch

    time_count_t time_trigger;

    rx8900_time_regs_to_count( &time_trigger , &time_trigger_reg_block );


    rx8900_time_regs_block_t time_now_reg_block;
    rx8900_time_regs_get_and_update_century_interlock( &time_now_reg_block );       // This will the century interlock and save back to EEPROM if nessisary

    time_count_t time_now;
    rx8900_time_regs_to_count( &time_now , &time_now_reg_block );


    time_count_t time_since_lanuch;
    if ( time_count_subtract( &time_since_lanuch , &time_now , &time_trigger ) ) {

        // The trigger time is in the future! Error!
        // This should only ever happen if there was an EEPROM corruption or someone is
        // messing with the EEPROM data

        eepromErrorMode(5);

        __builtin_unreachable();

    }

    // We are ready to start counting! See you in 30 years!

    // time_since_lanch has our count ready for us.

    run( time_since_lanuch.d , time_since_lanuch.h , time_since_lanuch.m , time_since_lanuch.s );

    // If we get here, then we have been running continuously for 1 million days.
    // TODO: Have the unit use its recently evolved sentience to add an additional digit to the days display?

    longNowMode();

    __builtin_unreachable();
}


// Subroutine for handling LCD Frame Interrupts
// This is a user configurable interrupt based
// on the frame rate of the LCD. It can be used
// as a miscellaneous timer by the user since it
// occurs at a constant rate.

// We leave it empty and just do all our processing when it returns.
// It would be nice to avoid this altogethers, but I do not think it is possible on AVR.

EMPTY_INTERRUPT(LCD_INT_vect);


