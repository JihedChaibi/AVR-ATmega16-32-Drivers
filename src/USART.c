/*
*
*  File:          USART.c
*  Author:        Jihed Chaibi
*  Date:          30/06/2020
*  Description:   Basic USART Functions Implementation
*
*/


#include "USART.h"


void USART_init(uint32_t BaudRate)
{

    /* Set baud rate */
    UBRRH = (uint8_t)(BaudRate>>8);
    UBRRL = (uint8_t)(BaudRate);

    /* Enable receiver and transmitter */
    UCSRB = (1<<RXEN)|(1<<TXEN);
    
    /* 2stop bit, 8-bit data frame format */
    UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);

}

void USART_Write(uint8_t Data)
{

    /* Wait for empty transmit buffer */
    while ( !( UCSRA & (1<<UDRE)) );

    /* Send the data */
    UDR = Data;

}

void USART_Write_String(uint8_t* data)
{
    for(uint8_t i = 0; data[i] != '\0'; i++)
	USART_Write(data[i]);
}

uint8_t USART_Read(void)
{
    /* Wait for data to be received */
    while ( !(UCSRA & (1<<RXC)) );

    /* Get and return received data from buffer */
    return UDR;
}


uint8_t USART_available(void)
{
    if( (UCSRA & (1<<RXC)) )  return 1;
    return 0;
}