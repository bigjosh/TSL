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

void spinOn( uint8_t step );

void spinOff( uint8_t step );

#endif /* LCD_H_ */