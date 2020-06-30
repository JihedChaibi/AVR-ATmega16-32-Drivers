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

     DDRB = (1<<PB4)|(1<<PB5)|(1<<PB7);	
     SPCR|= (1<<SPE)|(1<<MSTR);

}
