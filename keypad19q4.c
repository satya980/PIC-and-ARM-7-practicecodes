#include<p18f452.h>
#pragma config WDT=OFF
int row[]={0xfe,0xfd,0xfb,0xf7};
int col[]={0xef,0xdf,0xbf,0x7f};
int key[]={0,1,2,3,4,5,6,7,8,9,0x0a,0x0b,0x0c,0x0d,0x0e,0x0e};		
void del()
{int x;
	for(x=0;x<6000;x++);
	}
void main()
{
	int a,b,c;
	TRISD=0;
	PORTB=0xf0;
l:	while(1)
	{
 PORTB=0xf0;
	while(PORTB==0xf0)
TRISB=0x0f;
TRISB=0;
	a=0;
	for(b=0;b<4;b++)
	{
	PORTB=row[b];
	for(c=0;c<4;c++)
	{
		if((PORTB|0x0f)==col[c])
		{
			PORTD=key[a];
            del();
			goto l;
			}
		else
		a=a+1;	
		}
	
		}
	}
	}	