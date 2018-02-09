#include<p18f452.h>
#pragma config WDT=OFF
void delay()
{int x;
	for(x=0;x<20000;x++);
	}
void main()
{
	TRISB=TRISD=0;
	T3CON=0x60;
	while(1)
	{TMR3H=0;
		TMR3L=0;
	T3CONbits.TMR3ON=1;
	while(PIR2bits.TMR3IF==0)	
		{PORTB=TMR3H;
			PORTD=TMR3L;
delay();
			}
			PIR2bits.TMR3IF=0;
			T3CONbits.TMR3ON=0;
			}
	
	}