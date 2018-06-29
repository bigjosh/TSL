/*****************************************************************************
*
* Atmel Corporation
*
* File              : USI_TWI_Master.c
* Compiler          : AVRGCC Toolchain version 3.4.2
* Revision          : $Revision: 992 $
* Date              : $Date: 2013-11-07 $
* Updated by        : $Author: Atmel $
*
* Support mail      : avr@atmel.com
*
* Supported devices : All device with USI module can be used.
*                     The example is written for the ATmega169, ATtiny26 and ATtiny2313
*
* AppNote           : AVR310 - Using the USI module as a TWI Master
*
* Description       : This is an implementation of an TWI master using
*                     the USI module as basis. The implementation assumes the AVR to
*                     be the only TWI master in the system and can therefore not be
*                     used in a multi-master system.
* Usage             : Initialize the USI module by calling the USI_TWI_Master_Initialise() 
*                     function. Hence messages/data are transceived on the bus using
*                     the USI_TWI_Transceive() function. The transceive function 
*                     returns a status byte, which can be used to evaluate the 
*                     success of the transmission.
*
****************************************************************************/

#define	F_CPU	1000000UL	/* Hack until we fix things the right way (tm) */



#include <avr/io.h>
#include "USI_TWI_Master.h"
#include <util/delay.h>

#define BIT_TIME_US     (20)          // How long should should we wait between bit transitions?

#define SBI(port,bit) (port|=_BV(bit))
#define CBI(port,bit) (port&=~_BV(bit))
#define TBI(port,bit) (port&_BV(bit))

// These are open collector signals, so never drive high - only drive low or pull high

// The init functions put the pins into " Totem-pole with Pull-up" mode
// In this mode the pin is:
//  pulled high when DIR =0
//  driven low when DIR =1

static inline void scl_pull_init(void) {
    PORTC.PIN1CTRL = PORT_OPC_PULLUP_gc;    
}    


static inline void sda_pull_init(void) {
    PORTC.PIN0CTRL = PORT_OPC_PULLUP_gc;    
}

static inline void sda_drive_low(void) {    
    PORTC.DIRSET = _BV( 0 );
}    


static inline void sda_pull_high(void) {
    PORTC.DIRCLR = _BV( 0 );
}    

static inline void scl_drive_low(void) {
    PORTC.DIRSET = _BV( 1 );
}    


static inline void scl_pull_high(void) {
    PORTC.DIRCLR = _BV( 1 );
}    

static inline uint8_t sda_read(void) {
    return PORTC.IN & _BV( 0 );
}    

/*---------------------------------------------------------------
 USI TWI single master initialization function
---------------------------------------------------------------*/
void USI_TWI_Master_Initialise( void )
{
        
  sda_pull_high();
  scl_pull_high();
  
  // This leaves us with both SCL and SDA high, which is an idle state  
}

// Write a byte out to the slave and look for ACK bit
// Assumes SCL low, SDA doesn't matter

// Returns 0=success, SDA high, SCL low. The ACK bit is still on SDA but will disapear on next SCL falling edge

static unsigned char USI_TWI_Write_Byte( unsigned char data ) {
    
    for( uint8_t bitMask=0b10000000; bitMask !=0; bitMask>>=1 ) {
        
        // setup data bit
                        
        if ( data & bitMask) {
            sda_pull_high();
        } else {
            sda_drive_low();
            
        }                
        
        // clock it out        

        _delay_us(BIT_TIME_US);
                
        scl_pull_high();           // Clock in the next address bit
        
        _delay_us(BIT_TIME_US);
        
        scl_drive_low();        
                        
    }        
            
    // The device acknowledges the address by driving SDIO
    // low after the next falling SCLK edge, for 1 cycle. 
        
    sda_pull_high();            // Pull SDA high so we can see if the slave is driving low
    _delay_us(BIT_TIME_US);     // Not needed, but so we can see what is happening on the scope
    scl_pull_high();
    _delay_us(BIT_TIME_US);     // TODO: Don't need all these delays
    
    uint8_t ret = sda_read();   // slave should be driving low now
    scl_drive_low();            // Slave release
    _delay_us(BIT_TIME_US);     
    
    // TODO: CHeck ret
        
    return(ret);        
        
}

// readFlag=1 leaves in read mode
// readFlag=0 leaves in write mode
// Returns 0 on success, 1 if no ACK bit received.
// Assumes bus idle on entry (SCL and SDA high) 
// Returns with SCL low

static unsigned char USI_TWI_Start( unsigned char addr , unsigned char readFlag) {

    // We assume that we enter in idle state since that is how all public functions leave us
    
    _delay_us(BIT_TIME_US);         // Make sure we have been in idle at least long enough to see the falling SDA

    // Data transfer is always initiated by a Bus Master device. A high to low transition on the SDA line, while
    // SCL is high, is defined to be a START condition or a repeated start condition.
       
    sda_drive_low();
    
    _delay_us(BIT_TIME_US);
    
    scl_drive_low();
                        
    // A START condition is always followed by the (unique) 7-bit slave address (MSB first) and then w/r bit
        
    // The control word is latched internally on
    // rising SCLK edges and is eight bits in length, comprised
    // of a seven bit device address equal to 0010000b and a
    // read/write bit (write = 0 and read = 1).        
        
    uint8_t controlword = (addr << 1) | readFlag;     
    
    return USI_TWI_Write_Byte( controlword );
        
}    

// Assumes on entry SCL low and SDA high
// Returns with bus idle, SCL high SDA high 


static void USI_TWI_Stop(void) {

    // Data transfer ends with the STOP condition
    // (rising edge of SDIO while SCLK is high).
    
    // Q: Is this Really needed? Can we just do repeat starts and save this code? Spec is vague if address is reset on start.
    // A: Yes, we need this because it is possible that the FM_IC is holding the SDA line low
    // wait for us to clock out the MSB of the next byte!
    
    sda_drive_low();
    _delay_us(BIT_TIME_US);     // Give is a moment to stabilize in case 
    scl_pull_high();
    _delay_us(BIT_TIME_US);
   
    sda_pull_high();
    _delay_us(BIT_TIME_US);
 
}    

// Write the bytes pointed to by buffer
// addr is the chip bus address
// assumes bus is idle on entry, Exists with bus idle
// Returns 0 on success

unsigned char USI_TWI_Write_Data(unsigned char addr, const uint8_t *buffer , uint8_t count)
{
        
    USI_TWI_Start( addr , 0 );      // TODO: check for error
    
    // Note here we can't really break out readByte() becuase the last byte
    // is special since we do not ACK it but instead send a STOP.
    
    while (count--) {
        
        USI_TWI_Write_Byte( *buffer );
        
        buffer++;
        
    }
    
        
    // End transaction with bus in idle
    
    USI_TWI_Stop();
    
    return(0);
    
}


// Fill data buffer with bytes read from TWI
// addr is the chip bus address
// assumes bus is idle on entry, Exists with bus idle
// Returns 0 on success

unsigned char USI_TWI_Read_Data(unsigned char addr, uint8_t *buffer , uint8_t count)
{
    
    USI_TWI_Start( addr , 1 );      // TODO: check for error

                
    while (count) {
        
        unsigned char data=0;
    
        for( uint8_t bitMask=0b10000000; bitMask !=0; bitMask>>=1 ) {
        
            // Clock in the data bits
            
            scl_pull_high();           // Clock in the first data bit
            
            _delay_us(BIT_TIME_US);            
     
            if (sda_read()) {
            
                data |= bitMask;
            
            }            
        
            scl_drive_low();
            
            _delay_us(BIT_TIME_US);
                                                                    
        }      
    
        // SCLK low here
        // SDA should be pulled high and not driven low by the FMIC because 
        // we are reading so it is out turn to ACK now
        
        *buffer = data;
        
        buffer++;      
        
        count--;               
                        
        if (count) {
        
            //After each byte of data is read,
            //the controller IC must drive an acknowledge (SDIO = 0)
            //if an additional byte of data will be requested. Data
            //transfer ends with the STOP condition.         

            sda_drive_low();            // drive SDA to ACK that we read the byte
            _delay_us(BIT_TIME_US);     // Not needed, but so we can see what is happening on the scope

        
            scl_pull_high();            // Clock out the ACK bit
            _delay_us(BIT_TIME_US);

            scl_drive_low();        
            _delay_us(BIT_TIME_US);     // Not necessary
            sda_pull_high();            // Back to normal condition pulling SDA high (slave will have next data bit on bus now)
            _delay_us(BIT_TIME_US);
            
            // Ready for next bit..
            
        }            
    }    
    
    // Ok, we got all the bits we need. 
    // We did not send a ACK on the last byte, so 
    // SCL is still low from the final data bit. 
    // SDA is pulled high because the slave is waiting for use to drive low to ACK (we will STOP instead)
    
    /* 
        FROM TI: 
    
        "Once the master has received the number of bytes it is expecting, it
        will send a NACK, signaling to the slave to halt communications and release the bus. The master will
        follow this up with a STOP condition."
        
        https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=0ahUKEwj9mr_HuobYAhVJON8KHfV0CeMQFggoMAA&url=http%3A%2F%2Fwww.ti.com%2Flit%2Fan%2Fslva704%2Fslva704.pdf&usg=AOvVaw0MO8lWY9iHs3PZqsN6fgWm
                
        From FM_IC Daata sheet:
        
        "After each byte of data is read,
        the controller IC must drive an acknowledge (SDIO = 0)
        if an additional byte of data will be requested. Data
        transfer ends with the STOP condition. After every
        STOP condition, the internal address counter is reset."
        
        This actually makes sense if you consider the case where the high bit in the
        next data byte being read is a 0. In this case, the FM_IC will hold the SDA line LOW
        after the ACK bit is clocked, making it impossible to send the stop condition.
        
        This actually happened in the wild when issuing a WRITE to do a seek after issuing a
        RED to get he the currently tuned station for a save. 
                
    */

    scl_pull_high();            // SDA is is high, so we are clocking out a NAK
    _delay_us(BIT_TIME_US);        
    
    USI_TWI_Stop();
   
    // End transaction with bus in idle
    
    return(0);
    
}

// TODO: delete this placeholder

/*
unsigned char USI_TWI_Start_Transceiver_With_Data(unsigned char c, unsigned char *d, unsigned char l) {
    return(0);
} 
*/   

/*---------------------------------------------------------------
 Core function for shifting data in and out from the USI.
 Data to be sent has to be placed into the USIDR prior to calling
 this function. Data read, will be returned from the function.
---------------------------------------------------------------*/

/*
unsigned char USI_TWI_Master_Transfer( unsigned char temp )
{
  USISR = temp;                                     // Set USISR according to temp.
                                                    // Prepare clocking.
  temp  =  (0<<USISIE)|(0<<USIOIE)|                 // Interrupts disabled
           (1<<USIWM1)|(0<<USIWM0)|                 // Set USI in Two-wire mode.
           (1<<USICS1)|(0<<USICS0)|(1<<USICLK)|     // Software clock strobe as source.
           (1<<USITC);                              // Toggle Clock Port.
  do
  {
    _delay_us( T2_TWI/4 );              
    USICR = temp;                          // Generate positve SCL edge.
    while( !(PIN_USI & (1<<PIN_USI_SCL)) );// Wait for SCL to go high.
    _delay_us( T4_TWI/4 );              
    USICR = temp;                          // Generate negative SCL edge.
  }while( !(USISR & (1<<USIOIF)) );        // Check for transfer complete.
  
  _delay_us( T2_TWI/4 );                
  temp  = USIDR;                           // Read out data.
  USIDR = 0xFF;                            // Release SDA.
  DDR_USI |= (1<<PIN_USI_SDA);             // Enable SDA as output.

  return temp;                             // Return the data from the USIDR
}


*/

/*---------------------------------------------------------------
 Function for generating a TWI Stop Condition. Used to release 
 the TWI bus.
---------------------------------------------------------------*/

/*
unsigned char USI_TWI_Master_Stop( void )
{
  PORT_USI &= ~(1<<PIN_USI_SDA);           // Pull SDA low.
  PORT_USI |= (1<<PIN_USI_SCL);            // Release SCL.
  while( !(PIN_USI & (1<<PIN_USI_SCL)) );  // Wait for SCL to go high.
  _delay_us( T4_TWI/4 );               
  PORT_USI |= (1<<PIN_USI_SDA);            // Release SDA.
  _delay_us( T2_TWI/4 );                
  
#ifdef SIGNAL_VERIFY
  if( !(USISR & (1<<USIPF)) )
  {
    USI_TWI_state.errorState = USI_TWI_MISSING_STOP_CON;    
    return (FALSE);
  }
#endif

  return (TRUE);
}
*/