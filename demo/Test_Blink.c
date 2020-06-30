#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef __AVR_ATmega16__
#define __AVR_ATmega16__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main()
{


DDRA=0xFF;
DDRB=0xff;
DDRC=0x00;

while (1)
{


while ((PINC & (1<<PC2)))
	{
		PORTA=0xff;
		PORTB=0x00;

		_delay_ms(1000);

		PORTA=0x00;
		PORTB=0xff;

		_delay_ms(1000);

	}

}

return 0;
}
