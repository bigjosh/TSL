/*
 * lcd.h
 *
 * Created: 10/25/2017 11:53:48 PM
 *  Author: passp
 */ 

#include <avr/pgmspace.h>

#ifndef LCD_H_
#define LCD_H_

#define LCDPM4  4
#define LCDDR4  _SFR_MEM8(0xF0)
#define LCDDR9  _SFR_MEM8(0xF5)
#define LCDDR14 _SFR_MEM8(0xFA)

// Use compile time function to map segments to pins
// https://en.wikipedia.org/wiki/Compile_time_function_execution

// Map LCD segments to registers
// compute at compile time
// based on register tables in 24.5.5 of the ATMEGA169 datasheets
/*
#define LCD_MEM_REG( seg , com ) ( LCDDR0 + ( seg / 8 ) )

#define LCD_MEM_BIT( seg , com ) (com % 8)

// Map 7 segments A-G to internal representation bits 
// A=0b00000001, B=0b00000010, etc

#define LCD_DIS_BIT( letter ) ( 1 << (letter - 'A') )

extern const uint8_t PROGMEM segmap[];
*/

void spinOn( uint8_t d, uint8_t step );

void spinOff( uint8_t d, uint8_t step );

// Darken the segments in digit d (leftmost is 0) to display the number n

void digitOn( uint8_t d,  uint8_t n );

// Undarken the segments in digit d (leftmost is 0) to undisplay the number n

void digitOff( uint8_t d,  uint8_t n );

// Display the decimal digit n (0-9) at position d (0-11 where 0 is leftmost) dark if onFlag, light if not

void displaydigit( uint8_t d,  uint8_t n , uint8_t onFlag);

// Animate an atractive figuree 8 pattern. There are 8 steps

void figure8On( uint8_t d,  uint8_t s );


void figure8Off( uint8_t d,  uint8_t s );


#endif /* LCD_H_ */