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
#define TBI(x,b) (x&_BV(b))



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


// Overflows ever second. Wkaes us and updates display
EMPTY_INTERRUPT(TIMER2_OVF_vect);

// Triggered whenever firing pin changes. Used to wake us up so reponse to pin change is instant.
EMPTY_INTERRUPT(PCINT0_vect);


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



int main(void)
{
    
    //DDRE |= _BV(4) | _BV(5);    // TODO: Remove DEBUG led enable
        
    
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
    
    
    SBI( PORTE , 7 );           // Enable pull-up on firing pin

    SBI( PCMSK0 , PCINT7 );     // Enable pin change on firing pin   
    SBI( EIMSK ,  PCIE0 );      // Enable pin change bank that firing pin is on 
            
    sei();          // Enable interrupt so we can wake on timer overflow
    
    // While firing pin down...
    // Display a nice little animation so people can be confident that 
    // it will work right when the firing pin is pulled. 

    uint8_t step=0;    
    
    while ( !TBI(  PINE , 7 ) ) {
        
        for( int n=0; n<12;n++ ) {
            
            if (n & 1 ) {
                figure8On( n , step );
            } else {
                figure8On( n , (step + 4) % 8 );                
            }
            
        }                            
                
            
        sleep_cpu();            

        for( int n=0; n<12;n++ ) {
            
            if (n & 1 ) {
                figure8Off( n , step );
                } else {
                figure8Off( n , (step + 4) % 8 );
            }
            
        }

        step++;
        
        if (step==8) step=0;
        
    }        
    
    // PIN PULLED!!!!!
    
    CBI( PORTE , 7 );           // Display pull-up on firing pin to save a tiny leakage current

    CBI( EIMSK ,  PCIE0 );      // Enable pin change bank that firing pin is on, so for now on
                                // the pin is dead to us. No going back, sister. 
    
    
    #warning Fast counter easter egg in place
                
    SBI( PORTB , 3 );           // Enable pullup on the top right pin of the ISP header
                                // Short this to ground to enable fast mode for testing
                            
    // Here is the counter beef
    
    uint8_t digits[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    
    // Start with all 0's on display
    
    for(uint8_t d=0; d<12;d++) {
        displaydigit( d , 0 , 1 );
    }        
    
    // Start counting
    
    TCNT2 = 0;      // Always start on a full second boundary no matter when firing pin
                    // happened to get pulled in the timer cycle
       
    while (1) {
        
        if ( TBI( PINB , 3 ) ) {        // Fast mode enabled?
            
            // Nope - pull up is not grounded        
            sleep_cpu();
        } else {
            
            // Fast mode pin is grounded. 
            // Wait for a single LCD refresh cycle so at least display is clear. 
            
            while ( !( LCDCRA & _BV(LCDIF) ) );       // Wait for next refresh cycle to start
            
            LCDCRA |= _BV( LCDIF );                   // Clear the flag for next time.
                                                      // "writing a logical one to the flag clears LCDIF"            
        }
                            
        // Start rippling th overflow up
            
        uint8_t ripplePlace=12;
        uint8_t rippleDigit;
            
        do {
            
            // We count places backwards becuase digits are numbered left to right, 
            // but ripple flows right to left
            
            ripplePlace--;
                        
            rippleDigit = digits[ripplePlace];            
                                
            displaydigit( ripplePlace , rippleDigit , 0 );     // undraw prev value of digit 
                
            if ( ++rippleDigit == 10 ) {
                    
                rippleDigit = 0;
                    
            }

            displaydigit( ripplePlace , rippleDigit , 1 );     // draw new digit
            
            digits[ripplePlace] = rippleDigit;
            
                                
        } while ( rippleDigit==0 && ripplePlace < 12);     // This will leave 0's on the display when we overflow in 10,000 years
                                                
    }    
        
    for( int d=0; d<11;d++) {
        for( int n=0; n<10; n++) {
            for(int c=0; c<12; c++ ) {
                digitOn( c , (n+c)%10 );
            }                
                _delay_ms(500);
            
            for(int c=0; c<12; c++ ) {
                digitOff( c, (n+c)%10);
            }
            
        }
    }                    

while(1);

    while (1) {
        digitOn( 0 , 0 );
        _delay_ms(500);
        digitOff( 0 , 0 );        
        digitOn( 0 , 1 );
        _delay_ms(500);
        digitOff( 0 , 1 );
        digitOn( 0 , 2 );
        _delay_ms(500);
        digitOff( 0 , 2);        
    }        
        

    
    while (1);
    
 
}

