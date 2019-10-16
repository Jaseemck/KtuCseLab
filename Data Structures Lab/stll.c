#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
{
	int data;
	struct node *link;
}*TOP=NULL;
typedef struct node NODE;

void push(int item);
void pop();
void display();

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
				push(item);
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default: printf("\n INVALID OPTION!!! \n");
		}
		printf("\n1.Continue.. 2.Stop\n");
		scanf("%d",&x);
	}while(x==1);
	return 0; 
}

void push(int item)
{
	NODE *new;
	new=(NODE*)malloc(sizeof(NODE));
	new->data=item;
	new->link=TOP;
	TOP=new;
	return;
}

void pop()
{
	int del_item;
	if(TOP==NULL)
		printf("Stack Underflow!!");
	else
	{	
		NODE *ptr;
		del_item=TOP->data;
		ptr=TOP;
		TOP=TOP->link;
		free(ptr);
	}
	return;
}

void display()
{	
	NODE *temp;
	temp=TOP;
	if(temp==NULL)
	{
		printf("Stack Underflow!!");
	}
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->link;
	}
	return;
}
