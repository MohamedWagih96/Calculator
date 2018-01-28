#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "LCDHeader.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "prototypes.h"


//Global variables section
char op[16]="N";
int operand=0;
int opCounter=0;
char result[16]="N";
int R=0;
int r=1;
char s='0';
int res_counter=0;
int div_flag=0;
char equation[16]="N";
int eqCounter=0;
char s_history[16]="N";
int sh=0;
int div_by_zero_flag=0;
int negative_sign_flag=0;
char prevChar='~';
unsigned char cursorLocation;
int c=1;
float fR=0.0;


int main(void){ 
	unsigned char key;
	keypad_init();					//Initialize the keypad
  LCD_init(); 						//Initialize the lcd
	LCD_command(0x80);      //Force the cursor to the first line to the left
	PortF_Init();
	uint32_t status;
	
	
  while(1){
		key = keypad_getkey();  	  //Read the keypad
		status = PortF_Input();
    if (key != 0){						  //If a key is pressed
			char k = keypadMap(key); //Map the special characters in the keypad into + , - , / , =
			switch (k){
				case 'c' : del(); 	/*reset();*/			 						 break;
				case '=' : 
					if(s=='+' | s=='-' | s=='*' | s=='/') equal();							 
																													 break;
				case '+' : operation(k); 		displayEquation(k); 	 break;
				case '-' : operation(k); 		displayEquation(k);		 break;
				case '*' : operation(k); 		displayEquation(k);		 break;
				case '/' : operation(k); 		displayEquation(k);	 	 break;
				default  : appendDigit(k);	displayEquation(k);		 break;
			}
		}
		switch(status){                    
      case 0x01: moveCursor('L'); break   ;   // Switch 1
			case 0x10: moveCursor('R');	break;			// Switch 2
    }

		Delay_ms(500000);        
	}	
}