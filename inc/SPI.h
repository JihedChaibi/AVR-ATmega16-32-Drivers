/*
*
*  File:          SPI.h
*  Author:        Jihed Chaibi
*  Date:          30/06/2020
*  Description:   Basic SPI Functions Declarations
*
*/


#ifndef  SPI_AVR_H_
#define  SPI_AVR_H_

#include "AVR_MACROS.h"

/* Init Master's SPI */
void SPI_Master_Init();

/* Init Slave's SPI */
void SPI_Slave_Init();

/* Send 1 Character (8bits) */
void SPI_Master_Transmit(uint8_t data);

/* Recieve data as slave*/
char SPI_Slave_Receive(void);



#endif