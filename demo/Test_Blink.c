#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#ifndef __AVR_ATmega16__
#define __AVR_ATmega16__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"


int main()
{

DDRA=0xFF;
DDRB=0xFF;
DDRC=0x00;

USART_Init(51);

while (1)
{


while ((PINC & (1<<PC2)))
	{
		PORTA=0xff;
		PORTB=0x00;

		USART_Write('y');

		_delay_ms(1000);

		PORTA=0x00;
		PORTB=0xff;

		_delay_ms(1000);

	}

	if (!(PINC & (1<<PC2))) 		USART_Write('n');



}

return 0;
}
