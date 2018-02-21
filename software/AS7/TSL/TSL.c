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
	LCD.CTRLA = LCD_CLRDT_bm; //0x04
	//////////////////////////////////////////////////////////////////////
	
	
	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLB
	//     7        6       5       4        3       2       1      0
	// | PRESC |       CLKDIV[2:0]       | LPWAV |   -   |   DUTY[1:0]   |
	//     0        0       0       0        0       0       0      0
	// Frame Rate set to 64 Hz
	// LP Wave Enabled
	// 1/4 Duty, 1/3 Bias, COM[0:3] used
	LCD.CTRLB = LCD_PRESC_bm | LCD_CLKDIV1_bm | LCD_CLKDIV0_bm | LCD_LPWAV_bm; //0xB8
	//////////////////////////////////////////////////////////////////////
	
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
	LCD.INTCTRL = LCD_XIME2_bm | LCD_XIME1_bm | LCD_XIME0_bm | LCD_FCINTLVL_gm; // 0x3B sets interrupt period to 16 frames with high priority
	//////////////////////////////////////////////////////////////////////
	
	
	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLD
	//     7       6       5       4        3        2       1       0
	// |   -   |   -   |   -   |   -   | BLINKEN |   -   | BLINKRATE[1:0] |
	//     0       0       0        0       0        0       0       0
	// Disable hardware blinking
	LCD.CTRLD = ~LCD_BLINKEN_bm; // 0x00
	//////////////////////////////////////////////////////////////////////
	
	
	//////////////////////////////////////////////////////////////////////
	//LCD.CTRLA
	//     7        6       5        4        3        2       1       0
	// | ENABLE | XBIAS | DATCLK | COMSWP | SEGSWP | CLRDT | SEGON | BLANK|
	//     0        0       0        0        0        0       0       0
	// Enable LCD
	// Enable all LCD segments
	LCD.CTRLA |= LCD_ENABLE_bm | LCD_SEGON_bm; // 0x82
	//////////////////////////////////////////////////////////////////////
	
	// set LCD contrast with signed int value between -32 ~ 31
	// -32 corresponds to a segment voltage of approx 2.5V
	//   0 corresponds to a segment voltage of approx 3.0V
	//  31 corresponds to a segment voltage of approx 3.5V
	// Default is 0 (3.0V)
	LCD.CTRLF = 31;
}

//  Disable unused peripherals to save power

void prr_init() {
    
    // Disable everything but the LCD & RTC
    
    // TODO: DO we need to RTC? I think we have to track it ourselves anyway and increment off the LCD interrupt
    
    PR.PRGEN = PR_USB_bm | PR_AES_bm | PR_EVSYS_bm | PR_DMA_bm;   
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
	

    // TODO: These are just for debug output. Get rid of them. 
	PORTC.DIR = 0xff;
	PORTC.OUT = 0xff;
	
    // Enable the ultra low power RTC clock
    // We will drive the LCD from this
	enable_rtc();           
	
	// Configure Interrupt Priority Level and Location of Vectors
	pmic_init();
	
	// Enable change to protected IO reg
	//CCP = 0xD8; 
	// TODO: Disable JTAG for lower power
	//MCU_MCUCR = MCU_JTAGD_bm; 
		
	
	// Initialize the LCD Controller
	lcd_init();
	
	// Enable interrupts
	sei();
	
	// Turn off backlight
	//lcd_backlight_off();
	
	// Turn on AVR Icon

	//lcd_set_pixel(ICON_AVR);

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

	
	while (1) {
		
		//PORTC.OUTTGL = 0xff;
				
		// Clear the display memory
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04				
		LCD.DATA0=0xff;
		
		sleep_cpu();
		
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04		
		LCD.DATA1=0xff;
		
		sleep_cpu();

		LCD.CTRLA |= LCD_CLRDT_bm; //0x04		
		LCD.DATA2=0xff;
		
		sleep_cpu();
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04		
		LCD.DATA3=0xff;
		
		sleep_cpu();
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		
		LCD.DATA4=0xff;
		
		sleep_cpu();
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA5=0xff;

		sleep_cpu();
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA6=0xff;


		sleep_cpu();
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA7=0xff;
        
		sleep_cpu();
		LCD.CTRLA |= LCD_CLRDT_bm; //0x04
		LCD.DATA8=0xff;

		
		PORTC.OUTTGL = 0xff;
	
	
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
ISR(LCD_INT_vect)
{
		//PORTC.OUTTGL = 0xff;
	
	/*
	static uint8_t step=0;
	
	switch(step) {

	// Turn on each Bar segment
		case 0: lcd_set_pixel(ICON_LEVEL_1); lcd_clear_pixel(ICON_LEVEL_2); break;
		case 1: lcd_set_pixel(ICON_LEVEL_2); lcd_clear_pixel(ICON_LEVEL_3); break;		
		case 2: lcd_set_pixel(ICON_LEVEL_3); lcd_clear_pixel(ICON_LEVEL_4); break;
		case 3: lcd_set_pixel(ICON_LEVEL_4); lcd_clear_pixel(ICON_LEVEL_5); break;
		case 4: lcd_set_pixel(ICON_LEVEL_5); lcd_clear_pixel(ICON_LEVEL_1); break;
	}
	
	step++;
	
	if (step==5) step=0;
	*/
	
	
}

void sysclk_init(void) {
	
	// Assume operation from internal RC oscillator (2 MHz)
	
	// Assign pointer to Power Reduction Register
	uint8_t *reg = (uint8_t *)&PR.PRGEN;
	uint8_t i;
	
	// Turn off all peripheral clocks (initially) to conserve power
	for (i = 0; i <= 6; i++) {
		*(reg++) = 0xFF;
	}
	
	//////////////////////////////////////////////////////////////////////
	//OSC.PLLCTRL
	//     7       6       5       4       3        2        1        0
	// |  PLLSRC[1:0]  | PLLDIV |              PLLFAC[4:0]                 |
	//     0       0       0       0       0        0        0        0
	// Set 2MHz Internal RC Osc as PLL source
	// Set PLL to 16MHz
	//OSC.PLLCTRL = OSC_PLLSRC_RC2M_gc | OSC_PLLFAC3_bm; // 0x08
	//////////////////////////////////////////////////////////////////////
	 
	//////////////////////////////////////////////////////////////////////
	//OSC.CTRL
	//     7       6       5       4        3        2         1        0
	// |   -   |   -   |   -   | PLLEN | XOSCEN | RC32KEN | RC32MEN | RC2MEN |
	//     0       0       0       0        0        0         0        0
	// Enable PLL
	// Clock Source and Multiplication Factor must be selected in PLLCTRL
	// before setting this bit.
	//OSC.CTRL |= OSC_PLLEN_bm; // 0x10
	////////////////////////////////////////////////////////////////////// 
	
	//////////////////////////////////////////////////////////////////////
	//OSC.STATUS
	//     7       6       5        4        3         2          1          0
	// |   -   |   -   |   -   | PLLRDY | XOSCRDY | RC32KRDY | RC32MRDY | RC2MRDY |
	//     0       0       0        0        0         0          0          0
	// Wait for PLL to stabilize
	//while (0 == (OSC.STATUS & OSC_PLLRDY_bm)); // wait for STATUS reg to read 0x10
	////////////////////////////////////////////////////////////////////// 
	
	//////////////////////////////////////////////////////////////////////
	//CLK.PSCTRL
	//     7       6       5       4       3       2       1       0
	// |   -   |               PSADIV[4:0]             |    PSBCDIV    |
	//     0       0       0       0       0       0       0       0
	// Enable change on protected I/O reg
	//CONFIGURATION_CHANGE_PROTECTION;
	// Set Clk_per4 equal to 8 MHz
	//CLK.PSCTRL = CLK_PSADIV0_bm; // 0x04
	// Leaving CLK_PSBCDIV[1:0] with default value (b'00') sets
	// Clk_per2, Clk_per, and Clk_cpu equal to Clk_per4 (8 MHz)
	//////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////
	//CLK.CTRL
	//     7       6       5       4       3       2       1       0
	// |   -   |   -   |   -   |   -   |   -   |      SCLKSEL[2:0]    |
	//     0       0       0       0       0       0       0       0
	// Enable change on protected I/O reg
	//CONFIGURATION_CHANGE_PROTECTION;
	// Set PLL as sys clk source
	//CLK.CTRL = CLK_SCLKSEL2_bm; // 0x04
	//////////////////////////////////////////////////////////////////////
	
} 



void board_init(void) {
	
	// LED Pins set to Outputs
	// Sensor Pins set to Inputs
	//PORTB.DIR = 0xF0;
	//PORTB.OUTSET = 0xF0; //4 LEDs Off
	
	// QTouch button pins, LCD Backlight pin,
	// and Power LED pin set to output 
	// (QTouch buttons will not work in this configuration)
	//PORTE.DIR = 0xFF;
	//PORTE.OUTSET = 0xFF; //Power LED On, LCD Backlight On
}

