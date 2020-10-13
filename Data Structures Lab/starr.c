#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void push(int stack[],int item);
void pop(int stack[]);
void display(int stack[]);

int stack[MAX];
int TOP;

int main()
{
	int k,item,x;
	do
	{
		printf("1.PUSH  2.POP  3.DISPLAY\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1: printf("\nEnter the item to be added: ");
				scanf("%d",&item);
				push(stack,item);
				break;
			case 2: pop(stack);
				break;
			case 3: display(stack);
				break;
			default: printf("\n INVALID OPTION!!! \n");
		}
		printf("\n1.Continue.. 2.Stop\n");
		scanf("%d",&x);
	}while(x==1);
	return 0; 
}

void push(int stack[],int item)
{
	if(TOP==MAX-1)
		printf("Stack Overflow!!");
	else
	{
		TOP=TOP+1;
		stack[TOP]=item;
	}
	return;
}

void pop(int stack[])
{
	int del_item;
	if(TOP==-1)
		printf("Stack Underflow!!");
	else
	{
		del_item=stack[TOP];
		TOP=TOP-1;
	}
	return;
}

void display(int stack[])
{	
	int i=0;
	if(TOP==-1)
	{
		printf("Stack Overflow!!");
	}
	else
	{
		for(i=TOP;i>0;i--)
			printf("%d ",stack[i]);
	}
	return;
}
