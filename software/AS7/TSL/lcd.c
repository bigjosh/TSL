/*
 * LCD.c
 *
 * Created: 1/12/2018 5:16:42 PM
 *  Author: josh
 */

// Required AVR Libraries
#include <avr/io.h>

#include "lcd.h"


//---------------CUT HERE FOR SEG MAP PRINTOUT

// The code between the cut points can be run to print a map of which
// registers are used for which digits using printRegMap()

// You will need these to make this block compile independently...
// #include <stdint.h>
// typedef uint8_t register8_t;

// Maximum number of common lines.
#define LCD_MAX_NBR_OF_COM  4
// Maximum number of segment lines.
#define LCD_MAX_NBR_OF_SEG  25

// Map LCD segments to registers
// compute at compile time
// Taken from 25.5.11 DATA – LCD Data Memory Mapping

// Return the offset of the register that holds the requested pixel

inline static uint8_t LCD_REG_OFF( uint8_t com , uint8_t seg ) {
    
    uint8_t reg = ( com * ((LCD_MAX_NBR_OF_SEG + 7) / 8)) + ( seg / 8);
    
    return reg;
}


// LCD FONT----

// Map 7 segments A-G to internal representation bits
// A=0b00000001, B=0b00000010, etc
// Just luck that 7 segments fits into an 8 bit byte

#define LCD_SEG_BIT( letter ) ( 1 << (letter - 'A') )

#define SEG_A LCD_SEG_BIT('A')
#define SEG_B LCD_SEG_BIT('B')
#define SEG_C LCD_SEG_BIT('C')
#define SEG_D LCD_SEG_BIT('D')
#define SEG_E LCD_SEG_BIT('E')
#define SEG_F LCD_SEG_BIT('F')
#define SEG_G LCD_SEG_BIT('G')


const uint8_t lcd_font_digits[] = {
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F ,         // 0
    SEG_E | SEG_F ,                                         // 1
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_D ,                 // 2
    SEG_A | SEG_F | SEG_G | SEG_E | SEG_D ,                 // 3
    SEG_F | SEG_G | SEG_E | SEG_C ,                         // 4
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D ,                 // 5
    SEG_A | SEG_C | SEG_D | SEG_B | SEG_F | SEG_G ,         // 6
    SEG_D | SEG_E | SEG_F ,                                 // 7
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G , // 8
    SEG_A | SEG_E | SEG_C | SEG_D | SEG_F | SEG_G ,         // 9
};


const uint8_t lcd_font_char_dash = { SEG_G };                                 // '-'
const uint8_t lcd_font_char_c    = { SEG_G | SEG_B | SEG_A };                 // c
const uint8_t lcd_font_char_L    = { SEG_C | SEG_B | SEG_A };                 // L
const uint8_t lcd_font_char_o    = { SEG_G | SEG_B | SEG_A | SEG_F };         // o
const uint8_t lcd_font_char_E    = { SEG_D | SEG_C | SEG_G | SEG_B | SEG_A }; // E
const uint8_t lcd_font_char_r    = { SEG_B | SEG_G };                         // r
const uint8_t lcd_font_char_P    = { SEG_E | SEG_D | SEG_C | SEG_G | SEG_B }; // P

const uint8_t lcd_font_char_J    = { SEG_B | SEG_A | SEG_F | SEG_F | SEG_E }; // J
const uint8_t lcd_font_char_O    = { SEG_D | SEG_C | SEG_B | SEG_A | SEG_F | SEG_E }; // O
const uint8_t lcd_font_char_S    = { SEG_D | SEG_C | SEG_G | SEG_F | SEG_A }; // S
const uint8_t lcd_font_char_H    = { SEG_B | SEG_C | SEG_F | SEG_G | SEG_E }; // H

const uint8_t lcd_font_char_n    = { SEG_B | SEG_G | SEG_F };                 // n
const uint8_t lcd_font_char_t    = { SEG_B | SEG_C | SEG_A | SEG_G };         // t
const uint8_t lcd_font_char_i    = { SEG_B };                                 // i
const uint8_t lcd_font_char_G    = { SEG_D | SEG_C | SEG_B | SEG_A | SEG_F  }; // G

const uint8_t lcd_font_char_V    = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_E }; // V (ok, not really)
const uint8_t lcd_font_char_l    = { SEG_C | SEG_B };                         // l

const uint8_t lcd_font_char_b    = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_G }; // b
const uint8_t lcd_font_char_A    = { SEG_C | SEG_B | SEG_D | SEG_E | SEG_G | SEG_F };   // A
const uint8_t lcd_font_char_d    = { SEG_G | SEG_B | SEG_A | SEG_F | SEG_E};  // d
const uint8_t lcd_font_char_U    = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_E};  // d


// Map LCD seg pins to MCU seg pins (set by PCB layout)

#define LCD_SEG_R01 24
#define LCD_SEG_R02 23
#define LCD_SEG_R03 22
#define LCD_SEG_R04 21
#define LCD_SEG_R05 20
#define LCD_SEG_R06 19
#define LCD_SEG_R07 18
#define LCD_SEG_R08 17
#define LCD_SEG_R09 16
#define LCD_SEG_R10 15
#define LCD_SEG_R11 14
#define LCD_SEG_R12 13
#define LCD_SEG_R13 12


#define LCD_SEG_L01 24
#define LCD_SEG_L02 11
#define LCD_SEG_L03 10
#define LCD_SEG_L04  9
#define LCD_SEG_L05  8
#define LCD_SEG_L06  7
#define LCD_SEG_L07  6
#define LCD_SEG_L08  5
#define LCD_SEG_L09  4
#define LCD_SEG_L10  3
#define LCD_SEG_L11  2
#define LCD_SEG_L12  1
#define LCD_SEG_L13  0


// Map LCD COM pins to MCU com pins (set by PCB layout)

#define LCD_COM_R1 0
#define LCD_COM_R2 1
#define LCD_COM_R3 2
#define LCD_COM_R4 3

#define LCD_COM_L1 0
#define LCD_COM_L2 1
#define LCD_COM_L3 2
#define LCD_COM_L4 3



// Map LCD icons to seg/com (set by LCD datasheet)

// Map each of the 7 visible LCD icons A-G in each of the 6 digits per LCD

typedef struct {
    uint8_t com;
    uint8_t seg;
} lcd_visible_segment ;

// TODO: PROGMEM and then statically compiled transitions

// Maps segments in each digit to corresponding SEG and COM pin
// 0=rightmost digit, 11=leftmost

const lcd_visible_segment  digitmap[][7] = {

    // Right LCD

    {     //1 on the datasheet= 0 in digitmap array
        {LCD_COM_R1 , LCD_SEG_R03 },       //A
        {LCD_COM_R2 , LCD_SEG_R03 },       //B
        {LCD_COM_R3 , LCD_SEG_R03 },       //C
        {LCD_COM_R4 , LCD_SEG_R02 },       //D
        {LCD_COM_R3 , LCD_SEG_R02 },       //E
        {LCD_COM_R1 , LCD_SEG_R02 },       //F
        {LCD_COM_R2 , LCD_SEG_R02 },       //G
    },

    {     //2
        {LCD_COM_R1 , LCD_SEG_R05 },       //A
        {LCD_COM_R2 , LCD_SEG_R05 },       //B
        {LCD_COM_R3 , LCD_SEG_R05 },       //C
        {LCD_COM_R4 , LCD_SEG_R04 },       //D
        {LCD_COM_R3 , LCD_SEG_R04 },       //E
        {LCD_COM_R1 , LCD_SEG_R04 },       //F
        {LCD_COM_R2 , LCD_SEG_R04 },       //G
    },

    {     //3
        {LCD_COM_R1 , LCD_SEG_R07 },       //A
        {LCD_COM_R2 , LCD_SEG_R07 },       //B
        {LCD_COM_R3 , LCD_SEG_R07 },       //C
        {LCD_COM_R4 , LCD_SEG_R06 },       //D
        {LCD_COM_R3 , LCD_SEG_R06 },       //E
        {LCD_COM_R1 , LCD_SEG_R06 },       //F
        {LCD_COM_R2 , LCD_SEG_R06 },       //G
    },

    {     //4
        {LCD_COM_R1 , LCD_SEG_R09 },       //A
        {LCD_COM_R2 , LCD_SEG_R09 },       //B
        {LCD_COM_R3 , LCD_SEG_R09 },       //C
        {LCD_COM_R4 , LCD_SEG_R08 },       //D
        {LCD_COM_R3 , LCD_SEG_R08 },       //E
        {LCD_COM_R1 , LCD_SEG_R08 },       //F
        {LCD_COM_R2 , LCD_SEG_R08 },       //G
    },

    {     //5
        {LCD_COM_R1 , LCD_SEG_R11 },       //A
        {LCD_COM_R2 , LCD_SEG_R11 },       //B
        {LCD_COM_R3 , LCD_SEG_R11 },       //C
        {LCD_COM_R4 , LCD_SEG_R10 },       //D
        {LCD_COM_R3 , LCD_SEG_R10 },       //E
        {LCD_COM_R1 , LCD_SEG_R10 },       //F
        {LCD_COM_R2 , LCD_SEG_R10 },       //G
    },

    {     //6
        {LCD_COM_R1 , LCD_SEG_R13 },       //A
        {LCD_COM_R2 , LCD_SEG_R13 },       //B
        {LCD_COM_R3 , LCD_SEG_R13 },       //C
        {LCD_COM_R4 , LCD_SEG_R12 },       //D
        {LCD_COM_R3 , LCD_SEG_R12 },       //E
        {LCD_COM_R1 , LCD_SEG_R12 },       //F
        {LCD_COM_R2 , LCD_SEG_R12 },       //G
    },

    // Left LCD

    {     //1 on the datasheet= 0 in digitmap array
        {LCD_COM_L1 , LCD_SEG_L03 },       //A
        {LCD_COM_L2 , LCD_SEG_L03 },       //B
        {LCD_COM_L3 , LCD_SEG_L03 },       //C
        {LCD_COM_L4 , LCD_SEG_L02 },       //D
        {LCD_COM_L3 , LCD_SEG_L02 },       //E
        {LCD_COM_L1 , LCD_SEG_L02 },       //F
        {LCD_COM_L2 , LCD_SEG_L02 },       //G
    },

    {     //2
        {LCD_COM_L1 , LCD_SEG_L05 },       //A
        {LCD_COM_L2 , LCD_SEG_L05 },       //B
        {LCD_COM_L3 , LCD_SEG_L05 },       //C
        {LCD_COM_L4 , LCD_SEG_L04 },       //D
        {LCD_COM_L3 , LCD_SEG_L04 },       //E
        {LCD_COM_L1 , LCD_SEG_L04 },       //F
        {LCD_COM_L2 , LCD_SEG_L04 },       //G
    },

    {     //3
        {LCD_COM_L1 , LCD_SEG_L07 },       //A
        {LCD_COM_L2 , LCD_SEG_L07 },       //B
        {LCD_COM_L3 , LCD_SEG_L07 },       //C
        {LCD_COM_L4 , LCD_SEG_L06 },       //D
        {LCD_COM_L3 , LCD_SEG_L06 },       //E
        {LCD_COM_L1 , LCD_SEG_L06 },       //F
        {LCD_COM_L2 , LCD_SEG_L06 },       //G
    },

    {     //4
        {LCD_COM_L1 , LCD_SEG_L09 },       //A
        {LCD_COM_L2 , LCD_SEG_L09 },       //B
        {LCD_COM_L3 , LCD_SEG_L09 },       //C
        {LCD_COM_L4 , LCD_SEG_L08 },       //D
        {LCD_COM_L3 , LCD_SEG_L08 },       //E
        {LCD_COM_L1 , LCD_SEG_L08 },       //F
        {LCD_COM_L2 , LCD_SEG_L08 },       //G
    },

    {     //5
        {LCD_COM_L1 , LCD_SEG_L11 },       //A
        {LCD_COM_L2 , LCD_SEG_L11 },       //B
        {LCD_COM_L3 , LCD_SEG_L11 },       //C
        {LCD_COM_L4 , LCD_SEG_L10 },       //D
        {LCD_COM_L3 , LCD_SEG_L10 },       //E
        {LCD_COM_L1 , LCD_SEG_L10 },       //F
        {LCD_COM_L2 , LCD_SEG_L10 },       //G
    },

    {     //6
        {LCD_COM_L1 , LCD_SEG_L13 },       //A
        {LCD_COM_L2 , LCD_SEG_L13 },       //B
        {LCD_COM_L3 , LCD_SEG_L13 },       //C
        {LCD_COM_L4 , LCD_SEG_L12 },       //D
        {LCD_COM_L3 , LCD_SEG_L12 },       //E
        {LCD_COM_L1 , LCD_SEG_L12 },       //F
        {LCD_COM_L2 , LCD_SEG_L12 },       //G
    },



};


#include <stdio.h>

// Total number of LCD registers
#define LCD_REG_COUNT (((LCD_MAX_NBR_OF_SEG + 7)/8)*LCD_MAX_NBR_OF_COM)

// For each of the LCD data regs, put an X if any pixel of the digit touches that reg
// Good for getting a view of which digits impact other digits when updating


void printLcdMap() {
    
    // Step though each register, listing them vertically down the page

    printf("### LCD register usage by digit map\r\n");

    // Print table header

    printf("\r\n| Reg  | ");

    for( uint8_t dc=0; dc<12;dc++ ) {
        // Digit #11 is the leftmost on the display
        
        uint8_t d= 11-dc;
        printf("%0.02d | " , d );

    }


    printf("\r\n| ---  | ");

    for( uint8_t dc=0; dc<12;dc++ ) {
        // Digit #11 is the leftmost on the display
        
        uint8_t d= 11-dc;
        printf("-- | " );

    }


    // Print rows
    
    for( uint8_t reg = 0; reg <= LCD_REG_COUNT ; reg++ ) {
        
        printf( "\r\n| [%2.2d] |" , reg );
        
        
        // Step though each of the 12 digits, listing them horizontally across the page
        
        
        for( uint8_t dc=0; dc<12;dc++ ) {
            
            
            // Digit #11 is the leftmost on the display
            
            uint8_t d= 11-dc;
            
            // step though the pixels in this digit to see if current register is used.
            
            // Note that a register can be used multiple times by the same digit, be we only care if it is used at all
            uint8_t reg_used_flag = 0;
            
            for( uint8_t p=0; p<8;p++ ) {
                
                const lcd_visible_segment current_pixel = digitmap[d][p];
                
                if ( reg == LCD_REG_OFF( current_pixel.com , current_pixel.seg )  ) {
                    
                    reg_used_flag = 1 ;
                    
                }
                
            }
            
            printf( "  %c |" , reg_used_flag ? 'X' : ' ');
            
        }
        
    }
    
}



// For each of the LCD data regs, put an X if any pixel of the digit touches that reg
// Good for getting a view of which digits impact other digits when updating

void printLcdLocationMap() {
    
    // Step though each pixel in each digit and show which register it is in

    printf("\r\n\r\n### LCD register by pixel map (register:bit)\r\n");

    // Print table header

    printf("\r\n| Digit | A | B | C | D | E | F |\r\n");
    printf("| - | - | - | - | - | - | - |\r\n");

    // Print rows
    
    // Step though each of the 12 digits, listing them horizontally across the page
    
    
    for( uint8_t dc=0; dc<12;dc++ ) {
        
        
        // Digit #11 is the leftmost on the display
        
        uint8_t d= 11-dc;
        
        printf("| %0.02d | " , d );
        
        // step though the pixels in this digit and print the register used (A-F = 7 pixels)
        
        for( uint8_t p=0; p<8;p++ ) {
            
            const lcd_visible_segment current_pixel = digitmap[d][p];
            
            printf( " %02.2d:%1.1d |"  , LCD_REG_OFF( current_pixel.com , current_pixel.seg ) ,  current_pixel.seg % 8 );
            
        }
        
        printf( "\r\n");
        
    }
    
}

//---------------- END CUT


// This function is used to turn on individual icons on the display.
inline void lcd_set_pixel(uint8_t pix_com, uint8_t pix_seg) {
    register8_t *pixreg = (register8_t *)((uint16_t)&LCD.DATA0)
    + (pix_com * ((LCD_MAX_NBR_OF_SEG + 7) / 8))
    + (pix_seg / 8);

    *pixreg |= 1 << (pix_seg % 8);
}

// This function is used to turn off individual icons on the display.
inline void lcd_clear_pixel(uint8_t pix_com, uint8_t pix_seg) {
    register8_t *pixreg = (register8_t *)((uint16_t)&LCD.DATA0)
    + (pix_com * ((LCD_MAX_NBR_OF_SEG + 7) / 8))
    + (pix_seg / 8);

    *pixreg &= ~(1 << (pix_seg % 8));
}



void digitShow( uint8_t d,  uint8_t n ) {

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );

        } else {

            lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );

        }
    }
}


void digitOn(  uint8_t n , uint8_t d ) {

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );

        }
    }
}


void segmentsOn( uint8_t segementBitsInThisDigit,  uint8_t d ) {


    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );

        }
    }
}

void showDash(uint8_t n ) {

    segmentsOn( lcd_font_char_dash , n );

}

void lcd_show_fontchar( uint8_t segs , uint8_t d ) {
    segmentsOn( segs , d );
}

void showNoTrig() {
    segmentsOn( lcd_font_char_n , 11 );
    segmentsOn( lcd_font_char_o , 10 );

    segmentsOn( lcd_font_char_t , 5 );
    segmentsOn( lcd_font_char_r , 4 );
    segmentsOn( lcd_font_char_i , 3 );
    segmentsOn( lcd_font_char_G , 2 );


}

void showClocError() {
    segmentsOn( lcd_font_char_c , 11 );
    segmentsOn( lcd_font_char_L , 10 );
    segmentsOn( lcd_font_char_o ,  9 );
    segmentsOn( lcd_font_char_c ,  8 );

    segmentsOn( lcd_font_char_E , 5 );
    segmentsOn( lcd_font_char_r , 4 );
    segmentsOn( lcd_font_char_r , 3 );
    segmentsOn( lcd_font_char_o , 2 );
    segmentsOn( lcd_font_char_r , 1 );
}

void showSetCloc() {

    segmentsOn( lcd_font_char_S , 11 );
    segmentsOn( lcd_font_char_E , 10 );
    segmentsOn( lcd_font_char_t ,  9 );


    segmentsOn( lcd_font_char_c ,  5 );
    segmentsOn( lcd_font_char_L ,  4 );
    segmentsOn( lcd_font_char_o ,  3 );
    segmentsOn( lcd_font_char_c ,  2 );

}

void showReset() {

    segmentsOn( lcd_font_char_r , 11 );
    segmentsOn( lcd_font_char_E , 10 );
    segmentsOn( lcd_font_char_S ,  9 );
    segmentsOn( lcd_font_char_E ,  8 );
    segmentsOn( lcd_font_char_t ,  7 );

}



void showbAdint() {
    segmentsOn( lcd_font_char_b , 11 );
    segmentsOn( lcd_font_char_A , 10 );
    segmentsOn( lcd_font_char_d ,  9 );

    segmentsOn( lcd_font_char_i , 5 );
    segmentsOn( lcd_font_char_n , 4 );
    segmentsOn( lcd_font_char_t , 3 );
}


void showEEProError( uint8_t code ) {
    segmentsOn( lcd_font_char_E , 11 );
    segmentsOn( lcd_font_char_E , 10 );
    segmentsOn( lcd_font_char_P ,  9 );
    segmentsOn( lcd_font_char_r ,  8 );
    segmentsOn( lcd_font_char_o ,  7 );

    segmentsOn( lcd_font_char_E , 5 );
    segmentsOn( lcd_font_char_r , 4 );
    segmentsOn( lcd_font_char_r , 3 );
    segmentsOn( lcd_font_char_o , 2 );
    segmentsOn( lcd_font_char_r , 1 );
    digitOn(  code , 0 );

}

// The text part of the Pin B Phase 1 diagnostics display
// (space left for numbers to be filled in)

void showPinBPhase3Text() {

    // Show "VOLT" on left LCD

    segmentsOn( lcd_font_char_V , 9 );
    segmentsOn( lcd_font_char_o , 8 );
    segmentsOn( lcd_font_char_l , 7 );
    segmentsOn( lcd_font_char_t , 6 );

    // Show "VER" on right LCD

    segmentsOn( lcd_font_char_V , 5 );
    segmentsOn( lcd_font_char_E , 4 );
    segmentsOn( lcd_font_char_r , 3 );

}


void showc2018JOSH() {

    segmentsOn(  lcd_font_char_c , 11 );
    digitOn(  2 ,10 );
    digitOn(  0 , 9 );
    digitOn(  1 , 8 );
    digitOn(  8 , 7 );

    segmentsOn( lcd_font_char_J , 5 );
    segmentsOn( lcd_font_char_O , 4 );
    segmentsOn( lcd_font_char_S , 3 );
    segmentsOn( lcd_font_char_H , 2 );
}


void digitOff( uint8_t d,  uint8_t n ) {

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
        }
    }
}

// Blank out the specified digit

void digitBlank( uint8_t d ) {

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments in the digit

        lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
    }
}


// Display the decimal digit n (0-9) at position d (0-11 where 0 is leftmost) dark if onFlag, light if not

void displaydigit( uint8_t d,  uint8_t n , uint8_t onFlag) {

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            if (onFlag) {
                lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            } else {
                lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            }

        }
    }
}




void displaydigit01O() {

    uint8_t d =10;
    uint8_t n =1;
    uint8_t onFlag = 1;

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            if (onFlag) {
                lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
                } else {
                lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            }

        }
    }
}


void displaydigit01F() {

    uint8_t d =10;
    uint8_t n =1;
    uint8_t onFlag = 0;

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            if (onFlag) {
                lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
                } else {
                lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            }

        }
    }
}


void displaydigit02O() {

    uint8_t d =10;
    uint8_t n =2;
    uint8_t onFlag = 1;

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            if (onFlag) {
                lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
                } else {
                lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            }

        }
    }
}


void displaydigit02F() {

    uint8_t d =10;
    uint8_t n =2;
    uint8_t onFlag = 0;

    uint8_t segementBitsInThisDigit = lcd_font_digits[ n ];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBitsInThisDigit ) {

            if (onFlag) {
                lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
                } else {
                lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            }

        }
    }
}



// Battery icon
// Level = 0-3
// Level 0 is the outline

// Just happens to work out that the different level indicators are on coresponding COM lines on the same SEG

void battSegOn( uint8_t level) {
    lcd_set_pixel( level ,  LCD_SEG_L01 );

}

void battSegOff(uint8_t level) {
    lcd_clear_pixel( level ,  LCD_SEG_L01 );
}


// Colons between 4th and 5th digit on each module

void colonLOn() {
    lcd_set_pixel( LCD_COM_L4 ,  LCD_SEG_L05 );

}

void colonLOff() {
    lcd_clear_pixel( LCD_COM_L4,  LCD_SEG_L05 );
}


void colonROn() {
    lcd_set_pixel( LCD_COM_R4 ,  LCD_SEG_R05 );

}

void colonROff() {
    lcd_clear_pixel( LCD_COM_R4,  LCD_SEG_R05 );
}


// decimal points between 2th and 3th digit on each module

void decimalLOn() {
    lcd_set_pixel( LCD_COM_L4 ,  LCD_SEG_L09 );
}

void decimalLOff() {
    lcd_clear_pixel( LCD_COM_L4,  LCD_SEG_L09 );
}


void decimalROn() {
    lcd_set_pixel( LCD_COM_R4 ,  LCD_SEG_R09 );

}

void decimalROff() {
    lcd_clear_pixel( LCD_COM_R4,  LCD_SEG_R09 );
}



void spinOn( uint8_t d,  uint8_t step ) {

    //LCD_MEM_REG( 3 , 19 ) |=  LCD_MEM_BIT( 3 , 19 );

    //LCDDR0 |= LCD_MEM_BIT( digitmap[0][step].seg ,  digitmap[0][step].com );

    lcd_set_pixel( digitmap[d][step].com ,  digitmap[d][step].seg );

}

void spinOff( uint8_t d,  uint8_t step ) {

    lcd_clear_pixel( digitmap[d][step].com ,  digitmap[d][step].seg );

}

static const uint8_t figureEightSteps[] = {
    SEG_A, SEG_B , SEG_G , SEG_E , SEG_D , SEG_C , SEG_G , SEG_F
};

void figure8On( uint8_t d,  uint8_t s ) {

    uint8_t segementBit = figureEightSteps[s];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBit ) {

            lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );

        }
    }
}


void figure8Off( uint8_t d,  uint8_t s ) {

    uint8_t segementBit = figureEightSteps[s];

    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit

        if ( ( 1 << seg ) & segementBit ) {

            lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
        }
    }
}



/*
 Bit 1 – SEGON: Segments “ON”.
 Writing this bit to one enables all segments and the contents of the Display Memory is output on the LCD. Writing it to
 zero, turns “OFF” all LCD segments.
 This bit can be used to flash the LCD, leaving the LCD timing generator enabled

 */

void lcd_blank() {
    LCD.CTRLA |= LCD_SEGON_bm;
}

void lcd_unblank() {
    LCD.CTRLA &= ~LCD_SEGON_bm;
}
