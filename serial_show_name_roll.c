#include<p18f452.h>
#pragma config WDT=OFF
#define a PORTCbits.RC4
#define b PORTCbits.RC5
char d1[]="sataykam";
char d2[]="116ee0340";
char d3[]="09";
char d4[]="I dont know";
void main()
{
	int q;
TRISCbits.TRISC4=1;
TRISCbits.TRISC5=1;
TXSTA=0X20;
SPBRG=25;
RCSTA=0x80;
while(1)
{
if(a==0&&b==0)	
{ 
	for(q=0;q<8;q++)
	{
		TXREG=d1[q];
		while(PIR1bits.TXIF==0);
		PIR1bits.TXIF=0;
		}	
while(1);
	}
if(a==0&&b==1)	
{ 
	for(q=0;q<9;q++)
	{
		TXREG=d2[q];
		while(PIR1bits.TXIF==0);
		PIR1bits.TXIF=0;
		}
while(1);	
	}
	if(a==1&&b==0)	
{ 
	for(q=0;q<2;q++)
	{
		TXREG=d3[q];
		while(PIR1bits.TXIF==0);
		PIR1bits.TXIF=0;
		}
while(1);	
	}
if(a==1&&b==1)	
{ 
	for(q=0;q<11;q++)
	{
		TXREG=d4[q];
		while(PIR1bits.TXIF==0);
		PIR1bits.TXIF=0;
		}	
while(1);
	}
	
	}
}