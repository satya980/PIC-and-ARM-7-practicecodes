#include<p18f452.h>
#pragma config WDT=OFF 
void main()
{
TRISDbits.TRISD4=0;
T2CON=0x00;
while(1)
{
TMR2=0;
PR2=0xc8;
T2CONbits.TMR2ON=1;
while(PIR1bits.TMR2IF==0);
PORTDbits.RD4=~PORTDbits.RD4;
T2CONbits.TMR2ON=0;
	PIR1bits.TMR2IF=0;
	}	
	}