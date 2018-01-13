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

// Map 7 segments A-G to internal representation bits
// A=0b00000001, B=0b00000010, etc

#define LCD_DIS_BIT( letter ) ( 1 << (letter - 'A') )

// Map each of the 7 visible LCD segments A-G in each of the 12 digits 

struct lcd_visible_segment {
    uint8_t com;       
    uint8_t seg;    
};

const lcd_visible_segment PROGMEM digitmap[2][7] = {

    {     //1
        {0 , 1 },       //A
        {1 , 1 },       //B
        {2 , 1 },       //C                
        {3 , 0 },       //D
        {2 , 0 },       //E
        {1 , 0 },       //F
        {0 , 0 },       //G             
    },
    
    {     //2
        {3 , 0 },       //A
        {3 , 1 },       //B
        {3 , 2 },       //C
        {4 , 3 },       //D
        {4 , 2 },       //E
        {4 , 0 },       //F
        {4 , 1 },       //G        
    },                

};

void spinOn( uint8_t step ) {
    
    LCD_MEM_REG( 3 , 19 ) |=  LCD_MEM_BIT( 3 , 19 );
    
    //LCDDR0 |= LCD_MEM_BIT( digitmap[0][step].seg ,  digitmap[0][step].com );
    
    LCD_MEM_REG( digitmap[0][step].seg ,  digitmap[0][step].com ) |= LCD_MEM_BIT( digitmap[0][step].seg ,  digitmap[0][step].com );
    
}    

void spinOff( uint8_t step ) {
    
    LCD_MEM_REG( digitmap[0][step].seg ,  digitmap[0][step].com  ) &= ~ LCD_MEM_BIT( digitmap[0][step].seg ,  digitmap[0][step].com );
    
}

