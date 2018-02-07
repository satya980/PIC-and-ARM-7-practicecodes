#include<p18f452.h>
#pragma config WDT=OFF
#define a PORTBbits.RB0 
#define b PORTBbits.RB1 
void main()
{
TRISBbits.TRISB0=TRISBbits.TRISB1=1;
	TRISD=0;
	if(a==0 && b==0)
	PORTD=0x39;
	if(a==1 && b==0)
	PORTD=0x37;
	if(a==0 && b==1)
	PORTD=0x38;
	if(a==1 && b==1)
	PORTD=0x36;
	}