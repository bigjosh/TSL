/*
 * LCD.cpp
 *
 * Created: 1/12/2018 5:16:42 PM
 *  Author: passp
 */ 

#include "lcd.h"

// Map LCD segments to registers
// compute at compile time
// based on register tables in 24.5.5 of the ATMEGA169 datasheets

#define LCD_MEM_REG( com , seg ) _SFR_MEM8( &LCDDR0 + (  (  seg / 8 ) + (com * 5)  )  )

#define LCD_MEM_BIT( com , seg ) ( 1<< (seg % 8))

static inline void lcd_on( uint8_t com , uint8_t seg ) {
    LCD_MEM_REG( com ,  seg ) |= LCD_MEM_BIT( com ,  seg );
}    

static inline void lcd_off( uint8_t com , uint8_t seg ) {
    LCD_MEM_REG( com ,  seg ) &= ~LCD_MEM_BIT( com ,  seg );
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

// Map each of the 7 visible LCD segments A-G in each of the 12 digits 

struct lcd_visible_segment {
    uint8_t com;       
    uint8_t seg;    
};

// TODO: PROGMEM and then statically compiled transitions

// Maps segments in each digit to coresponding SEG and COM pin
// 0=leftmost digit, 11=rightmost

const lcd_visible_segment  digitmap[][7] = {

    {     //1 on the datasheet= 0 in digitmap array
        {0 , 1 },       //A
        {1 , 1 },       //B
        {2 , 1 },       //C                
        {3 , 0 },       //D
        {2 , 0 },       //E
        {0 , 0 },       //F
        {1 , 0 },       //G             
    },
    
    {     //2
        {0 , 3 },       //A
        {1 , 3 },       //B
        {2 , 3 },       //C
        {3 , 2 },       //D
        {2 , 2 },       //E
        {0 , 2 },       //F
        {1 , 2 },       //G        
    },                
    
    {     //3
        {0 , 5 },       //A
        {1 , 5 },       //B
        {2 , 5 },       //C
        {3 , 4 },       //D
        {2 , 4 },       //E
        {0 , 4 },       //F
        {1 , 4 },       //G
    },

    {     //4
        {0 , 7 },       //A
        {1 , 7 },       //B
        {2 , 7 },       //C
        {3 , 6 },       //D
        {2 , 6 },       //E
        {0 , 6 },       //F
        {1 , 6 },       //G
    },
    
    {     //5
        {0 , 9 },       //A
        {1 , 9 },       //B
        {2 , 9 },       //C
        {3 , 8 },       //D
        {2 , 8 },       //E
        {0 , 8 },       //F
        {1 , 8 },       //G
    },
    
    {     //6
        {0 ,11 },       //A
        {1 ,11 },       //B
        {2 ,11 },       //C
        {3 ,10 },       //D
        {2 ,10 },       //E
        {0 ,10 },       //F
        {1 ,10 },       //G
    },
    
    {     //Right 1  (digit =7, index = 6 ) 
        {0 ,13 },       //A
        {1 ,13 },       //B
        {2 ,13 },       //C
        {3 ,14 },       //D
        {2 ,14 },       //E
        {0 ,14 },       //F
        {1 ,14 },       //G
    },
    
    {     //Right 2
        {0 ,15 },       //A
        {1 ,15 },       //B
        {2 ,15 },       //C
        {3 ,12 },       //D
        {2 ,12 },       //E
        {0 ,12 },       //F
        {1 ,12 },       //G
    },

    {     //Right 3
        {0 ,17 },       //A
        {1 ,17 },       //B
        {2 ,17 },       //C
        {3 ,16 },       //D
        {2 ,16 },       //E
        {0 ,16 },       //F
        {1 ,16 },       //G
    },

    {     //Right 4
        {0 ,19 },       //A
        {1 ,19 },       //B
        {2 ,19 },       //C
        {3 ,18 },       //D
        {2 ,18 },       //E
        {0 ,18 },       //F
        {1 ,18 },       //G
    },

    {     //Right 5
        {0 ,21 },       //A
        {1 ,21 },       //B
        {2 ,21 },       //C
        {3 ,20 },       //D
        {2 ,20 },       //E
        {0 ,20 },       //F
        {1 ,20 },       //G
    },

    {     //Right 6
        {0 ,23 },       //A
        {1 ,23 },       //B
        {2 ,23 },       //C
        {3 ,22 },       //D
        {2 ,22 },       //E
        {0 ,22 },       //F
        {1 ,22 },       //G
    },



    
};

void spinOn( uint8_t d,  uint8_t step ) {
    
    //LCD_MEM_REG( 3 , 19 ) |=  LCD_MEM_BIT( 3 , 19 );
    
    //LCDDR0 |= LCD_MEM_BIT( digitmap[0][step].seg ,  digitmap[0][step].com );
    
    lcd_on( digitmap[d][step].com ,  digitmap[d][step].seg );
    
}    

void spinOff( uint8_t d,  uint8_t step ) {
    
    lcd_off( digitmap[d][step].com ,  digitmap[d][step].seg );
    
}

static const uint8_t figureEightSteps[] = {
    SEG_A, SEG_B , SEG_G , SEG_E , SEG_D , SEG_C , SEG_G , SEG_F 
};    

void figure8On( uint8_t d,  uint8_t s ) {
    
    uint8_t segementBit = figureEightSteps[s];
    
    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit
        
        if ( ( 1 << seg ) & segementBit ) {
            
            lcd_on( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            
        }
    }
}


void figure8Off( uint8_t d,  uint8_t s ) {
    
    uint8_t segementBit = figureEightSteps[s];
    
    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit
        
        if ( ( 1 << seg ) & segementBit ) {
            
            lcd_off( digitmap[d][seg].com ,  digitmap[d][seg].seg );
        }
    }
}


void digitOn( uint8_t d,  uint8_t n ) {
    
    uint8_t segementBitsInThisDigit = lcd_font[ n ];
    
    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit
        
        if ( ( 1 << seg ) & segementBitsInThisDigit ) { 
            
            lcd_on( digitmap[d][seg].com ,  digitmap[d][seg].seg );
                        
        }            
    }
}    


void digitOff( uint8_t d,  uint8_t n ) {
    
    uint8_t segementBitsInThisDigit = lcd_font[ n ];
    
    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments in the digit
        
        if ( ( 1 << seg ) & segementBitsInThisDigit ) { 
                        
            lcd_off( digitmap[d][seg].com ,  digitmap[d][seg].seg );            
        }
    }
}

// Display the decimal digit n (0-9) at position d (0-11 where 0 is leftmost) dark if onFlag, light if not 

void displaydigit( uint8_t d,  uint8_t n , uint8_t onFlag) {
    
    uint8_t segementBitsInThisDigit = lcd_font[ n ];
    
    for(uint8_t seg = 0 ; seg < 7; seg++ ) {    // Walk though the 7 segments A-G in the digit
        
        if ( ( 1 << seg ) & segementBitsInThisDigit ) {
            
            if (onFlag) {
                lcd_on( digitmap[d][seg].com ,  digitmap[d][seg].seg );
            } else {
                lcd_off( digitmap[d][seg].com ,  digitmap[d][seg].seg );                
            }                                
            
        }
    }
}
