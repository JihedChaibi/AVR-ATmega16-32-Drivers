/*
*
*  File:          I2C.c
*  Author:        Jihed Chaibi
*  Date:          14/07/2020
*  Description:   Implementation of I2C.h functions 
*
*/

#include "I2C.h"

#define I2C_PRESCALER 1
#define F_SCL 4000000
#define TWBR_Value (((F_CPU/F_SCL)-16)/(2*I2C_PRESCALER))

void    I2C_master_init(void)
{

TWBR = (uint8_t)TWBR_Value;

}


void    I2C_start(void)
{

TWCR = 0;
TWCR |= ((1 << TWEN) | (1 << TWSTA) | (1 << TWINT));   

}


void    I2C_write(uint8_t data);
uint8_t I2C_read(void);
void    I2C_stop(void);
uint8_t I2C_slave_available(void);
void    I2C_slave_init();