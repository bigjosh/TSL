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

#define F_CPU 2000000		// Default internal RC clock on startup


void enable_rtc() {

	//////////////////////////////////////////////////////////////////////
	//CLK.RTCCTRL
	//     7       6       5       4       3       2       1       0
	// |   -   |   -   |   -   |   -   |      RTCSRC[2:0]     |  RTCEN  |
	//     0       0       0       0       0       0       0       0
	// LCD Runs off the RTC
	// Enable RTC, source from 32kHz internal ULP osc
	CLK.RTCCTRL = CLK_RTCEN_bm; // 0x01
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
	LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV1_bm | LCD_CLKDIV0_bm | LCD_LPWAV_bm; //0xB8
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

    LCD.INTCTRL = LCD_XIME4_bm | LCD_XIME3_bm | LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 64 frames with high priority (1 Hz)
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

    // TODO: DO we need to RTC? I think we have to track it ourselves anyway and increment off the LCD interrupt

    PR.PRGEN = PR_USB_bm | PR_AES_bm | PR_EVSYS_bm | PR_DMA_bm;


    // These following lines reduce power consumption durring active mode
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

inline void lcd_1hz(void) {
    LCD.INTCTRL = LCD_XIME4_bm | LCD_XIME3_bm | LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 64 frames with high priority (1 Hz)
}

inline void lcd_2hz() {
	LCD.INTCTRL = LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 16 frames with high priority - 2Hz


}

inline void showNowD( uint16_t d ) {

    uint8_t i=0;

    while ( d > 0 && i < 6 ) {      // Don't show leading zeros. No need to wipe because digits only go up.

        uint16_t next = d / 10;

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
    digitShow( 5 , t );


}


void run() {

    uint8_t ff_mode=0;

    for( uint16_t d=0; d< UINT16_MAX; d++ ) {

    showNowD( d );


        for( uint8_t h=0; h<24; h++ ) {

        showNowH(h);


            for( uint8_t m=0; m<60; m++ ) {

                // Only check for trigger pin pressed at the end of each minute

                // We enable the pullup BEFORE drawing the digits because it takes more than 0.5uA for the pull-up
                // to pull up when the switch is open.

                PORTD.PIN0CTRL = PORT_OPC_PULLUP_gc;        // Enable pull-up on trigger pin


                showNowM(m);


                if (PORTD.IN & _BV( 0 ) ) {      // Pin pressed?
                    ff_mode=1;
                } else {
                    PORTD.PIN0CTRL = 0;        // Disable pull-up on trigger pin
                }



                for( uint8_t s=0; s<60; s++ ) {

                    showNowS(s );

                    if (!ff_mode) {

                        sleep_cpu();

                    } else {

                        if ( ! (PORTD.IN & _BV( 0 ))  ) {     // Repeat until pin released -

                            // Pin released, so exit FF mode

                            ff_mode=0;
                            PORTD.PIN0CTRL = 0;        // Disable pull-up on trigger pin


                        }

                    }

                }



            }
        }
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

    // Configure System and Peripheral Clocks
    //sysclk_init();


    // Disable unused peripherals to save power
    prr_init();
    disableJTAG();


    // Enable the ultra low power RTC clock
    // We will drive the LCD from this
	enable_rtc();
	// Configure Interrupt Priority Level and Location of Vectors
	pmic_init();


	// Initialize the LCD Controller
	lcd_init();

	// Enable interrupts
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

	//set_sleep_mode( SLEEP_SMODE_IDLE_gc);
	set_sleep_mode( SLEEP_SMODE_PSAVE_gc );

	sleep_enable();

    //lcd_set_pixel( 0 , 3);
    //lcd_set_pixel( 2 , 3);

    //while (1);


    // NOW WE WAIT FOR TRIGGER PIN TO BE PRESSED

    PORTD.PIN0CTRL = PORT_OPC_PULLUP_gc;        // Enable pull-up on trigger pin

    uint8_t s=0;

    lcd_2hz();

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

    } while ( !(PORTD.IN & _BV( 0 ) ));     // Repeat until pin pressed

    // PRESSED - ARMED AND READY!

    lcd_1hz();


    // TRIGGERED!

    lcd_1hz();

    uint8_t n=9;
    uint8_t d=11;

    do {
        clearLCD();
        digitShow( d , n );

        sleep_cpu();

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

    } while ( (PORTD.IN & _BV( 0 )) );     // Repeat until pin released -


    PORTD.PIN0CTRL = 0;        // Disable pull-up on trigger pin


    /*

    while (1) {

        for( uint8_t c=0; c< 64; c++ ) {

           // LCD.CTRLF = c;
            lcd_set_pixel( 2 , 23);
            lcd_set_pixel( 0 , 23);
            sleep_cpu();
            lcd_clear_pixel( 2 , 1);
            lcd_clear_pixel( 0 , 1);
        }
    }


    */
    /*

    while (1) {



        for (uint8_t seg=0; seg< LCD_MAX_NBR_OF_SEG; seg++ ) {


            for(uint8_t pix=0; pix<LCD_MAX_NBR_OF_SEG; pix++ ) {


                lcd_set_pixel( seg , pix );

                sleep_cpu();

                lcd_clear_pixel( seg , pix );

                sleep_cpu();


            }
        }

        LCD.CTRLA |= LCD_CLRDT_bm; //0x04
         sleep_cpu();


    }
    */

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

// We leave it emptry and just do all our processing when it returns.
// It would be nice to avoid this alltoether, but I do not think it is possible on AVR.

EMPTY_INTERRUPT(LCD_INT_vect);

