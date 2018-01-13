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
         _BV( LCDPS0 )      // clk /64 - looks great but maybe 1-2uA more power
      //   _BV( LCDPS1 )      // clk /128 - looks ok just on the edge of getting jittery. 

        ;

    
    LCDCCR =     
          
          _BV( LCDDC0)  |     // 70uS ontime. 10uA
       
          (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1) |  (1<<LCDCC0);  // LCD contrast control 3.35V
          
          // We need a lot of voltage here because our LCD is a 6:00PM so push the volts opens the viewing angle up to normal          

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

/*

//Blink LED for testing 

ISR(TIMER2_OVF_vect) 
 {
            // TODO: REMOVE Blink DEBUG led
            PORTE |= _BV(4);
            _delay_ms(100);
            PORTE &= ~_BV(4);
            _delay_ms(100);
};

*/

void digit( uint8_t *r , uint8_t v ) {
    switch (v) {
        
        case 0:
            
            break;
    }            
        
}    

int main(void)
{
    
    DDRE |= _BV(4) | _BV(5);    // TODO: Remove DEBUG led enable
        
    
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
    
    spinOn(0);
    
    while (1);
    
    
    uint8_t step=0;

    while (0) 
    {
     
        LCDDR0 = 0x01;
        
        _delay_ms(1);
        sleep_cpu();
        LCDDR0 = 0x02;
        _delay_ms(1000);        
        //sleep_cpu();
        
        
    };
    
    while (1) {      
        
             
        spinOff(step);
        
        step++;
        
        if (step==7) {
            step=0;
        }            
        
        spinOn(step);
       _delay_ms(1000);
        //sleep_cpu();
    }         
 
}

