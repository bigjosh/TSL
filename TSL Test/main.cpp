/*
 * TSL Test.cpp
 *
 * Created: 10/24/2017 5:23:48 PM
 * Author : passp
 */ 

#include <avr/io.h>

#define F_CPU 1000000

#include <util/delay.h>

#include <avr/sleep.h>

#include <avr/interrupt.h>

#include "lcd.h"

#define SBI(x,b) (x|=_BV(b))
#define CBI(x,b) (x&=~_BV(b))

void LCD_Init(void)
{
    
    /*
    
    XTAL
    
    LCDCRB =  
    
        ( 1<< LCDCS) |                  // When this bit is written to one, the external asynchronous clock source is used. We use XTAL becuase EXCLK is not set,.
        ( 0 << LCD2B ) |                // When this bit is written to zero, 1/3 bias is used. When this bit is written to one, ½ bias is used.
        (1<<LCDMUX1) | (1<<LCDMUX0) |   // 1/4 duty, 4 coms on pins COM0:3
        
        
        (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0)        // 25 segments, on pins SEG0:24
        
        ;


    LCDFRR =
        // _BV( LCDPS0 )      // clk /64 - looks great but maybe 1-2uA more power
        _BV( LCDPS1 )      // clk /128 - looks ok just on the edge of getting jittery.

    ;



    */


    // External clock on XTAL1
    
    LCDCRB =

        ( 1<< LCDCS) |                  // When this bit is written to one, the external asynchronous clock source is used. We use XTAL becuase EXCLK is not set,.    
        ( 0 << LCD2B ) |                // When this bit is written to zero, 1/3 bias is used. When this bit is written to one, ½ bias is used.
        (1<<LCDMUX1) | (1<<LCDMUX0) |   // 1/4 duty, 4 coms on pins COM0:3
    
    
        (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0)        // 25 segments, on pins SEG0:24
    
    ;

    
      ASSR |= _BV( AS2 );             // Clock from TOSC1
    

    LCDFRR = 
      // _BV( LCDPS0 )      // clk /64 - looks great but maybe 1-2uA more power
         _BV( LCDPS1 )      // clk /128 - looks ok just on the edge of getting jittery. 

        ;

    
    LCDCCR =     
          
          _BV( LCDDC0)  |     // 70uS ontime. 10uA
       
          (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1) |  (1<<LCDCC0);  // LCD contrast control 3.35V
          
          // We need a lot of voltage here becuase our LCD is a 6:00PM so push the volts opens the viewing angle up to normal          

    LCDCRA = (1<<LCDEN) |
        _BV( LCDAB );               // Low power waveform , drops 2-4uA but looks dimmer and digits slower to update
}

// Setup timer2 to overflow ISR once per second

void Timer2_Init(void) {
    
        
        ASSR |= _BV( AS2 );             // Clock from XTAL

        
        TCCR2A |= _BV(CS20) | _BV(CS22);            // Clock prescaler /128 (enables timer)
        
        //TCCR2A |= _BV(CS20) ;            // Clock prescaler /1 (enables timer)
         _delay_ms(1000);       // Wait for xtal to warm up
        
        // Must enable interrupt AFTER timer clock started
        
        TIMSK2 |= _BV( TOIE2 );      // Overflow interrupt enable
        
        // 32768 xtal / 256 overflow / 128 prescaller = 1 interrupt per second
                   
}    

// I wish there was a way to say "Don't call the ISR, just pick up where you left off!"

EMPTY_INTERRUPT(TIMER2_OVF_vect);

void digit( uint8_t *r , uint8_t v ) {
    switch (v) {
        
        case 0:
            
            break;
    }            
        
}    

int main(void)
{
    
    // Good morning blink on pin #2
    
    DDRE |= _BV(0);    
    PINE |= _BV(0);
    PINE |= _BV(0);
    PINE |= _BV(0);
    PINE |= _BV(0);
    PINE |= _BV(0);
    PINE |= _BV(0);

    // Shut down things we don't need. Only matters when actively running.
        
    PRR |= _BV( PRTIM1) | _BV(PRSPI ) | _BV( PRUSART0 ) | _BV( PRADC );

    LCD_Init();
    Timer2_Init();
    
    SMCR = _BV( SM1) | _BV(SM0 ) | _BV(SE);       // Power save mode, Sleep Enabled
            
    sei();

    while (1) 
    {
        LCDDR0 = 0xff;
        LCDDR1 = 0xff;
        LCDDR2 = 0xff;
        LCDDR3 = 0xff;
       // LCDDR4 = 0xff;        // SEG>24, Not used on this chip
        LCDDR5 = 0xff;
        LCDDR6 = 0xff;
        LCDDR7 = 0xff;
        LCDDR8 = 0xff;
        //LCDDR9 = 0xff;        // SEG>24, Not used on this chip
        LCDDR10 = 0xff;
        LCDDR11 = 0xff;
        LCDDR12 = 0xff;
        LCDDR13 = 0xff;
        //LCDDR14 = 0xff;       // SEG>24, Not used on this chip
        LCDDR15 = 0xff;        
        LCDDR16 = 0xff;
        LCDDR17 = 0xff;
        LCDDR18 = 0xff;
        
    
        // Deep sleep until timer rolls
        sleep_cpu();
                
        
        LCDDR0 = 0x00;
        LCDDR1 = 0x00;
        LCDDR2 = 0x00;
        LCDDR3 = 0x00;
        LCDDR4 = 0x00;
        LCDDR5 = 0x00;
        LCDDR6 = 0x00;
        LCDDR7 = 0x00;
        LCDDR8 = 0x00;
        LCDDR9 = 0x00;
        LCDDR10 = 0x00;
        LCDDR11 = 0x00;
        LCDDR12 = 0x00;
        LCDDR13 = 0x00;
        LCDDR14 = 0x00;
        LCDDR15 = 0x00;
        LCDDR16 = 0x00;
        LCDDR17 = 0x00;
        LCDDR18 = 0x00;

        // Deep sleep until timer rools        
        sleep_cpu();
    }
         
 
}

