#include<stdio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int TOP=0;

void push(char item);
int pop();
int prec(char symbol);
char infix_to_postfix(char infix[],char postfix[]);

int main()
{
	char infix[100],postfix[100];
	printf("Enter theInfix expression:\t");
	scanf("%s",infix);
	infix_to_postfix(infix,postfix);
	return 0;
}

void push(char item)
{
	if(TOP==-1)
		printf("\nOverflow\n");
	else
	{
		TOP++;
		stack[TOP]=item;
	}
}

int pop()
{
	char del_item;
	if(TOP==-1)
		printf("\nUnderflow\n");
	else
	{
		del_item=stack[TOP];
		TOP--;
		return del_item;
	}
}

int prec(char symbol)
{
	if(symbol=='^')
		return 3;
	else if(symbol=='*' || symbol=='/')
		return 2;
	else if(symbol=='+' || symbol=='-')
		return 1;
	else
		return 0;
}

char infix_to_postfix(char infix[],char postfix[])
{
	int length,index=0,pos=0;
	char symbol,temp;
	length=strlen(infix);
	while(index<length)
	{
		symbol=infix[index];
		switch(symbol)
		{
			case '(' :	push(symbol);
					break;
			case ')' :	temp=pop();
					while(temp!='(')
					{
						postfix[pos]=temp;
						pos++;
						temp=pop();
					}
					break;

			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '^' :
					while(prec(stack[TOP])>=prec(symbol))
					{	
						temp=pop();
						postfix[pos++]=temp;
					}
					push(symbol);
					break;
			default:	postfix[pos++]=symbol;
				
		}
	index++;
	}
	while(TOP>=0)
	{
		temp=pop();
		postfix[pos++]=temp;
	}
	postfix[pos++]='\0';
	printf("Postfix Expression:\t");
	puts(postfix);
	return;
}










