#include <reg51.h>

void delay(int end);
void rotate1();
void rotate2();
void rotate3();
void rotate4();

void main() {
 	while(1) {
	 	rotate1();
		rotate2();
		rotate3();
		rotate4();
	}
}

void rotate1() {
	int i = 1;
 	P2 = 0;
	delay(10);
	P2 = 1; 
	while(i < 8) {
	 	delay(10);
		P2 = P2 << 1;
		i++;
	}
	delay(10);
}

void rotate2() {
 	int i = 1;
	P2 = 0;
	delay(10);
	P2 = 3;
	while(i < 4) {
	 	delay(20);
		P2 = P2 << 2;
		i++;
	}
	delay(10);
}

void rotate3() {
 	int i = 1;
	P2 = 0;
	delay(10);
	P2 = 7;
	while(i < 3) {
	 	delay(30);
		P2 = P2 << 3;
		i++;
	}
	delay(10);
}

void rotate4() {
	P2 = 0;
	delay(10);
	P2 = 15;
	delay(40);
	P2 = P2 << 4;
	delay(10);
}

void delay(int end) {
 	int i = 0, j = 0;
	for(j=0; j<end; j++)
	while(i < 10000) i++;
}