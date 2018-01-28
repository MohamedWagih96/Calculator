#include "LCDHeader.h"
extern char op[16];
extern int c;
extern int opCounter;

void del(){
	LCD_command(1);
	char op_copy[16]="N";
	op[c-1]='N';
	int e=0;
	for(int i=0;i<opCounter;i++){
		if(op[i]!='N') {
			LCD_data(op[i]);
			op_copy[e++]=op[i];
			op[i]='N';
		}
	}
	
	for(int i=0;i<e;i++){
		op[i]=op_copy[i];
	}
	opCounter=e;
}