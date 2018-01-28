#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "LCDHeader.h"
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
extern int div_by_zero_flag;
extern int negative_sign_flag;
extern int c;


//Basically what the operation function do is add , subtract , multiply or divide
void operation(char k){
	c=1;
	LCD_command(1); //Clear LCD
	opCounter=0;
	int operand = atoi (op); //Parse operand from string to int
	if(negative_sign_flag==1) operand=operand*-1;
	
	//Perform the required operation 
	//NOTE: You can't do something like this operand then operator1 then operator1
	//			If you entered an operator then another operator it will only consider the last one like the windows calculator
	if(s_history[sh]!=s_history[sh-1]){
	switch(k){
		case '+':
			s_history[sh++]='+';
			div_flag=1;
			if(s=='*' | s=='/') {memset(op,0,sizeof(op));operand = atoi (op);}
			s='+';
			if(negative_sign_flag==1 && R<operand){
				R=operand-R;
				R*=-1;
			}
			
			 if(negative_sign_flag==1 && R>operand){
				R=R+operand;
				R*=-1;
			}
			else R+=operand;
			
			r=R*-1;
			memset(op,0,sizeof(op));
			if(R<0){negative_sign_flag=1; R*=-1;}
			else negative_sign_flag=0;
			//if(negative_sign_flag==1) R*=-1;
			break;
		
		case '-':
			s_history[sh++]='-';
			div_flag=1;
			if(s=='*' | s=='/') {memset(op,0,sizeof(op));operand = atoi (op);}
			s='-';
			if(R==0)R=operand;
			else if(R<operand){
				R=operand-R;
				negative_sign_flag=1;
			}
			else R-=operand;
			r=R;
			memset(op,0,sizeof(op));
			op[0]='N';
			break;
		
		case '*':
			s_history[sh++]='*';
			div_flag=1;
			if(s=='+' | s=='-') {memset(op,0,sizeof(op));op[0]='1';operand = atoi (op);}
			s='*';
			if(negative_sign_flag==1) r=r*operand*-1;
			else r=r*operand;
			R=r;
			if(R<0){negative_sign_flag=1; R=r*-1;}
			else negative_sign_flag=0;
			
			memset(op,0,sizeof(op));
			op[0]='1';
			break;

		case '/':
			s_history[sh++]='/';
			if(s=='+' | s=='-') {memset(op,0,sizeof(op));op[0]='1';operand = atoi (op);}
			s='/';
			if(div_flag==1 && negative_sign_flag==0) r=r/operand;
			else if (div_flag==1 && negative_sign_flag==1) {r=r/operand; r*=-1;}
			else {r=operand; R=r;}
			R=r;
			//
		
			//
			if(R<0){negative_sign_flag=1; R=r*-1;}
			else negative_sign_flag=0;
			memset(op,0,sizeof(op));
			op[0]='1';
			div_flag=1;
			if(operand==0) div_by_zero_flag=1;
			break;
	}
}
	
	int op_int[16]={INT_MAX,}; //Initialize an array of integers to store them individually
	int index=0;
	int n=R;
	if(n==0){
		op_int[0]=0;
		res_counter=1;
		index=1;
	}
	//Break down the digit(s) & save each digit in the array
	int entered=0;
	while (n > 0) {
		int digit = n % 10;
		op_int[index++]=digit;
		n /= 10;
		entered=1;
	}
	if(entered!=0)res_counter=index;
	
	//Parse the integer array elements to characters
	int j=0;
	for(int i=index-1 ; i>=0 ; i--){
		if(op_int[i]!=INT_MAX) result[j++]=op_int[i]+'0';
	}
}
