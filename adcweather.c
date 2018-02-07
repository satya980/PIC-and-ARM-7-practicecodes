#include<p18f452.h>
#pragma config WDT=OFF
#define rs PORTBbits.RB1
#define rw PORTBbits.RB2
#define en PORTBbits.RB3
#define rd PORTBbits.RB4
#define wr PORTBbits.RB5
#define intr PORTBbits.RB6
int cmmd[]={0x38,0x0e,0x01,0x06,0x80};
char data1[]="weather is hot";
char data2[]="weather is cold";
char data3[]="weather is moderate";
void del()
{
int x;
for(x=0;x<10000;x++);
}
void cmm()
{
rs=0;
rw=0;
en=1;
en=0;	
	}
	void dat()
{
rs=1;
rw=0;
en=1;
en=0;	
	}
void adc()
{
rd=1;
wr=0;
	wr=1;
while(intr==1);
rd=0;
}
void main()
{
	int b,c,d;
	int a;
	TRISD=0;
	TRISB=1;

for(b=0;b<5;b++)
{
	PORTD=cmmd[b];
	cmm();
	}	
	while(1)
{
adc();
	if(PORTB<25)
	{
	for(a=0;b<19;b++)
	{
		PORTD=data2[a];
		dat();
		del();
}	
		}
if(PORTB>25&&PORTB<35)
{
	for(b=0;b<18;b++)
	{
		PORTD=data3[b];
		dat();
del();
		}
	}
if(PORTB>35)
{
	for(b=0;b<18;b++)
	{
		PORTD=data1[b];
		dat();
       del();
		}
	}			
		}} 	