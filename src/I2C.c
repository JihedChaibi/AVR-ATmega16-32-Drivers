/*
*
*  File:          I2C.c
*  Author:        Jihed Chaibi
*  Date:          14/07/2020
*  Description:   Implementation of I2C.h functions 
*
*/

#include "I2C.h"

// I2C Clock Prescaler, must be: 1, 4, 16 or 64
#define I2C_PRESCALER 1
#define F_SCL 4000000


void I2C_master_init(void)
{

    TWBR = (uint8_t)((F_CPU/F_SCL)-16)/(2*I2C_PRESCALER);

}


void I2C_start(uint8_t address)
{

    TWCR |= ((1 << TWEN) | (1 << TWSTA) | (1 << TWINT));   

    // Wait until transmission completed
	while(!(TWCR & (1<<TWINT)));

    // Transmit device address
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	// Wail until transmission completed and ACK/NACK has been received
	while(!(TWCR & (1<<TWINT)));

}

void I2C_stop(void)
{    
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO));
}


void I2C_write(uint8_t data)
{

    // Send data to the previously addressed device
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	// Wait until transmission completed
	while(!(TWCR & (1<<TWINT)));

}



uint8_t I2C_read(void)
{
	// Start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA); 
	while( !(TWCR & (1<<TWINT)) );
	return TWDR;
}


uint8_t I2C_slave_available(void);
void    I2C_slave_init();