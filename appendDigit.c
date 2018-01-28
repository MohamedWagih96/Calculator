#include "LCDHeader.h"
extern char op[16];
extern int opCounter;
extern int c;

//Save all the digits entered by the user in an array
void appendDigit(char d){
	//LCD_command(1); //Clear LCD
	c++;
	op[opCounter++]=d;
	
}
