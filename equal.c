#include "LCDHeader.h"
#include <string.h>
#define GREEN     0x08
#define RED       0x02
extern int div_by_zero_flag;
extern char s;
extern int res_counter;
extern char result[16];
extern int negative_sign_flag;
extern int R;
extern int c;
extern char s_history[16];

//Read & display the final result on the second line or give an ERROR message if something went wrong
void equal(){
	LCD_command(1);
	switch(s){
		case '+' : operation('+'); break;
		case '-' : operation('-'); break;
		case '*' : operation('*'); break;
		case '/' : operation('/'); break;
	}
	
	LCD_command(0xC0); //Force cursor to start at the 2nd line
	char msg[20]="ERROR! / by zero";
	if(div_by_zero_flag==1){
		PortF_Output(RED);
		for(int i=0 ; i<20 ; i++){
			LCD_data(msg[i]);
			LCD_command(6);
		}
		//After 10 seconds reset the lcd along with the data
		Delay_Us(10000000);
		//reset();
	}
	else{
		PortF_Output(GREEN);
		if(negative_sign_flag==1){
			R=R*-1;
			LCD_data('-');
			LCD_command(6);
		} 
	for(int i=0 ;i<res_counter ; i++){
			LCD_data(result[i]);
			LCD_command(6);	
	}
}
	memset(result,0,sizeof(result));
	c=1;
}
