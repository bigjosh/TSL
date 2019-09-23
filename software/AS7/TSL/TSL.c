/*
 * Time Since Launch firmware for ATXMEGA63B3
 *
 * https://github.com/bigjosh/TSL
 *
 */

// Shown on Pin `B` diagnostic display.

#define VERSION 105

// Required AVR Libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>       // pgm_read_byte() in ReadSignatureByte()

#include "lcd.h"

#include "USI_TWI_Master.h"

#include "code2code_output.h"   // Include the call to the computer generated code that updates the LCD for an hour

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


// The ADC on this chip lives on PORTB

// Disable both the analog to digital converter and the analog comparitor
// to save power

void adc_powerdown_adc_and_ac() {

    PR.PRPB = PR_ADC_bm | PR_AC_bm;

}

// Enable the analog to digital converter but disable (or leave disabled) the analog comparitor
// We never want the AC enabled, so we hard code these two together to save having to read the register,
// change the ADC bit, and and write back.

void adc_powerup_adc_powerdown_ac() {

    PR.PRPB = PR_AC_bm;

}

// Needed to get the ADC calibration
// http://barefootelectronics.com/xMegaADC.aspx

uint8_t ReadSignatureByte(uint16_t Address)
{
    NVM_CMD = NVM_CMD_READ_CALIB_ROW_gc;
    uint8_t Result;
    Result = pgm_read_byte((uint8_t *)Address);
    NVM_CMD = NVM_CMD_NO_OPERATION_gc;
    return Result;
}


// We initialize the registers in the ADC one time at startup
// and then leave them like that so we don't waste time setting
// them when we need a sample. These settings persist even when the
// ADC is disabled and stopped in power reduction mode.
// Assumes ADC is not in power reduction mode

/*
    The power reduction (PR) registers provide a method to stop the clock to individual peripherals. When this is done, the
    current state of the peripheral is frozen and the associated I/O registers cannot be read or written. Resources used by the
    peripheral will remain occupied; hence, the peripheral should be disabled before stopping the clock. Enabling the clock to
    a peripheral again puts the peripheral in the same state as before it was stopped. This can be used in idle mode and
    active modes to reduce the overall power consumption. In all other sleep modes, the peripheral clock is already stopped.
*/

// We have plenty of flash, so we inline this to save a call/return and
// coax the compiler into simplifying the low battery voltage compare
// in the main run() loop.

inline void adc_init() {

    // Set calibration bytes to factory values
    ADCB.CALL = ReadSignatureByte(0x20) ; //ADC Calibration Byte 0
    ADCB.CALH = ReadSignatureByte(0x21) ; //ADC Calibration Byte 1

    // Lowest current for lowest power
    // Only need 8 bits for our purposes, so save steps to save power
   // ADCB.CTRLB = ADC_CURRLIMIT_LOW_gc | ADC_RESOLUTION_8BIT_gc;

   // Signed mode to get rid off offset
    ADCB.CTRLB = ADC_RESOLUTION_8BIT_gc | ADC_CONMODE_bm;

    // Measure the Vcc against the internal 1V reference
    // Enable the bandgap since thats where the 1V reference comes
    ADCB.REFCTRL = ADC_REFSEL_INT1V_gc | ADC_BANDGAP_bm ;

    // We leave the prescaller at default 1/4 to get the quickest measurement possible
    // and get the hell out of here. Our main clock is 2MHz, so at 1/4 we are at 500Khz
    // which is between 100kHZ min and 1.4MHz max ADC clock rate.

    // ADCB.PRESCALER = ADC_PRESCALER_DIV4_gc;

    // Set up channel 0
    // 1x gain
    // Internal sample (no pin)

    ADCB.CH0.CTRL = ADC_CH_GAIN_1X_gc | ADC_CH_INPUTMODE_INTERNAL_gc;

    // Sample the Vcc scaled down by 10x so 1V on Vcc is 0.1V on the ADC
    // Negative input is always ground for internal measurements.

    ADCB.CH0.MUXCTRL =   ADC_CH_MUXINT_SCALEDVCC_gc ;

}


// Convert clocks to microseconds

static inline unsigned long cycles2us( uint32_t  cycles ) {

    // Unit anaylisis : ((cycles/s)  * cycles)) / ( microseconds/s)  =  microseconds
    return ( F_CPU  * cycles ) / 1000000UL;
}


// We are using 1/4 prescaller for ADC
#define CYCLES_PER_ADC_TICK 4
#define ADC_TICKS_TO_CYCLES(x) (x*CYCLES_PER_ADC_TICK)

// Use the internal multimeter to read the current Vcc
// Returns Vcc * 10, so 2.4 volts returns 24.
// Assumes ADC is disabled and in power reduction mode
// Leaves it the same way


static inline uint8_t adc_read_vcc_x_10() {

    // Turn the ADC on
    adc_powerup_adc_powerdown_ac();

    // Enable the ADC and start the conversion
    // TODO: Can we do this in a single operation?
    //ADCB.CTRLA = ADC_CH0START_bm | ADC_ENABLE_bm;

    ADCB.CTRLA = ADC_ENABLE_bm;

    // Wait for the ADC start-up time (typical max. 24 ADC clocks).
    // Data sheet really not clear here. Says typical 12 ticks,
    // max 24 ticks. How do we know when it is ready?
    // (Round up to be safe)
    _delay_us( cycles2us( ADC_TICKS_TO_CYCLES(24)  ) + 1 );

    // Wait for the bandgap to start up
    // "Startup time as reference for ADC (1 ClkPER + 2.5µs)"
    // TODO: Is this included in the ADC start up time?
    _delay_us( cycles2us( ADC_TICKS_TO_CYCLES(1) ) + 3 );

    // Clear the interrupt bit so we can tell when the conversion is done
    // "The bit can also be cleared by writing a one to the bit location"

    ADCB.INTFLAGS = ADC_CH0IF_bm;


    // Start the conversion (keep enabled bit 1)

    ADCB.CTRLA = ADC_CH0START_bm | ADC_ENABLE_bm;

    // Wait for the conversion to complete
    // "The interrupt flag is set when the ADC conversion is complete."
    // This should only take a few microseconds, so not worth setting up the
    // interrupt and sleeping.

    while ( !(ADCB.INTFLAGS & ADC_CH0IF_bm) );

    // We only asked for 8 bits, so grab them
    // We are in signed mode, so using signed variable here
    int8_t r = ADCB.CH0RESL;

    // Disable the ADC (we have to before we can turn it off)
    ADCB.CTRLA = 0;

    // Turn ADC off until the next time we need to tomorrow
    // to save power
    adc_powerdown_adc_and_ac();

    // Calculate the resulting voltage according to the formula
    // We do this after we've shut the place down to save a smidgen of power
    // Hopefully the compiler we will smart enough to eliminate this calculation
    // when the caller compares the return value to a static value.
    // The datasheet is unclear on how unsigned 8-bit samples are scaled,
    // but I am assuming that TOP=127 so...
    // r = ( (v/10) / 1.0 ) * 128
    // Since V is scaled by 1/10 and compared to the 1V reference

    // To save integer precision we algebraically change the order of operation...
    uint8_t vx10 = (r * 100 ) / 128;

    return vx10;
}

//  Disable unused peripherals to save power

void prr_init() {

    // Disable everything we don't ever use

    // Disabling RTC does not noticeably reduce power

    PR.PRGEN = PR_USB_bm | PR_AES_bm | PR_EVSYS_bm | PR_DMA_bm | PR_RTC_bm;


    // These following lines reduce power consumption during active mode

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

void diagnostic_init_Pins() {



    // These appear on ISP pins 3 & 4 respectively

    PORTC.PIN2CTRL = PORT_OPC_PULLUP_gc ;
    PORTC.PIN3CTRL = PORT_OPC_PULLUP_gc ;
}

// Set up some ports for more efficient access


void vport_init() {

    // Map PORTC to Virtual Port 0
    // Since we will be Accessing these every minute
    // to check for diagnostic pins, this will make those accesses much faster.

    PORTCFG.VPCTRLA = PORTCFG_VP0MAP_PORTC_gc;    
    
    
    // Put PORTB onto VP2 so we can test the FOUT signal in single instruction
    // Note that the VP2 bit 2 is HARDCODED into the code2code program so any changes must be reflected there too

    PORTCFG.VPCTRLB  = PORTCFG_VP2MAP_PORTB_gc;

    /*
    
    Note that these tests are important, but can not be outside a comment because of the way VPORTx is implemented a a pointer.

    #if (FOUT_VPORT) != (VPORT2)
    #error If you change the FOUT VPORT you must also update the code in code2code.cpp
    #endif


    #if (TRIGGER_VPORT) != (VPORT0)
        #error If you change the FOUT VPORT you must also update the code in code2code.cpp
    #endif    
    
    
    
    */
    
}

void diagnostic_init_PinT_OutputMode() {
    PORTC.DIRSET = _BV(3);
}

void diagnostic_out_PinT_1() {
    PORTC.OUTSET = _BV(3);
}

void diagnostic_out_PinT_0() {
    PORTC.OUTCLR = _BV(3);
}

void diagnostic_init_PinB_OutputMode() {
    PORTC.DIRSET = _BV(2);
}

void  diagnostic_out_PinB_1() {
    PORTC.OUTSET = _BV(2);
}

void  diagnostic_out_PinB_0() {
    PORTC.OUTCLR = _BV(2);
}


inline uint8_t diagnostic_in_PinB_Grounded() {

    return ( ! (VPORT0.IN & _BV(2) ));

}


inline uint8_t diagnostic_in_PinT_Grounded() {

    return ( ! (VPORT0.IN & _BV(3) ));

}

// Returns 1 if either diagnostic pin is grounded
// The VPORT makes this compile down nicely...

/*

    2374:	92 9b       	sbis	0x12, 2	; 18
    2376:	02 c0       	rjmp	.+4      	; 0x237c <main+0xad0>
    2378:	93 99       	sbic	0x12, 3	; 18
    237a:	fc c2       	rjmp	.+1528   	; 0x2974 <main+0x10c8>

*/

inline uint8_t diagnostic_in_EitherPin_Grounded() {
    return diagnostic_in_PinB_Grounded() || diagnostic_in_PinT_Grounded();

}

// Enable the pin on the XMEGA that gets the FOUT signal from the RX8900 and generates an interrupt to wake us once per second

// QUIRK: The RX8900 updates the time on the FALLING edge of FOUT.

void FOUT_in_pin_enable() {
    
    PORTB.PIN2CTRL = PORT_ISC_BOTHEDGES_gc;       // Interrupt on both the rising and falling edges of the 1Hz FOE signal from the RTC
                                                  // We will check these on waking and interlock to avoid spurious resets
                                                      

    // Use this code when all spurious triggers on FOUT are fixed
    // to interrupt only once per second and avoid the interlock code
    //PORTB.PIN2CTRL = PORT_ISC_FALLING_gc;       // Interrupt on both the rising and falling edges of the 1Hz FOE signal from the RTC

    PORTB.INTCTRL = PORT_INT0LVL0_bm;            // PORTB int0 is low priority level interrupt
    PORTB_INT0MASK |= PIN2_bm;                   // Enable pin 7 to be int0    
    
    #if FOUT_PIN != 2 
        #error If you change the FOUT pin you must also update the code in code2code.cpp
    #endif
            
}

// Returns the current FOUT pin state

inline uint8_t fout_pin_in_value() {
    return FOUT_VPORT.IN & _BV(FOUT_PIN);
}

// A new second starts on the falling edge of FOUT
// This function will sleep until that falling edge
// Filters out spurious interrupts by testing the value
// of FOUT after each interrupt to make sure it matches the
// expected state and interlocks the rising and falling edges
// This was added because we were seeing spurious interrupts
// sometimes due to static electricity.
// Assumes that the FOUT pin is set to interrupt on _both_ edges.
// Note that seconds increment on FOUT HIGH to LOW transition

// Returns immediately after the next seconds increment event on the RX8900
// Returns with FOUT LOW

inline void sleep_until_next_second() {
    
    // On the RX89800, the seconds increments on the high-to-low transition
    // We currently get an interrupt on both edges, and we sometimes get spurious interrupts
    // so we have this interlock where we check for both rising and falling edges
    // and return on the falling, which indicates that the seconds just incremented. 

    // This first while() will fall though if FOUT is already high

    while (!fout_pin_in_value()) {
        sleep_cpu();
    }

    // Here FOUT is high

    do {
        sleep_cpu();
    } while (fout_pin_in_value());          // Repeat until it goes low
    
    // Here FOUT is LOW (seconds just incremented)

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
    PORTC.DIRCLR   = PIN7_bm;                                            // Set to input
    PORTC.PIN7CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc ;        // Enable pull-up on trigger pin
    _delay_ms(1);                                                        // Give the pullup a moment to do its thing
    PORTC.INTCTRL = PORT_INT0LVL0_bm;
    PORTC_INT0MASK |= PIN7_bm;
}

// Turn off interrupt, ground pin (to hopefully shunt static discharge)

void triggerPinDisable() {

    PORTC_INT0MASK &= ~PIN7_bm;                            // Disable interrupt
    PORTC.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc;            // Disable pull-up on trigger pin, disable input buffer
    PORTC.OUTCLR   = PIN7_bm;                              // Set low
    PORTC.DIRSET   = PIN7_bm;                              // Set to output (now driving low)
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
// wake us at the beginning of the frame anyway


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

void initFlashBulbs() {

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

void rx8900_fout_1KHz_x(void) {

    uint8_t reg = 0b00000100;
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_EXTENTION_REG , &reg , 1 );

}

// Set FOUT on the RX8900 to 1Hz (default 32Khz)

void rx8900_fout_1Hz_x(void) {

    uint8_t reg = 0b00001000;
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_EXTENTION_REG , &reg , 1 );

}

// Called anytime the RX8900 has seen low voltage (VLF)
// Sets all the control registers to known values 
// Clears the flags, so make sure you save any that you need before calling
// Does not reset the time counter 

void rx8900_initialize(void) {

    // First the  EXTENTION register
    // TEST  0 = Normal
    // WADA  0 = Week alarm (rather than day) (we don't care)
    // USEL  1 = Minute update (rather than second) (we don't use, so pick the slower one?)
    // TE    0 = Stops the fixed cycle interrupt (we don't use)
    // FSEL 10 = 1 Hz FOUT
    // TSEL 11 = 1 minute count down interrupt (we don't use, so pick the slowest one?)

    const uint8_t ex_reg = 0b00101011;
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_EXTENTION_REG , &ex_reg , 1 );

    // Next the FLAGS register
    
    // Importantly clears the low voltage detect flags to zero
    // also clears a bunch of alarm flags we don't use
    
    const uint8_t flag_reg = 0b00000000;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_FLAG_REG , &flag_reg , 1 );

    // Note here we reset. which is OK becuase to get here the low voltage detect had to be set. 

    const uint8_t contrl_reg = 0b01000000;     // 2s temp comp, no timers or interrupts or alarms, NO RESET

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_CONTROL_REG, &contrl_reg, 1 );
    
    // Default with MOS switch closed, sampled 2ms every 1s
    
    const uint8_t backup_reg= 0;

   // USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_BACKUP_REG , &backup_reg , 1 );    
    
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

void rx8900_open_MOS_x() {

    // Turn off the switch and disable the voltage detection system
    // The datasheet strongly suggests that the switch can not be opened unless
    // the voltage detect is disabled, which is a shame because we'd like to
    // have the chip go into backup made when the voltage drops below 2.4V

    uint8_t reg= RX8900_BACKUP_SWOFF_bm & RX8900_BACKUP_VDETOFF_bm;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_BACKUP_REG , &reg , 1 );

}


// Close the MOS switch between Vdd and Vbat. Leaves voltage detector off

void rx8900_close_MOS_x() {

    // Turn on the switch and disable the voltage detection system

    uint8_t reg= RX8900_BACKUP_VDETOFF_bm;

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_BACKUP_REG , &reg , 1 );

}


// Returns 1 if the RX8900 has seen a low voltage - which means its data is not trustworthy
// and it needs a RESET.

uint8_t rx8900_low_voltage_check() {

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

void rx8900_low_voltage_clear_x() {

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

// Always do a reset before calling this so we don't
// risk a time increment in the middle of our update.

// RX8900 QUIRK:
// Setting the registers forces FOUT LOW when running at 1Hz
// FOUT will then go HIGH after 500ms and then LOW again 1s after the original set
// We trigger interrupts on the falling edge so we see the new time each update right
// after it happens.


static void rx8900_time_regs_set( const rx8900_time_regs_block_t *rx8900_time_regs_block ) {
    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , 0x00 , rx8900_time_regs_block->time_regs, 8 );
}


// Load from chip

static void rx8900_time_regs_get( rx8900_time_regs_block_t *rx8900_time_regs_block ) {
    USI_TWI_Read_Data( RX8900_TWI_ADDRESS , 0x00 , rx8900_time_regs_block->time_regs, 8 );
}



// Load from chip, update century interlock if necessary
// Writes time to RX8900, which resets us back to the beginning of the current second...
// so make sure to only call at the beginning of the current second so we do not loose time.

static void rx8900_time_regs_get_and_update_century_interlock( rx8900_time_regs_block_t *rx8900_time_regs_block ) {

    rx8900_time_regs_get( rx8900_time_regs_block );

    uint8_t y = bcd2c( rx8900_time_regs_block->time_regs[6] );
    uint8_t i = bcd2c( rx8900_time_regs_block->time_regs[7] );     // Century interlock flag

    if (
        (y >=50 && !( i & 0x01 )) // If the year is 50-99 and the interlock is currently even...
        ||                        // ...or...
        ( y<50  &&  ( i & 0x01 )) // If the year is 00-49 and the interlock is currently odd...
    ) {
        // Increment the century interlock and write back to RTC
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

// This resets us back to the beginning of the current second
// It also forces FOUT low.

void rx8900_reset() {

    // Note here we add the RESET flag. This will start the timer at the beginning of the first second.

    uint8_t contrlreg = 0b01000001;     // 2s temp comp, no timers or interrupts or alarms, reset

    USI_TWI_Write_Data( RX8900_TWI_ADDRESS , RX8900_CONTROL_REG, &contrlreg, 1 );

}


void figure8PatternUntilTriggerReleased() {
    // Show figure 8 pattern until pin pulled

    // TODO: unroll this for efficiency
    // TODO: Update double time since it looks cooler?

    uint8_t s=0;


    do {
        clearLCD();

        for( uint8_t d=0;d<12;d+=2) {
            figure8On( d , s );
            figure8On( d+1 , (s+6)%8 );
        }


        s++;

        if (s==8) {
            s=0;
        }

        // This interlock makes sure we only update the display once per alternating FOUT levels
        // and not on spurious interrupts where FOUT does not change.

        // Note that we can not use wait_for_next_second() here becuase we want to check the
        // trigger pin state after each interrupt in case the interrupt was a pin change
        // on the trigger pin rather than FOUT.

        // We also always check the trigger pin state so that the reaction to the trigger pin
        // being pulled is instant and does not have to wait for the next FOUT transition.
        // (The trigger pin state change also generates an interrupt that will wake us).

        // Note that there is a race condition here where the user could pull the trigger pin
        // in the cycle between when we check it and when we go to sleep. Then it will not generate an interrupt
        // because the pin change happened before we entered sleep, so the user will have to wait 1/2 second
        // before the trigger pull is noticed. We could eliminate this race by bracketing the test and sleep
        // with cli() sei(), but this would use up power on every update to eliminate a litterally
        // 1 in a million race and the impact of that race is very low, so we leave it.
        // LMK if you ever actually see (and notice!) that race IRL!

        uint8_t last_fout = fout_pin_in_value();

        while ( last_fout == fout_pin_in_value() && triggerPinPresent() ) {

            sleep_cpu();

        }

        last_fout= fout_pin_in_value();

        while ( last_fout == fout_pin_in_value() && triggerPinPresent() ) {

            sleep_cpu();

        }

    } while ( triggerPinPresent() );     // Repeat until pin pressed

}


// Look like a normal clock
// Read current time from RTC and show on the display
// Indicates clock time with blinking decimal point on left module and colon on right module

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

// Shows the little battery icons with just thier
// bottom segment lit to express thier emptyness

void showEmptyBatteryIcon() {

    battSegOn(0);       // Outline
    battSegOn(3);       // Bottom segment

}

// Blinks whatever is on the LCD on and off at 2Hz

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

// Show blinking battery icons
// Draws <3uA @ 2.4V

void low_battery_mode() {

    clearLCD();
    showEmptyBatteryIcon();
    blink_lcd_forever();

    __builtin_unreachable();


}

void badInterruptMode() {

    clearLCD();
    showbAdint();
    blink_lcd_forever();

    __builtin_unreachable();

}

// Catch any errant interrupts
// These should never ever happen, but if they
// do happen we want to know becuase something is
// wrong

ISR(BADISR_vect) {
    badInterruptMode();
}

// Show the reason for last reset for 5 seconds and clear bits for next time
// Bits described in XMEGA B Manual 9.5.1

void showAndClearResetBits() {

    // Grab current reset bits
    uint8_t t = RST.STATUS;

    // Clear all reset bits
    RST.STATUS = RST_PORF_bm |  RST_EXTRF_bm | RST_BORF_bm | RST_WDRF_bm | RST_PDIRF_bm | RST_SRF_bm | RST_SDRF_bm ;

    clearLCD();

    showReset();

    // Power on
    if ( t & RST_PORF_bm ) {
        lcd_show_fontchar( lcd_font_char_P , 0 );
    } else {
        lcd_show_fontchar( lcd_font_char_dash , 0 );
    }

    // Ext reset pin
    if ( t & RST_EXTRF_bm ) {
        lcd_show_fontchar( lcd_font_char_E , 1 );
        } else {
        lcd_show_fontchar( lcd_font_char_dash , 1 );
    }

    // Brown out
    if ( t & RST_BORF_bm ) {
        lcd_show_fontchar( lcd_font_char_b , 2 );
        } else {
        lcd_show_fontchar( lcd_font_char_dash , 2 );
    }

    // PDI programming port reset (`d`ownload)
    if ( t & RST_PDIRF_bm ) {
        lcd_show_fontchar( lcd_font_char_d , 3 );
        } else {
        lcd_show_fontchar( lcd_font_char_dash , 3 );
    }

    // Software reset
    if ( t & RST_SRF_bm ) {
        lcd_show_fontchar( lcd_font_char_S , 4 );
        } else {
        lcd_show_fontchar( lcd_font_char_dash , 4 );
    }

    // Undefined reset bits
    if ( t & 0b11000000 ) {
        lcd_show_fontchar( lcd_font_char_U , 5 );
        } else {
        lcd_show_fontchar( lcd_font_char_dash , 5 );
    }

}

// Blink "999999 235959" forevermore
// Prevents unscrupulous sellers from trying to
// pass off TSLs that have rolled over as less used
// than they really are.

void longNowMode() {

    showNowMDY( 99 , 99 , 99);
    showNowHMS( 23 , 59 , 59);

    blink_lcd_forever();

    __builtin_unreachable();

}

// Show "------ ------"

void showDashes() {

    for(uint8_t d=0; d<12 ; d++ ) {

        showDash(d);

    }

}

// Used the instant after the pin is pulled to put something
// on the display so the transition from 0->1 count is seamless
// and happens smoothly 1 second after the pin is pulled.

void showZeros() {
    showNowD( 000000 );
    showNowHMS( 0 , 0 , 0 );
}

// This should trigger when the battery voltage hits about 2.4 volts
// The XMEGA can run down to 1.6V and the RX8900 can run down to
// 1.6V with temp compensation down to 2V, so this should give us
// plenty of notice

// Empirically this cuts out at between 2.5V and 2.6V on Vcc

#define LOW_BATTERY_VOLTAGE_X10 23

// Returns 1 if battery voltage reading less than LOW_BATTERY_VOLTAGE_X10
// Note that this uses about 200x normal power, so call sparingly
// which is fine because battery voltages change slowly.

static inline uint8_t check_low_battery() {

    // Turn on ADC, take a reading of Vcc, turn off Vcc
    // Returns Vcc * 10, so 2.4V would return 24
    // Note that due probably to rounding, the Vcc reading
    // is about 0.1V lower than the actual battery voltage.

    uint8_t vx10 = adc_read_vcc_x_10();

    return vx10 <= LOW_BATTERY_VOLTAGE_X10 ;

}


// Used for checking accuracy against a timebase
// Wait for T pin to go low, then resets the RTC to sync
// Then the B pin toggles at 1Hz forever
// Note that this is not meant to be an exact sync
// but instead to just get the pulse edges close to each
// other so that are easy to compare on the scope screen.
// It is changes in the relative offset that matter.


void accuracyTester() {

    // We will output on pin T
    diagnostic_init_PinT_OutputMode();

    // Wait for low going pulse form timebase on pin B
    while (!diagnostic_in_PinB_Grounded());


    // Reset RTC seconds counter
    rx8900_reset();

    while(1) {

        // Start high
        diagnostic_out_PinT_1();
        sleep_until_next_second();

        // Go low on output
        // Falling edge is what we time to
        diagnostic_out_PinT_0();

    }

}


// From: https://www.mikrocontroller.net/topic/217451

void softwareReset() {
    // ::::::::::::::::::::::::::::::::::::::::::::::::
    // CCP: Configuration Change Protection
    // ::::::::::::::::::::::::::::::::::::::::::::::::
    //for general: ref manual p. 12 (3.12)
    //ref manual p. 13 (3.14.1)
    //CCP - Configuration Change Protection Register
    //IOREG: Protected IO register
    //
    //enabling to write into protectet area
    CCP = CCP_IOREG_gc;
    //All interrupts are ignored during the next 4 CPU
    //instruction cycles from now


    //CTRL bit is protected by Configuration Change Protection
    //Software-Reset ausführen (bit0 setzen)
    //see manual p. 109 (9.5.2: CTRL - Reset Control Register)
    RST.CTRL =  RST_SWRST_bm;

    __builtin_unreachable();
}

// Shows a graph of the FOUT level for a short window after each interrupt.
// 0=low, 1=high. Left to right.

void fout_graph() {

    uint8_t colon_alternator=0;

    while (1) {

        uint8_t levels[12];         // Levels captured right after we wake 11=left (oldest), 0=right (newest)

        sleep_cpu();

        // We are awake!

        // First collect up the values....

        uint8_t s=11;

        do {

            levels[s]= fout_pin_in_value();

            _delay_ms(1);

        } while ( (s--) > 0);

        clearLCD();


       // Now display the collected values

        s=11;

        do {

            digitShow( s , levels[s] );

        } while ( (s--) > 0);


        colon_alternator = !colon_alternator;

        if (colon_alternator) {

            colonLOn();

        } else {

            colonROn();

        }


        // Wait long enough to see it, skip next FOUT transision
        _delay_ms(1500);

    }

    __builtin_unreachable();
}


// Continuously shows the current time
// The right decimal point is on when fout pin is high
// Watch to see if time changes on low-to-high or high-to-low
// RESULTS: Seconds increments on the high-to-low!


void testFOUTpolarity() {
    
    while (1) {
        rx8900_time_regs_block_t now;
        
        rx8900_time_regs_get( &now );
        
        if (fout_pin_in_value()) {
            
            decimalROn();
            } else {
            decimalROff();
        }
        
        showClockTime(&now);
        
    }
    
}


// For testing how long a backup from the interrupt we need to discern an FOUT
// from the RTC from a spontaneously interrupt from static electricity.
// Digit | Meaning
//   6      Seconds counter (driven off FOUT from RTC)
//   5      Glitch counter (interrupts where FOUT was not low)
//   0      reset counter


uint8_t reset_count __attribute__ ((section (".noinit")));
uint24_t seconds  __attribute__ ((section (".noinit")));
uint24_t glitches  __attribute__ ((section (".noinit")));

uint8_t last_fout __attribute__ ((section (".noinit")));


// For testing if static electricity can cause a glitch on the FOUT line.

void fout_glitch_tester() {

    digitShow( 6 , seconds   );
    digitShow( 5 , glitches  );

   // Enable the 1Hz output from the RTC
   //rx8900_fout_1Hz();

   reset_count++;
   if (reset_count>9) reset_count=0;
   digitShow( 0 , reset_count );

    while (1) {

        while (last_fout == fout_pin_in_value()) {

            sleep_cpu();

            if (last_fout== fout_pin_in_value()) {

                glitches++;
                if (glitches==10) glitches=0;

                digitShow( 5 , glitches  );

            }

        }

        last_fout = fout_pin_in_value();

        if (last_fout==0) {     // Falling edge

               seconds++;
               if (seconds==10) seconds=0;
               digitShow( 6 , seconds   );

        }

    }

}


// Update the display until we get to top of next hour...
// when we will be able to kick off the optimized hour long code stepper
// Remember to increment h (and possible d if rollover) on return!

void finish_hour( uint24_t d , uint8_t h, uint8_t m , uint8_t s ) {

    showNowD( d );

    showNowH(h);
        
    uint8_t st = s/10;          // seconds tens place
    uint8_t so = s - (st*10);   // seconds ones place
            
    while (m<60) {
        
        showNowM(m);

        while (st<6) {

            showNowS10s( st );

            while (so<10) {

                showNowS1s( so );
                
                // To avoid incrementing the count on spurious interrupts, we check FOUT
                // level and interlock.

                sleep_until_next_second();

                so++;

            }
            
            so=0;
            st++;

        }       // s

        st=0;
        m++;

    }           // m
        
}    


// Returns when we hit 999999 days 23:59:59 = 2737.90926 years years.
// https://www.google.com/search?q=1000000+days+-+1+second

void run( uint24_t d , uint8_t h) {
       
    while (d<1000000 ) {
        
        // Once per day on rollover to 00 hours...

        // First check for low voltage
        // This takes a lot of power so only do it once every 8 days
        // Starting at the beginning of day 1 when things have started to settle down
        // and we have recovered from the traumatic flashbulb currents
        
        // Take just the low byte of the day count.
        
        uint8_t d_mod_256 = (uint8_t) d;

        if ( (d_mod_256 & 0x07) == 0x01 ) {     // Every 8 days, starting on day0->day1 transition
            if ( check_low_battery() ) {

                // Show blinking battery icon. Never returns.
                low_battery_mode();
                __builtin_unreachable();

            }
        }
        
        // Test with:
        // eeprom-utils-bin\tsl-make-block.exe x.bin  -t 202001010000000 -s 20200507235946

        if ( ( d_mod_256 & 127) == 0x00 ) {     // Every 128 days.... (every 100 days would be more fun, but that would require an expensive divide!)

            clearLCD();
            showc2018JOSH();            // Show copyright egg
                        
            _delay_ms(450);                       // FOUT will be LOW for 500ms, internal oscilator can be +/2% so leave plenty of room. 
            
            // FOUT should still be low here with ~50ms to spare. 
            
            // Note that we can't show for more than 0.5 second because then we would miss entering the optimized loop with FOUT still LOW
            // 0.450 second egg is more modest anyway. Remember I could a put an attention getting sinewave here. Now even if someone does
            // happened to catch it, it will be so short and rare that they will probably think they imagined it.            
            
        }
        

        showNowD( d );
        
        while (h<24) {
            
            // CHeck for diagnostic pins present every hour on the hour
            
            if (diagnostic_in_EitherPin_Grounded()) {        // If either of the diagnostic pins are grounded on the hour...

                softwareReset();                // Reset, which will jump to diagnostic display

            }
                                          
            showNowH(h);                   // Update hour on display    
                                           
            // Run a full hour of counts on hyper low power zombie autopiliot. 
            lcd_optimized_run_hour();
                       
            h++;
        }               // h
                        
        h=0;
        d++;

    }  // d

}



void showPinBPhase1() {

    // Show start time from EEPROM
    // Both `:`'s lit

    rx8900_time_regs_block_t time_start_reg_block;

    colonLOn();

    load_starttime_from_EEPROM( &time_start_reg_block );
    showClockTime( &time_start_reg_block );

}

void showPinBPhase2() {

    // Show trigger time 
    // Right `:` lit
    // Decimal points indicate the Low Voltage flags
        
    if ( load_trigger_flag_from_EEPROM() ) {

        rx8900_time_regs_block_t trigger_time_reg_block;

        load_triggertime_from_EEPROM( &trigger_time_reg_block );

        colonROn();

        showClockTime( &trigger_time_reg_block );

    } else {

        showNoTrig();
    }    
    

}


void showPinBPhase3() {

    // Show the text template so we can fill in the values
    showPinBPhase3Text();

    // Show battery voltage digits on left LCD

    uint8_t vcc = adc_read_vcc_x_10();

    digitOn(  vcc / 10 ,11 );
    digitOn(  vcc % 10 ,10 );

    // Show firmware version digits on right LCD

    digitOn(  (VERSION / 100)       , 2 );
    digitOn(  (VERSION % 100 / 10)  , 1 );
    digitOn(  (VERSION % 10)        , 0 );

}

// Diagnostic display when Pin B is grounded during startup

void showPinT() {
    

    if ( rx8900_low_voltage_check()  ) {
        decimalLOn();
    }

    if ( load_low_voltage_flag_from_EEPROM() != 0x00 ) {
        decimalROn();
    }
    
    rx8900_time_regs_block_t time_now_reg_block;

    rx8900_time_regs_get( &time_now_reg_block );
    showClockTime( &time_now_reg_block );

}

int main(void)
{  

    // Enable the ultra low power XMEGA clock
    // We will drive the LCD from this

    enable_rtc_ulp();

    //enable_rtc_32Kxtal();     // There is provision to install this on the PCB. Saves 0.3uA over ULP. Worth the savings for the extra part?

    disableUnusedIOPins();      // Save a little power by disabling the input buffers on all unused pins

    triggerPinDisable();        // Disable the input buffer on the trigger pin. We will enable (and this disable it) if we actually need it to read the trigger pin.

    USI_TWI_Master_Initialise();        // Init TWI pins to pullup.

    diagnostic_init_Pins();             // Set pullups on the 2 extra pins on the ISP just to keep them from floating. We can also uses these for diagnostics and programming.

    vport_init();                       // Set up all VPORTs. These let us access the trigger pin & FOUT more efificently

    // Set up the ADC registers that we will use for low battery checks
    // This must happen before we shut it down since we can't access registers
    // when it is powered down
    adc_init();
    adc_powerdown_adc_and_ac();

    // Disable all other unused peripherals to save power
    prr_init();
    disableJTAG();

	// Initialize the LCD Controller
	lcd_init();

	// Enable LOW priority interrupts (we only use low)
    CPU_CCP = CCP_IOREG_gc;             // TODO: I think this is not needed?
    PMIC.CTRL |= PMIC_LOLVLEN_bm;

	set_sleep_mode( SLEEP_SMODE_PSAVE_gc );     // Lowest power sleep with LCD

	sleep_enable();         // This chip needs you to tell it that it is ok to sleep before the sleep instruction will actually work

    initFlashBulbs();       // Enable output on the pins that control the transistors that flash the flash LEDs
    
    output1onFOEpin();      // Enable the 1Hz output from the RTC via its Frequency Output Enable pin
                            // Note that this only matters on ver5 PCBs. On ver6, FOUT is connected to the RTC Vcc so it will cut out quicker when battery is pulled. 
    
    
    /* 
        Access wait time
        (After initial power on)
        tCL After VDD=2.5V 30 - - ms
        
    */ 
    
    // Oh man the data sheet sucks here, it specifies the *min* time it can take to settle, rather than the max...
    
   // To be safe, lets wait a full second...

    lcd_optimized_run_sinewave();        // 0.5 sec
    lcd_optimized_run_sinewave();        // 0.5 sec
    
    uint8_t rx8900_low_voltage_flag =0; 
          
    if (rx8900_low_voltage_check()) {
        
        // Save that we saw a low voltage since the initialization below will clear it
        
        rx8900_low_voltage_flag =1;
        
        /*
            If VLF-bit returns “1”, please initialize all registers. Please perform initial setting only tSTA (oscillation start time), when the
            built-in oscillation is stable.
            
            Oscillation start time tSTA
            Ta= +25C, VDD=1.6 V to  5.5 V ,             1.0s Max.
            Ta= -40 to +85C, VDD=1.6 V to 5.5 V,        3.0s Max.
            
        */
        
        // Since VLF is 1, that means that the RTC has lost any data in it and needs to be reset.
        // Furthermore, we must wait for the oscillator to stabilize before we can start updating registers.
        // We take the worst case and wait 3s. We already waited 1 second above for tCL, so 2 more...

        // Delay 2 secs for RX8900 to warm up  (and to show off)
        lcd_optimized_run_sinewave();        // 0.5 sec
        lcd_optimized_run_sinewave();        // 0.5 sec
        lcd_optimized_run_sinewave();        // 0.5 sec
        lcd_optimized_run_sinewave();        // 0.5 sec

                        
    }
    
    // Technically we do not need to initialize unless there was a low voltage, but here we do it every time
    // since it does not mess anything up, and it makes development easier becuase we always now how the registers are set. 
    
    rx8900_initialize();
    
    
    // TODO: Check if version5, open MOS
    
    // OK, we get here, the RX8900 is up and running, MOS closed, 1Hz FOUT


    //showDashes();           // Show "------ ------" on the screen while we wait for the RTC to warm up

    
    FOUT_in_pin_enable();   // Enable an interrupt on the falling edge of the 1Hz FOUT coming from the RTC
                            // Setting a new time sets FOUT low, and then it goes low again on each new seconds update.

    sei();                  // Note that our ISRs are empty, we only use interrupts to wake from sleep.    
    
        
    // Clear the LCD so any upcoming messages will look clean
    clearLCD();
    
    // Diagnostic functions

    while (diagnostic_in_PinB_Grounded()) {

        // Test pin B will show the current time in the RTC - even if it has not been set or reset yet
        // Right colon indicates RTC time
        // Left decimal point means low voltage flag set in RX8900
        // Right decimal point means low voltage flag set in EEPROM (we have seen a low voltage on RX8900 in the past)

        showPinBPhase1();           // Start time
        sleep_until_next_second();

        clearLCD();
        showPinBPhase2();           // Trigger time
        sleep_until_next_second();

        clearLCD();
        showPinBPhase3();
        sleep_until_next_second();

        clearLCD();
    }

//    diagnostic_init_TestPinB_OutputMode();
//    diagnostic_out_PinB_1();

    while (diagnostic_in_PinT_Grounded()) {

        // Test pin T will show the current trigger time - even if it has not been set yet

        showPinT();
        sleep_cpu();
        clearLCD();

    }

    
    /*
    while (1) {
        
        for(uint8_t i=0; i<10;i++) {
            digitShow( 0 , i  );
            sleep_cpu();
        }
        
        };  
    */
    
   
    if ( check_low_battery() ) {

        // Show blinking battery icon. Never returns.
        low_battery_mode();
        __builtin_unreachable();

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


    if ( ! load_start_flag_from_EEPROM() ) {      // We need to set the RTC time.

        // This is our first power up in the factory. We need to init the RTC and set the current time

        /*

        if (load_trigger_flag_from_EEPROM() ) {

            // Hmmm.... We seem to have triggered even though we are in factory startup?
            // This is wonky
            
            // Note that this safety check prevents us from setting the start time and trigger time in the EEPROM at the same time
            // To do that, you must first set the start time and power up, and then set the trigger time after. 

            eepromErrorMode(4);

            __builtin_unreachable();

        }

        */

        showSetCloc();

        /// Set the current time from START_TIME in EEPROM into the RTC timekeeping registers!

        rx8900_time_regs_block_t now;

        load_starttime_from_EEPROM( &now );

        if (!rx8900_time_regs_valid( &now ) ) {

            eepromErrorMode( 7 );

        }

        // This resets us back to the beginning of the current second. This will prevent
        // a time increment update from happening while we are setting the new time.
        // Necessary? Unclear from datasheets.

        rx8900_reset();

        rx8900_time_regs_set( &now );

        // Empirically determined that setting the time also resets the seconds phase and the FOUT phase to LOW

        rx8900_set_magic();     // As a backup plan, also store our secret magic in the unused alarm registers
                                // so we can check later. Currently unused.

        // Mark that we used the start_time so we don't try to reuse it
        save_start_flag_to_EEPROM();

        // Wait for the EEPROM write to complete
        // If we do not do this and just reset, the the write does not work!
        eeprom_busy_wait();

        // Now we do a software reset on the XMEGA. This will start us again with a clean slate and read back the time from the
        // RX8900 and do the normal validity checks and low voltage flag checks. We do this to Fail fast during the programming rather than
        // discovering the problem decades later at the first battery change.

        softwareReset();

        __builtin_unreachable();

    } // if (load_start_flag_from_EEPROM() == 0x00 )


    // Did we see the low voltage flag set when we powered up?

    if ( rx8900_low_voltage_flag ) {

        // Permanently remember this since we now do not know what time it is ever again
        save_low_voltage_flag_to_EEPROM();

        // Wait for save to complete
        eeprom_busy_wait();

        // Don't bother clearing the low voltage because the time is gone forever (or until
        // reset at factory) so nothing we can do about it now

    }
    
    // Have we ever had a low voltage condition?

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

        // We have triggered in the past. They just changed the battery.

        // Load the trigger_time from EEPROM

        load_triggertime_from_EEPROM( &time_trigger_reg_block );

        if (!rx8900_time_regs_valid( &time_trigger_reg_block ) ) {

            eepromErrorMode( 8 );

        }
                                              
        // Fall though to normal run mode below...

    } else {

        // We are trigger virgins!

        // Before we continue to "Ready to Launch mode", we need the pin to be in so that it can be pulled out.
        // Show RTC clock time a long as pin is out for double check that it got set right and is running.

        rx8900_time_regs_block_t now;

        uint8_t blink_toggle;

        triggerPinEnable();                 // Enable the pull-up, input buffer, and the interrupt
                                            // The interrupt wakes us from sleep the moment the pin is pulled
                                            // so there is not a lag until the next second.

        while ( !triggerPinPresent() ) {

            // Blink the colons at 2Hz to indicate clock mode

            blink_toggle = !blink_toggle;

            if ( blink_toggle ) {

                colonLOn();
                colonROn();

            }

            // Here we use just pain sleep_cpu() rather than
            // wait_until_next_second() so that we will react to the
            // trigger pin insertion immediately.

            rx8900_time_regs_get( &now );
            showClockTime( &now );
            sleep_cpu();

            colonLOff();
            colonROff();

        }

        _delay_ms(100);         // Debounce the trigger pin being inserted so we don't prematurely fire

        // if we get here, we know we have never been triggered and the pin is armed and ready

        // "Ready to Launch mode"


        // Show a nice pattern until the pin is pulled that shows we are ready

        // Show the optimized ready mode figure 8 pattern. This will return when trigger pin is pulled. 
        lcd_optimized_run_ready();
        
        // Trigger pin pulled! SHOWTIME, PEOPLE!

        // Clear the display for instant feed back!

        clearLCD();

        // Align the RTC second boundary to NOW so it is in phase with when the pin was pulled.

        // This resets us back to the beginning of the current second
        // so we can drop any fractional second since we have no good way to measure that
        // Sure our real time will be off by up to 1 second forevermore, but worth it to have the count
        // start on an even second boundary so that the first 0->1 transistion happens 1 full second
        // after the trigger is pulled.

        // Alternately we could wait for next forward second update, but the user pulled the trigger and they
        // might be waiting up to a second for the show to begin... and that is no fun!

        /*
            Next update timing of a Seconds counter from RESET.
            That range is 1000ms-30.5?s from just 1000ms.
            RESET affects to time update interruption, alarm, and timer.
        */

        rx8900_reset();


        // Put a fake "000000 000000" on the display
        // until we are done flashing and are able to
        // start the real count.

        showZeros();

        // Grab the current time from RTC!

        rx8900_time_regs_get( &time_trigger_reg_block );

        // Save the triggered time to EEPROM!

        save_triggertime_to_EEPROM( &time_trigger_reg_block );    // Save the time we triggered forever
        eeprom_busy_wait();                             // Wait for save to complete just to be safe.
        
        save_trigger_flag_to_EEPROM();                 // Set the flag so we know that trigger_time in EEPROM is valid
        eeprom_busy_wait();                             // Wait for save to complete just to be safe.

        // Disable trigger pin - we do not need it ever again!
        // We disable it also to prevent any spurious interrupts coming from the
        // pin bouncing that could delay us or trigger extra counts.

        triggerPinDisable();                        // Disable interrupt, pull-up, and input buffer to save power
                                                    // Really important because the pull-up would be shorted to ground anytime the pin was back in
                                                    // and the input buffer is going to float without a pull-up.

        // When we get here, the only active interrupt source should be the
        // 1Hz from the RTC


        // Flash bulb party!!!

        flash();

        // Note that it is important that this complete within 1 second of the pull
        // or we will miss a second in our count this pass (it would come back on next battery change)
        // This deadline is no problem with current flash pattern.

        // Coming out of this the LCD is clear, count should be 0, and we are less than 1 second
        // into the current second.

    } 
    
    
    // If we get here because of a trigger pull, then we are pretty far into the current second. If we are more than half way
    // then we don't want to enter the optimized hour loop since that needs us to be at the beginning of the 1st second.
    // In that case, we want to wait until the beginning of the next second. We will then compute that the display should say "000000 000001"
    // and will jump into the non-optimized version for the first hour. 
    
    // If we get here because of a battery change, then we have no idea where we are in the current second. So we
    // will wait until the next second so we know we will be at the top of the second and it will not change while we are working.
    // This does mean that the user might see a blank display for up to 1 second after putting in the new battery, but that's ok. 
    // The calculation below will be right since it grabs the clock time after the wait is over. 
    
    sleep_until_next_second();

    rx8900_time_regs_block_t time_now_reg_block;
    rx8900_time_regs_get_and_update_century_interlock( &time_now_reg_block );       // This will the century interlock and save back to EEPROM if necessary

    time_count_t time_now;
    rx8900_time_regs_to_count( &time_now , &time_now_reg_block );

    time_count_t time_trigger;
    rx8900_time_regs_to_count( &time_trigger , &time_trigger_reg_block );

    // Now we have to figure out what the display count looks like by subtracting the
    // time_trigger from the time_now to get the time_since_lanuch

    // Time Since Launch = time now - trigger time
      
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
    
    // If we just started after a battery replacement, then hour and second might not be 0
    // so here we run out the current hour to get a nice even 00:00 transition so the hyperoptimized
    // code in run can take over.
    
    // Note that this does run for the first hour after you pull the trigger since the flash takes 
    // more than 0.5 second so by the time we get here it is 000000 000001. 
    // I had a whole fancy system to jump into a sequence midstep, but not enough memory for it
    // so we have to be OK with a little extra power drain for the first hour of our long life. 
    
    // TODO: When we get new PCB rev that resolves the spurious FOUT triggers, then we can switch to 
    // only interrupt once per second and get rid of the interlock
    
    // Note this will run except in the 1/3600 case where the person change the battery and we happened to wake up at exactly a new hour.
    // Oh well, code is free and if it happens once then that person will get an extra second or two of battery life for free!
    
    if ( time_since_lanuch.m != 0 || time_since_lanuch.s != 0 ) {
                
        // Finishhour() runs until the next hour clicks. Note that it does not update any of the values. This is OK because
        // we KNOW that m and s will be 0 at the top of the hour, and we know that it will be one hour later.                 
        finish_hour( time_since_lanuch.d , time_since_lanuch.h , time_since_lanuch.m , time_since_lanuch.s );
               
        // Reflect the hour transition that just happened to get us here (we don't get here until the previous hour is over)
        time_since_lanuch.h++;
        
        // Day happen to roll?
        if ( time_since_lanuch.h >=24 ) {
            time_since_lanuch.h=0;
            time_since_lanuch.d ++;            
            // run() will catch if d overflowed into long now mode
        }            

        // Here we know that we are at the top of an hour (m=s=0) and ready for run()        
        
    }    
            
    // Enter the long optimized run. Returns on day 1000000. 
    // Note that you can only enter the optimized at the top of the hour
    
    run( time_since_lanuch.d , time_since_lanuch.h );

    // If we get here, then we have been running continuously for 1 million days.
    // TODO: Have the unit use its recently evolved sentience to add an additional digit to the days display.

    longNowMode();

    __builtin_unreachable();
}
