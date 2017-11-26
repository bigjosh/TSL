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
    /* Use 32 kHz crystal oscillator */
    /* 1/3 Bias and 1/3 duty, SEG21:SEG24 is used as port
    pins */
    //LCDCRB = (1<<LCDCS) | (1<<LCDMUX1)| (1<<LCDPM2);
    
/*    
    // Use system clock (1Mhz) 
    // 1/4 Bias and 1/4 duty (4 COMS)
    // ALL segs on (40) 
    
    // SEG0-24 (25 total segs) 
    
    LCDCRB =  (1<<LCDMUX1) | (1<<LCDMUX0) | (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0);
*/  



    // Use system clock (1Mhz)
    // 1/4 Bias and 1/4 duty (4 COMS)
    // ALL segs on (40)
    
    // SEG0-24 (25 total segs)
    
    LCDCRB =  
    
        ( 1<< LCDCS) |        // When this bit is written to one, the external asynchronous clock source is used. We use XTAL becuase EXCLK is not set,.
        ( 0 << LCD2B ) |      // When this bit is written to zero, 1/3 bias is used. When this bit is written to one, ½ bias is used.
        (1<<LCDMUX1) | (1<<LCDMUX0) |   // 1/4 duty, 4 coms on pins COM0:3
        
        
        (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0)        // 25 segments, on pins SEG0:24
        
        ;

    
    /* Using 16 as prescaler selection and 7 as LCD Clock
    Divide */
    /* gives a frame rate of 49 Hz */
//    LCDFRR = (1<<LCDCD2) | (1<<LCDCD1);
    

    /* Using 4096 as prescaler selection and 8 as LCD Clock
    Divide = 32Hz*/
    //LCDFRR = (1<<LCDPS2) |  (1<<LCDPS1) |(1<<LCDPS0) |(1<<LCDCD2) | (1<<LCDCD1) | (1<<LCDCD0) ;
    

    /* Using 256 as prescaler selection and 8 as LCD Clock
    Divide = 32Hz*/
//    LCDFRR = (1<<LCDPS1) | (1<<LCDCD1) | (1<<LCDCD0) ;
    LCDFRR = 
            // LCDPS000 = clk/16 (clock is 32768Hz so LCD clock is 2048Hz)
       // (1<<LCDCD2) | (1<< LCDCD1) | (1<<LCDCD0)       // 111 = Divide output by 8 = 32Hz
        _BV( LCDPS1 )       // clk /128 - looks good
        ;

    
    /* Set segment drive time to 125 µs and output voltage to
    3.3 V*/
    LCDCCR =     
    
        // TODO: Can we shorten this to save power?
//        _BV( LCDDC2) | _BV(LCDDC1) | _BV( LCDDC0) |         // 50% of clock cycle (longest) 31uA
//        0 |         // 300uS 12.5uA
       
          _BV( LCDDC0) |         // 70uS 10uA
       
    
//        (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1) |  (1<<LCDCC0)  // LCD contract control 3.35V

//        (1<<LCDCC3)  // LCD contract control 3.0V

          //(1<<LCDCC1) |  (1<<LCDCC0)  // LCD contract control 2.75V
          
        (0<<LCDCC1) |  (0<<LCDCC0)  // LCD contract control 2.60V
          


    ;
    
    /* Enable LCD, default waveform and no interrupt enabled
    */
    
    // TODO: Low power waveform?
    LCDCRA = (1<<LCDEN) |
        _BV( LCDAB );               // Low power waveform , drops 1uA
}

// Setup timer2 to overflow ISR once per second

void Timer2_Init(void) {
    
        
        ASSR |= _BV( AS2 );             // Clock from XTAL
        
        TCCR2A |= _BV(CS20) | _BV(CS22);            // Clock prescaler /128 (enables timer)
        
        //TCCR2A |= _BV(CS20) ;            // Clock prescaler /1 (enables timer)
        // _delay_ms(1000);
        
        // Must enable interrupt AFTER timer clock started
        
        TIMSK2 |= _BV( TOIE2 );      // Overflow interrupt enable
        
        // 32768 xtal / 256 overflow / 128 prescaller = 1 interrupt per second
        
        
    
}    

EMPTY_INTERRUPT(TIMER2_OVF_vect);

int main(void)
{


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
        LCDDR4 = 0xff;
        LCDDR5 = 0xff;
        LCDDR6 = 0xff;
        LCDDR7 = 0xff;
        LCDDR8 = 0xff;
        LCDDR9 = 0xff;
        LCDDR10 = 0xff;
        LCDDR11 = 0xff;
        LCDDR12 = 0xff;
        LCDDR13 = 0xff;
        LCDDR14 = 0xff;
        LCDDR15 = 0xff;        
        LCDDR16 = 0xff;
        
    
        sleep_cpu();
        
        //_delay_ms(500);
        

       // PIND |= _BV(0);
        
        
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
        
        sleep_cpu();
    }
 
 
        DDRB |= _BV(6);
        
        /*
        set_sleep_mode( SLEEP_MODE_PWR_SAVE );      // Power save LCD still works                
        sleep_enable();
        */
        SMCR = _BV( SM1) | _BV(SM0 ) | _BV(SE);       // Power save mode, Sleep Enabled (equivalent to above but 10 bytes shorter)
        
        //Timer2_Init();      // set up 1 interrupt per second off the XTAL   
        //sei();
       
        while (0) {
            
            PORTB |= _BV(6);    
            
                    
            TIFR2 |= _BV(TOV2);
            
           //OCR2A = 0;      // Just start any transfer to the ASYNC block
           
           //while (ASSR & _BV(OCR2UB) );      // Wait for transfer to complete - this way we know that on TSOC clock happened
            
           // _delay_ms(1);
            
           // PORTB &= ~_BV(6);
            
            sleep_cpu();
                           
        }
               
        
        //while (1)       {  PINB|=_BV(6); _delay_ms(10);}
    
        // Enable Timer2 on xtal
        
        //PORTE |= _BV(0);
        //while(1);
        
        //Timer2_Init();      // set up 1 interrupt per second off the XTAL   
        
                
        //TCCR2A |= _BV(CS22);            // Clock directly no prescaler (enables timer)
        
        
        
        SMCR = _BV( SM1) | _BV(SM0 ) | _BV(SE);       // Power save mode, Sleep Enabled
        
        sei(); 
        
        
       // _delay_ms(2000);
        
        while (0) {
            
            PORTB |= _BV(6);
            
           // OCR2A = 0;      // Just start any transfer to the ASYNC block
           // while (ASSR | _BV(OCR2UB) );      // Wait for transfer to complete - this way we know that on TSOC clock happened

            PORTB &= ~_BV(6);
            
            //sleep_cpu();
            
            /*
            
            if (TIFR2 & _BV(TOV2) ) {
                PINB |= _BV(6);
                TIFR2 |= _BV(TOV2);
            } 
            */
                           
        }
        
    
        // Shut down things we don't need. Only matters when actively running. 
        
        PRR |= _BV( PRTIM1) | _BV(PRSPI ) | _BV( PRUSART0 ) | _BV( PRADC );
/*    
        set_sleep_mode( SLEEP_MODE_PWR_SAVE );      // Power save LCD still works
        sleep_enable();
        sleep_cpu();
  */  
    
        LCD_Init();
    /* Replace with your application code */
    
        Timer2_Init();      // set up 1 interrupt per seocnd off the XTAL

        // Setup everything so we can just sleepcpu    
        set_sleep_mode( SLEEP_MODE_PWR_SAVE );      // Power save LCD still works
        sleep_enable();
        sei();
    
    while (1) 
    {
        
        PINE|=_BV(0);
        
        /*
        
        SBI( LCDDR5 , 2 );  
        _delay_ms(100);
        SBI( LCDDR10 , 2 );
        _delay_ms(100);
        
        CBI( LCDDR5 , 2 );
        _delay_ms(100);
        CBI( LCDDR10 , 2 );
        _delay_ms(100);
        
*/
        
        LCDDR0 = 0xff;
        LCDDR1 = 0xff;
        LCDDR2 = 0xff;
        LCDDR3 = 0xff;
        LCDDR4 = 0xff;
        LCDDR5 = 0xff;
        LCDDR6 = 0xff;
        LCDDR7 = 0xff;
        LCDDR8 = 0xff;
        LCDDR9 = 0xff;
        LCDDR10 = 0xff;
        LCDDR11 = 0xff;
        LCDDR12 = 0xff;
        LCDDR13 = 0xff;
        LCDDR14 = 0xff;
        LCDDR15 = 0xff;        
        
    
        //sleep_cpu();
        
        _delay_ms(500);
        

       // PIND |= _BV(0);
        
        
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
        
    // sleep_cpu();
    }
}

