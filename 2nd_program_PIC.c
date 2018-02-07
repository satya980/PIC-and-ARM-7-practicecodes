#include<p18f452.h>
#pragma config WDT=OFF
void main()
{TRISC=1;
	TRISB=TRISD=0;
	if(PORTC>0xAA)
	PORTB=PORTC;
	else
	PORTD=PORTC;
	}