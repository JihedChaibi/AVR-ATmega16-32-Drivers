/*
*
*  File:          I2C.h
*  Author:        Jihed Chaibi
*  Date:          14/07/2020
*  Description:   Basic I2C Functions Declarations
*
*/

#ifndef  I2C_AVR_H_
#define  I2C_AVR_H_

#include "AVR_MACROS.h"


void    I2C_master_init(void);
void    I2C_start(uint8_t address);
void    I2C_stop(void);
void    I2C_write(uint8_t data);
uint8_t I2C_read(void);
uint8_t I2C_slave_available(void);
void    I2C_slave_init();






#endif