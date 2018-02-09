#include<p18f452.h>
#pragma config WDT=OFF
#define x PORTBbits.RB1
#define y PORTBbits.RB5
#pragma interrupt t0
void t0()
{
x=~x;
TMR0H=0;
TMR0L=0;
INTCONbits.TMR0IF=0;	
	}
	#pragma interruptlow t
	void t()
	{
	y=~y;
	TMR1H=0;
	TMR1L=0;
	PIR1bits.TMR1IF=0;	
		}
		#pragma code timer0=0x08
		void timer0()
		{
			t0();
			}
		#pragma code t1=0x18
		void t1()
			{
			t();	
			}
			#pragma code main=0x200
			void main()
			{
			TRISBbits.TRISB1=0;	
			TRISBbits.TRISB5=0;
			TRISC=0xff;
			TRISD=0;
			T0CON=0x08;
			T1CON=0;
			TMR0H=0;	
			TMR0L=0;
			TMR1H=0;
			TMR1L=0;
			INTCONbits.TMR0IE=1;
			PIE1bits.TMR1IE=1;
			INTCONbits.GIE=1;
			INTCONbits.PEIE=1;
			T0CONbits.TMR0ON=1;
			T1CONbits.TMR1ON=1;
			RCONbits.IPEN=1;
			IPR1bits.TMR1IP=0;
			INTCON2bits.TMR0IP=1;
			while(1)
			{
				PORTD=PORTC;}
				}