#include "LCDHeader.h"
#include <string.h>
extern int opCounter;
extern char s_history[16];
extern char op[16];
extern int sh;
extern int div_flag;
extern char s;
extern int R;
extern int r;
extern int res_counter;
extern char result[16];
extern int operand;
extern char equation[16];
extern int eqCounter;
extern char prevChar;

//Reset all the data to its initial state
void reset(){
	LCD_command(1);
	PortF_Output(0);
	memset(op,0,sizeof(op));
	operand=0;
	opCounter=0;
	memset(result,0,sizeof(result));
	R=0;
	r=1;
	s='0';
	res_counter=0;
	div_flag=0;
	memset(equation,0,sizeof(equation));
	eqCounter=0;
	prevChar='0';
}
