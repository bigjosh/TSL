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

#define BIT_TIME_US     (500)          // How long should should we wait between bit transitions?

// These are open collector signals, so never drive high - only drive low or pull high

// The init functions put the pins into " Totem-pole with Pull-up" mode
// In this mode the pin is:
//  pulled high when DIR =0
//  driven low when DIR =1

// Assumes OUT bits are still at startup default of 0

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

  sda_pull_init();
  scl_pull_init();

  /*
  while (1) {
    scl_drive_low();
    _delay_us(BIT_TIME_US);
    scl_pull_high();
    _delay_us(BIT_TIME_US);
  }
  */


  // This leaves us with both SCL and SDA high, which is an idle state
}

// Write a byte out to the slave and look for ACK bit
// Assumes SCL low, SDA doesn't matter

// Returns 0=success, SDA high (ACK bit released), SCL low.

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
// Assumes SCL high
// Returns with SCL low, SDA wahtever last bit (r/w bit) was

static unsigned char USI_TWI_Start( unsigned char slave , unsigned char readFlag) {

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

    uint8_t controlword = (slave << 1) | readFlag;

    return USI_TWI_Write_Byte( controlword );

}

// Assumes on entry SCL low 
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

    sda_pull_high();            // SDA low to high while SCLK is high is a STOP
    _delay_us(BIT_TIME_US);

}

// Write the bytes pointed to by buffer
// addr is the chip bus address
// assumes bus is idle on entry, Exists with bus idle
// Returns 0 on success

unsigned char USI_TWI_Write_Data(unsigned char slave, unsigned char addr , const uint8_t *buffer , uint8_t count)
{

    USI_TWI_Start( slave , 0 );      // TODO: check for error
    
    USI_TWI_Write_Byte( addr );      // select starting register to write to
    

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

unsigned char USI_TWI_Read_Data(unsigned char slave, unsigned char addr  , uint8_t *buffer , uint8_t count)
{

    USI_TWI_Start( slave , 0 );      // "CPU transmits the RX8900's slave address with the R/W bit set to write mode."

    USI_TWI_Write_Byte( addr );     // "CPU transfers address for reading from RX8900."
    
    // Write returns with SDA high (ACK bit released), SCL low.
    
    // We are doing a restart here, so force clock high, then Start() will pull sda low with clock high
    
    scl_pull_high();
    _delay_us(BIT_TIME_US);     

    USI_TWI_Start( slave , 1 );      // "CPU transfers RESTART condition [Sr] (in which case, CPU does not transfer a STOP condition [P])"


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
        // we are reading so it is our turn to ACK now

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
    scl_drive_low();            // finish clocking out a NAK

    USI_TWI_Stop();

    // End transaction with bus in idle

    return(0);

}
