/*
*
*  File:          SPI.c
*  Author:        Jihed Chaibi
*  Date:          30/06/2020
*  Description:   Implementation of SPI.h functions 
*
*/

#include "SPI.h"

void SPI_Master_Init()
{
     /* Set SS, MOSI and SCK output, all others input */
     DDRB = (1<<PB4)|(1<<PB5)|(1<<PB7);	

     /* Enable SPI, Master*/
     SPCR|= (1<<SPE)|(1<<MSTR);
}

void SPI_Slave_Init()
  {
    /* Set MISO output, all others input */
    DDRB =(1<<PB6);

    /* Enable SPI */
    SPCR|= (1<<SPE);
  }

void SPI_Master_Transmit(uint8_t data)
  {
    /* Start transmission */
    SPDR = data;

    /* Wait for reception complete */
    while(!(SPSR & (1<<SPIF)));
  }

char SPI_Slave_Receive(void)
  {
     /* Wait for reception complete */
     while(!(SPSR & (1<<SPIF)));

     /* Return data register */
     return SPDR;
}