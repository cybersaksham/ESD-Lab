#include <reg51.h>

void delay(int end);

void main() {
 	while(1) {
		P2 = 0;
		delay(30);
		P2 = 17;
		delay(30);
		P2 = P2 + 34;
		delay(30);
		P2 = P2 + 68;
		delay(30);
		P2 = P2 + 136;
		delay(30);
		P2 = P2 - 136;
		delay(30);
		P2 = P2 - 68;
		delay(30);
		P2 = P2 - 34;
		delay(30);
	}
}

void delay(int end) {
 	int i = 0, j = 0;
	for(j=0; j<end; j++)
	while(i < 10000) i++;
}