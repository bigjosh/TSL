/*****************************************************************************
*
* Atmel Corporation
*
* File              : USI_TWI_Master.h
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
*                     the USI_TWI_Start_Transceiver_With_Data() function. If the transceiver
*                     returns with a fail, then use USI_TWI_Get_Status_Info to evaluate the
*                     couse of the failure.
*
****************************************************************************/
    #include<avr/io.h>
//********** Defines **********//

//********** Prototypes **********//

void              USI_TWI_Master_Initialise( void );
unsigned char USI_TWI_Start_Transceiver_With_Data(unsigned char, unsigned char * , unsigned char );
unsigned char USI_TWI_Get_State_Info( void );

unsigned char USI_TWI_Read_Data(unsigned char slave,unsigned char addr, unsigned char *msg, unsigned char msgSize);

unsigned char USI_TWI_Write_Data(unsigned char slave, unsigned char addr, const uint8_t *data , uint8_t size);

unsigned char USI_TWI_Write_Data_No_stop(unsigned char slave, unsigned char addr , const uint8_t *buffer , uint8_t count);

/// float pins and disable input buffers

void USI_TWI_Master_disable( void );

