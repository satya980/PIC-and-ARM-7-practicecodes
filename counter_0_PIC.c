#include<p18f452.h>
#pragma config WDT=OFF

void main()
{
	TRISB=0;
	T0CON=0x60;
	while(1)
	{
	TMR0L=0;
T0CONbits.TMR0ON=1;
		while(INTCONbits.TMR0IF==0)
		{
			PORTB=TMR0L;

			}
			T0CONbits.TMR0ON=0;
			INTCONbits.TMR0IF=0;
		}
	}