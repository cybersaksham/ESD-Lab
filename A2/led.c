#include <reg51.h>

sbit led = P2 ^ 0;

void delay();

void main() {
 	while(1) {
	 	led = 1;
		delay();
		led = 0;
		delay();
	}
}

void delay() {
 	int i = 0;
	while(i < 10000) i++;
}