#include "LCDHeader.h"
#define FLASH 0x0E
#define RED   0x02
extern char equation[16];
extern int eqCounter;
extern char prevChar;

//Display what the user is doing on the first line of the LCD
void displayEquation(char d){
	if (prevChar=='~' && (d=='+' | d=='*' | d=='/' | d=='=')) PortF_Output(RED);
	else{
		PortF_Output(FLASH);
		Delay_ms(500000);
		PortF_Output(0);
		equation[eqCounter++]=d;
		if(prevChar=='+' | prevChar=='-' | prevChar=='*' | prevChar=='/') LCD_command(1);
		LCD_data(d);
		LCD_command(6);
		prevChar=d;
		eqCounter=0;
	}
}
