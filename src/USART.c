/*
*
*  File:          USART.c
*  Author:        Jihed Chaibi
*  Date:          30/06/2020
*  Description:   Basic USART Functions Implementation
*
*/


#include "USART.h"


void USART_Init(uint32_t BaudRate)
{

    uint32_t BaudRate_temp;

    switch (BaudRate)
    {
        case 9600: BaudRate_temp = 51; break;
        case 115200: BaudRate_temp = 3; break;
        default: BaudRate_temp = 51; break;
    }

    /* Set baud rate */
    UBRRH = (uint8_t)(BaudRate_temp>>8);
    UBRRL = (uint8_t)(BaudRate_temp);

    /* Enable receiver and transmitter */
    UCSRB = (1<<RXEN)|(1<<TXEN);
    
    /* 1 stop bit, 8-bit data frame format */
    UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);


}

void USART_Write(unsigned char data)
{

    /* Wait for empty transmit buffer */
    while ( !( UCSRA & (1<<UDRE)) );

    /* Send the data */
    UDR = data;

}

void USART_Write_String(unsigned char* data)
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


void USART_Flush(void)
{
    unsigned char dummy;
    while ( UCSRA & (1<<RXC) ) dummy = UDR;
}

void USART_NewLine(void)
{

    /* Wait for empty transmit buffer */
    while ( !( UCSRA & (1<<UDRE)) );

    USART_Write(13);
	USART_Write(10);

}
