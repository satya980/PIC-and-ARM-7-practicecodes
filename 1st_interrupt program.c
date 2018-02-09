#include<p18f452.h>
#pragma config WDT=OFF
#define x PORTBbits.RB4
#define y PORTCbits.RC7
#pragma interrupt b
void b()
{
	y=~y;
	INTCONbits.RBIF=0;
}
	#pragma code t=0x008
	void t()
	{
	b();	
		}
		#pragma code main=0x200
		void main()
		{
         y=1;
		TRISBbits.TRISB4=1;
		TRISCbits.TRISC7=0;
		INTCONbits.GIE=1;
		INTCONbits.PEIE=1;
		RCONbits.IPEN=1;	
            while(1);		

        	}