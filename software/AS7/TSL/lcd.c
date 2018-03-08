/*
 * LCD.c
 *
 * Created: 1/12/2018 5:16:42 PM
 *  Author: josh
 */ 

// Required AVR Libraries
#include <avr/io.h>

#include "lcd.h"

// Map LCD segments to registers
// compute at compile time
// Taken from 25.5.11 DATA – LCD Data Memory Mapping


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

// Which segments A-G do we turn on for each of the displayed chars 0-9

/*
// This is rightside up font

const uint8_t lcd_font[] = {
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F ,         // 0
    SEG_B | SEG_C ,                                         // 1
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_D ,                 // 2    
    SEG_A | SEG_B | SEG_G | SEG_C | SEG_D ,                 // 3
    SEG_F | SEG_G | SEG_B | SEG_C ,                         // 4
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D ,                 // 5
    SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G ,         // 6
    SEG_A | SEG_B | SEG_C ,                                 // 7
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G , // 8    
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G ,         // 9    
};    

*/

// This is upside down font

const uint8_t lcd_font[] = {
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


// Map each of the 7 visible LCD segments A-G in each of the 12 digits 

typedef struct {
    uint8_t com;       
    uint8_t seg;    
} lcd_visible_segment ;

// TODO: PROGMEM and then statically compiled transitions

// Maps segments in each digit to corresponding SEG and COM pin
// 0=rightmost digit, 11=leftmost

const lcd_visible_segment  digitmap[][7] = {

    {     //1 on the datasheet= 0 in digitmap array
        {0 , 2 },       //A
        {1 , 2 },       //B
        {2 , 2 },       //C                
        {3 , 1 },       //D
        {2 , 1 },       //E
        {0 , 1 },       //F
        {1 , 1 },       //G             
    },
    
    {     //2
        {0 , 4 },       //A
        {1 , 4 },       //B
        {2 , 4 },       //C
        {3 , 3 },       //D
        {2 , 3 },       //E
        {0 , 3 },       //F
        {1 , 3 },       //G        
    },                
    
    {     //3
        {0 , 6 },       //A
        {1 , 6 },       //B
        {2 , 6 },       //C
        {3 , 5 },       //D
        {2 , 5 },       //E
        {0 , 5 },       //F
        {1 , 5 },       //G
    },

    {     //4
        {0 , 8 },       //A
        {1 , 8 },       //B
        {2 , 8 },       //C
        {3 , 7 },       //D
        {2 , 7 },       //E
        {0 , 7 },       //F
        {1 , 7 },       //G
    },
    
    {     //5
        {0 ,10 },       //A
        {1 ,10 },       //B
        {2 ,10 },       //C
        {3 , 9 },       //D
        {2 , 9 },       //E
        {0 , 9 },       //F
        {1 , 9 },       //G
    },
    
    {     //6
        {0 ,12 },       //A
        {1 ,12 },       //B
        {2 ,12 },       //C
        {3 ,11 },       //D
        {2 ,11 },       //E
        {0 ,11 },       //F
        {1 ,11 },       //G
    },
    
    {     //Right 1  (digit =7, index = 6 ) 
        {0 ,14 },       //A
        {1 ,14 },       //B
        {2 ,14 },       //C
        {3 ,13 },       //D
        {2 ,13 },       //E
        {0 ,13 },       //F
        {1 ,13 },       //G
    },
    
    {     //Right 2
        {0 ,16 },       //A
        {1 ,16 },       //B
        {2 ,16 },       //C
        {3 ,15 },       //D
        {2 ,15 },       //E
        {0 ,15 },       //F
        {1 ,15 },       //G
    },

    {     //Right 3
        {0 ,18 },       //A
        {1 ,18 },       //B
        {2 ,18 },       //C
        {3 ,17 },       //D
        {2 ,17 },       //E
        {0 ,17 },       //F
        {1 ,17 },       //G
    },

    {     //Right 4
        {0 ,20 },       //A
        {1 ,20 },       //B
        {2 ,20 },       //C
        {3 ,19 },       //D
        {2 ,19 },       //E
        {0 ,19 },       //F
        {1 ,19 },       //G
    },

    {     //Right 5
        {0 ,22 },       //A
        {1 ,22 },       //B
        {2 ,22 },       //C
        {3 ,21 },       //D
        {2 ,21 },       //E
        {0 ,21 },       //F
        {1 ,21 },       //G
    },

    {     //Right 6
        {0 ,24 },       //A
        {1 ,24 },       //B
        {2 ,24 },       //C
        {3 ,23 },       //D
        {2 ,23 },       //E
        {0 ,23 },       //F
        {1 ,23 },       //G
    },



    
};

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



void digitShow( uint8_t d,  uint8_t n ) {
    
    uint8_t segementBitsInThisDigit = lcd_font[ n ];
    
    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit
        
        if ( ( 1 << seg ) & segementBitsInThisDigit ) { 
            
            lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
                        
        } else {
            lcd_clear_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );            
        }            
    }
}    


void digitOn( uint8_t d,  uint8_t n ) {
    
    uint8_t segementBitsInThisDigit = lcd_font[ n ];
    
    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit
        
        if ( ( 1 << seg ) & segementBitsInThisDigit ) { 
            
            lcd_set_pixel( digitmap[d][seg].com ,  digitmap[d][seg].seg );
                        
        }        
    }
}    


void digitOff( uint8_t d,  uint8_t n ) {
    
    uint8_t segementBitsInThisDigit = lcd_font[ n ];
    
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
    
    uint8_t segementBitsInThisDigit = lcd_font[ n ];
    
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