#include<reg51.h>


#define l P3
	char name[4] = "ABCD";
	char val[4]="0000";

sbit rs =  P2^6;
sbit e =  P2^7;
sbit ll= P2^4;
sbit A = P1 ^ 0;
sbit b = P1 ^ 1;
sbit C = P1 ^ 2;
sbit D = P1 ^ 3;
sbit E = P1 ^ 4;
sbit F = P1 ^ 5;
sbit G = P1 ^ 6;

sbit n0 = P2 ^ 0;
sbit n1 = P2 ^ 1;
sbit n2 = P2 ^ 2;
sbit n3 = P2 ^ 3;

sbit num = P2 ^ 5;

 void delay(int x){
int i,j;
for(i=0;i<x;i++){
	for(j =0;j<10000;j++);}
}


void w_command(int x)
{
    rs = 0;
	P3 = x;
	e = 1;
	delay(5);
	e = 0;
	delay(5);
}

void w_data(char x)
{
	rs = 1;
	P3 = x;
	e = 1;
	delay(2);
	e = 0;
	delay(2);
}

void lcd_init()
{
	w_command(0x38);
	w_command(0x0C);
	w_command(0x01);
	w_command(0x80);
}



void blink(int x){
	num=1;
	switch(x){
   	 case 0:{A=1; b=1;C=1;D = 1; E = 1 ; F= 1; G = 0 ; break;}
	 case 1:{A=0; b=1;C=1;D = 0; E = 0 ; F= 0; G = 0 ; break;}
	 case 2:{A=1; b=1;C=0;D = 1; E = 1 ; F= 0; G = 1 ; break;}
	 case 3:{A=1; b=1;C=1;D = 1; E = 0 ; F= 0; G = 1 ; break;}
	 case 4:{A=0; b=1;C=1;D = 0; E = 0 ; F= 1; G = 1 ; break;}
	 case 5:{A=1; b=0;C=1;D = 1; E = 0 ; F= 1; G = 1 ; break;}
	 case 6:{A=1; b=0;C=1;D = 1; E = 1 ; F= 1; G = 1 ; break;}
	 case 7:{A=1; b=1;C=1;D = 0; E = 0 ; F= 0; G = 0 ; break;}
	 case 8:{A=1; b=1;C=1;D = 1; E = 1 ; F= 1; G = 1 ; break;}
	 case 9:{A=1; b=1;C=1;D = 1; E = 0 ; F= 1; G = 1 ; break;}
	 default:{A=0; b=0;C=0;D = 0; E = 0 ; F= 0; G = 1 ; break;}
	}

	num=0;
}

int main(){
	

    int i = 0,j=0;	  

	n0=n1=n2=n3=0;
	lcd_init();
	w_command(0x01);

		for(i=0;i<4;i++){
			w_data(name[i]);
		}

		w_command(0xC0);

		for(j=0;j<4;j++){
			w_data(val[j]);
		}
	while(1){
		ll=1;
			
		i=j=0;

		while(1){
			if(n0==1  && ll==1){
				n0=1;
				blink(0);
				val[0]+=1;
				ll=0;
				w_command(0x01);

		for(i=0;i<4;i++){
			w_data(name[i]);
		}

		w_command(0xC0);

		for(j=0;j<4;j++){
			w_data(val[j]);
		}
				delay(10);
				ll=1;
				break;
			}
			if(n1==1 && ll==1){
				n1=1;
				
				val[1]+=1;
				ll=0;
				w_command(0x01);

		for(i=0;i<4;i++){
			w_data(name[i]);
		}

		w_command(0xC0);

		for(j=0;j<4;j++){
			w_data(val[j]);
		}
				delay(10);
				ll=1;
				break;
				
			}
			if(n2==1 && ll==1){
			    
				n2=1;
				blink(2);
				val[2]+=1;
				ll=0;
				w_command(0x01);

		for(i=0;i<4;i++){
			w_data(name[i]);
		}

		w_command(0xC0);

		for(j=0;j<4;j++){
			w_data(val[j]);
		}
				delay(10);
				ll=1;
				break;
			}
			if(n3==1 && ll==1){
				n3=1;
				blink(3);
				val[3]+=1;
				ll=0;
				w_command(0x01);

		for(i=0;i<4;i++){
			w_data(name[i]);
		}

		w_command(0xC0);

		for(j=0;j<4;j++){
			w_data(val[j]);
		}
				delay(10);
				ll=1;
				break;
			}
		}
		n0=n1=n2=n3=0;

	
	}
	return 0 ;
}