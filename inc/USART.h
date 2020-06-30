/*
*
*  File:          USART.h
*  Author:        Jihed Chaibi
*  Date:          30/06/2020
*  Description:   Basic USART Functions Declarations
*
*/


#ifndef  USART_AVR_H_
#define  USART_AVR_H_

#include "AVR_MACROS.h"

/* Init The USART */
void USART_init(uint32_t);

/* Send one character */
void USART_Write(uint8_t data);

/* Send a string */
void USART_Write_String(uint8_t* data);

/* Recieve one character */
uint8_t USART_Read(void);

/* Is USART Available? */
uint8_t USART_available(void);

#endif