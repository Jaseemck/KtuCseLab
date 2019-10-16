#include<stdio.h>
#include<string.h>
char s[10];
int top=-1;

int push(int item){
top++;
s[top]=item;
}

int pop(){
return(s[top]);
top--;
}



int main(){
char postfix[50],symbol;
int i=0,x,y;
printf("enter the postfix expression");
scanf("%s",postfix);



while((symbol=postfix[i++])!='\0'){
	if(isdigit(symbol))
		push(symbol-'0');
	else{
		y=pop();
		x=pop();}
	switch(symbol){
		case '+':
			push(x+y);
			break;	
		case '-':
			push(x-y);
			break;
		case '*':
			push(x*y);
			break;
		case '/':
			push(x/y);
			break;
 		case '^':
			push(x^y);
			break;
		default: push(symbol);
	}

}
printf("the value is %d",pop());
return(0);
}
