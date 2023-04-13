#include <reg51.h>
#define L P2
sbit RS = P1^0;
sbit E = P1^1;

void delay(int);
void cw(int);
void dw(char);
void LCD_init();

void LCD_init()
{
	cw(0x38);
	cw(0x0C);
	cw(0x01);
	cw(0x80);
	cw(0x06);
}

void cw(int x)
{
	RS = 0;
	P2 = x;
	E = 1;
	delay(5);
	E = 0;
}

void dw(char x)
{
	RS = 1;
	P2 = x;
	E = 1;
	delay(5);
	E = 0;
}

void delay(int n)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<10000;j++) {}
}

char saksham[] = "Saksham\n";
char sak[] = "2020ucp1801\n";
char hitesh[] = "Hitesh\n";
char hit[] = "2020ucp1791\n";
char rahul[] = "Rahul\n";
char rah[] = "2020ucp1799\n";

void main()
{
	int i;
	int j = 0;
	
	LCD_init();

	while(saksham[j]) {
		dw(saksham[j]);
		j++;
	}
	cw(0xC0);
	j = 0;
	while(sak[j]) {
		dw(sak[j]);
		j++;
	}
	delay(10);
	LCD_init();
	j=0;
	while(hitesh[j]) {
		dw(hitesh[j]);
		j++;
	}
	cw(0xC0);
	j = 0;
	while(hit[j]) {
		dw(hit[j]);
		j++;
	}
	delay(10);
	LCD_init();
	j = 0;
	while(rahul[j]) {
		dw(rahul[j]);
		j++;
	}
	cw(0xC0);
	j = 0;
	while(rah[j]) {
		dw(rah[j]);
		j++;
	}
	delay(10);
	LCD_init();
}