#include "LCDHeader.h"
extern int c;
extern unsigned char cursorLocation;
extern int opCounter;

void moveCursor(char direction){
	cursorLocationMap();
	switch(direction){
		case 'L' :  if(c!=1){LCD_command(cursorLocation-1); 				c--;} break;
		case 'R' :  if(c<=opCounter){LCD_command(cursorLocation+1);	c++;} break;
	}
	
}