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

#include <util/delay.h>

typedef __uint24  uint24_t;     // Make 24 bit type look normal

void enable_rtc_xtal() {

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

void enable_rtc_TOSC1() {

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
	LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV2_bm |LCD_CLKDIV1_bm | LCD_CLKDIV0_bm | LCD_LPWAV_bm; //0xB8   2.65uA
//	LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV2_bm |LCD_CLKDIV1_bm | LCD_CLKDIV0_bm ; //No Low power waveform         3.7uA

    // PRESC divides the 32khz clock /16 into the LCD
    // Clockdiv 111 further divides it down to 32Hz refresh

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

    LCD.INTCTRL =  LCD_XIME3_bm | LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 32 frames with high priority (1 Hz)

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

    // Disabling RTC does not noticably reduce power

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

    while ( d > 0 && i < 6 ) {      // Don't show leading zeros. No need to wipe because digits only go up.
        
        // TODO: unrool this so we only uses as many bits as nessisary

        uint24_t next = d / 10;

        uint8_t ones = d-(next*10);

        digitShow( 6+i , ones );

        i++;

        d = next;

    }

}

inline void showNowS( uint8_t s) {

    // TODO: We need to write some code to write some code here.
    // We need to figure out the minimum segment transition from second to second
    // and emit the code to implement those transisions directly.


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

    if (t) {
        digitShow( 5 , t );
    }

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

void run() {

    for( uint16_t d=0; d< UINT16_MAX; d++ ) {

        showNowD( d );

        digitBlank( 5 );        // Clear the residual leading '2' from the hours-tens digit.

        for( uint8_t h=0; h<24; h++ ) {

            showNowH(h);

            for( uint8_t m=0; m<60; m++ ) {

                showNowM(m);

                for( uint8_t s=0; s<60; s++ ) {

                    showNowS( s );

                    if (!testPin3Grounded()) {

                        sleep_cpu();

                    }
                }       // s
            }           // m
        }               // h
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


    // and fade...

    for( uint8_t b=100; b>0; b-=2) {

        FlashFetOn1();

        for( uint8_t d=b; d; d-- ) _delay_us(10);
        FlashFetOff1();
        for( uint8_t d=100-b; d; d-- ) _delay_us(10);

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
    enable_rtc_ulp();

    disableUnusedIOPins();      // Save a little power
    
    USI_TWI_Master_Initialise();        // Init TWO pins to pullup. Keep them from floating to save power. 

    initTestPins();             // Set pullups on the 2 extra pins on the ISP

    // Disable unused peripherals to save power
    prr_init();
    disableJTAG();

	// Configure Interrupt Priority Level and Location of Vectors
	pmic_init();

	// Initialize the LCD Controller
	lcd_init();

	// Enable interrupts
    PMIC.CTRL |= PMIC_LOLVLEN_bm;
	sei();

/*
	PORTCFG.MPCMASK = 0xFF;
	PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLUP_gc;
	PORTCFG.MPCMASK = 0xFF;
	//PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLUP_gc;
	PORTCFG.MPCMASK = 0xFF;
	PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLUP_gc;
	PORTCFG.MPCMASK = 0xFF;
	PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLUP_gc;
	PORTCFG.MPCMASK = 0xFF;
	PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLUP_gc;
	PORTCFG.MPCMASK = 0xFF;
*/

	set_sleep_mode( SLEEP_SMODE_PSAVE_gc );     // Lowest power sleep with LCD

	sleep_enable();
    
    initFlash();
    //flash();

    //lcd_set_pixel( 0 , 3);
    //lcd_set_pixel( 2 , 3);

    

    /*
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
    
    
*/
    // NOW WE WAIT FOR TRIGGER PIN TO BE PRESSED

    triggerPinInit();       
    
    uint8_t s=0;
/*
    while  (1) {

        for( uint8_t d=0;d<10;d++) {
            clearLCD();

            figure8On( d , s );
            digitShow( 6 ,  8 );
            digitShow( 7 ,  d );

            //digitShow( d , s % 10   );
            sleep_cpu();

        }

        s++;

        sleep_cpu();


    }

    */
    


    //lcd_1hz();          // Generate interrupt once per second

    uint8_t n=9;
    uint8_t d=11;

    // Show a marching countdown pattern until pin released...
    
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

    } while ( !triggerPinPressed() );     // Repeat until pin released

    clearLCD();
    
    _delay_ms(100);     // Debounce switch

    // PRESSED - ARMED AND READY!

    // Show figure 8 pattern until pin pulled

    // TODO: unroll this for efficiency
    
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


    clearLCD();
    
    triggerPinDisable();           // So we do not waste current running though pull up and the switch forevermore....

    flash();

    // Clear out whatever was left from the countdown so we can assume all
    // all blank digits in run()
    
    
    for(int i=0; i<=3;i++) {
        
        showNowD(i);
        sleep_cpu();
    }        
    
    
    // TWI TEST CODE
    

        
    clearLCD();
                
                
    uint8_t reg[16];
        
    clearLCD();
        
    reg[0] = 0x00;        // Dummy write to 0x0c
                        

    
    while (1) {
        
        clearLCD();
        
        while (1) {
            
            reg[1] = 0b00000101;        // Switch FOUT to 1024hz            
        
            USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0x00c , reg , 2 );
            
            sleep_cpu();
            
            USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0x0c , reg , 2 );
            
            showNowD( reg[1] );
            
            sleep_cpu();
            
            
            reg[1] = 0b00000001;        // Switch FOUT to 1024hz            
            
            USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0x00c , reg , 2 );
            
            sleep_cpu();
                        
            
        }            

                               
        USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0x0d , reg , 1 );
        
        showNowD( reg[0] );
        
        sleep_cpu();
                
    }        

    run();

   uint8_t count=0;

    while(1) {

        for( uint8_t slot=0; slot<12;slot++) {

            digitOn( (11-slot) , ( slot  + count) % 10 );

        }

    while (1) {
        sleep_cpu();
        LCD.DATA0 = 0xff;
        sleep_cpu();
        LCD.DATA0 = 0x00;
    }

        for( uint8_t slot=0; slot<12;slot++) {

            digitOff( (11-slot) , ( slot  + count) % 10 );

        }
        count++;
    }




    while (1) {

        for(uint8_t i=0; i<12; i++ ) {


            for( uint8_t slot=0; slot<12;slot++) {

                digitOn( slot , 12-slot );

            }

            //while(1);

            sleep_cpu();

            for( uint8_t slot=0; slot<12;slot++) {

                digitOff( slot , i );

            }
            sleep_cpu();
        }

    }



	while (1) {

		//PORTC.OUTTGL = 0xff;

		// Clear the display memory
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA0=0xff;

		sleep_cpu();

		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA1=0xff;

		sleep_cpu();

		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA2=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA3=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04

		LCD.DATA4=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA5=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA6=0xff;


		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA7=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA8=0xff;


		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA9=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA10=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA11=0xff;

		sleep_cpu();
		//LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA12=0xff;

		sleep_cpu();
		sleep_cpu();
		sleep_cpu();
		sleep_cpu();
		sleep_cpu();


		//PORTC.OUTTGL = 0xff;


		//set_sleep_mode( SLEEP_SMODE_PDOWN_gc );
		//sleep_cpu();

		// Infinite Loop to add code and allow LCD
		// Frame Interrupt to continuously operate
	}
}


// Subroutine for handling LCD Frame Interrupts
// This is a user configurable interrupt based
// on the frame rate of the LCD. It can be used
// as a miscellaneous timer by the user since it
// occurs at a constant rate.

// We leave it empty and just do all our processing when it returns.
// It would be nice to avoid this alltoether, but I do not think it is possible on AVR.

EMPTY_INTERRUPT(LCD_INT_vect);

