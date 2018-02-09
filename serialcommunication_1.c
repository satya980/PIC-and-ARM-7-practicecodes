#include<p18f452.h>
#pragma config WDT=OFF
void main()
{
	TRISCbits.TRISC1=0;
while(1)
	{T1CON=0x00;
		TMR1H=0x9E;
	TMR1L=0xF7;
	T1CONbits.TMR1ON=1;
		while(PIR1bits.TMR1IF==0);
	T0CONbits.TMR0ON=0;
	PIR1bits.TMR1IF=0;
	PORTCbits.RC1=~PORTCbits.RC1;
	}
	}