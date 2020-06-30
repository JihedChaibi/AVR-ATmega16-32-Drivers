#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#include <avr/io.h>
int main()
{


DDRA=0xFF;
DDRB=0xff;
DDRC=0x00;

while (1)
{


if ((PINC & (1<<PC2)))
	{
		PORTA=0xff;
		PORTB=0x00;
	}

if (!(PINC & (1<<PC2))) 
	{
	PORTA=0x00;
	PORTB=0xff;}
	}


return 0;
}
