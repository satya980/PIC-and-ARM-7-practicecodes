#include<p18f452.h>
#pragma config WDT=OFF
void delay(int m)
{int x;
for(x=0;x<m;x++);
	}
void main()
{TRISA=0;
	TRISB=0;
	TRISC=0;
	TRISD=0;
	TRISE=0;
	ADCON1=0x07;
while(1)
{	PORTA=~PORTA;
	delay(10000);
	PORTB=~PORTB;
	delay(20000);
	PORTC=~PORTC;
	delay(30000);
	PORTD=~PORTD;
	delay(40000);
	PORTE=~PORTE;
	delay(65000);
	}
}