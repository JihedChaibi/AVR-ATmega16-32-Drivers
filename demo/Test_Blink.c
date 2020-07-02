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

USART_Init(9600);
USART_Write_String("Hello User! \r\n");
USART_Write_String("Test_Blink Demo.. \r\n");

	while (1)
	{

	_delay_ms(2000);

	if ((PINC & (1<<PC2)))
		{
			PORTA=0xFF;
			PORTB=0x00;

			USART_Write('A');
			USART_NewLine();

		}

	else if (!(PINC & (1<<PC2)))
		{
			
			PORTA=0x00;
			PORTB=0xFF;
		
			USART_Write(66);
			USART_NewLine();
		}


	}

return 0;
}
