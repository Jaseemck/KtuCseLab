#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int queue[MAX];
int rear=-1;
int front=-1;

void enqueue(int queue[],int item);
void dequeue(int queue[]);
void display(int queue[]);

int main()
{
	int k,item,x;
	do
	{
		printf("1.Enqueue  2.Dequeue  3.DISPLAY\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1: printf("\nEnter the item to be added: ");
				scanf("%d",&item);
				enqueue(queue,item);
				break;
			case 2: dequeue(queue);
				break;
			case 3: display(queue);
				break;
			default: printf("\n INVALID OPTION!!! \n");
		}
		printf("\n1.Continue.. 2.Stop\n");
		scanf("%d",&x);
	}while(x==1);
	return 0; 
}

void enqueue(int queue[],int item)
{
	if((rear+1)%MAX==front)
		printf("Queue Overflow!!");
	else
	{
		rear=(rear+1)%MAX;
		queue[rear]=item;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	return;
}



void dequeue(int queue[])
{
	int del_item;
	if(front==-1 || rear==-1)
		printf("Queue Underflow!!");
	else
	{
		del_item=queue[front];
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
		front=(front+1)%MAX;
	return;
}

void display(int queue[])
{	
	int i;
	if(front==-1)
	{
		printf("Empty");
		return;
	}
	if(front>rear)
	{
		for(i=front;i<MAX;i++)
			printf("%d ",queue[i]);
		for(i=0;i<=rear;i++)
			printf("%d ",queue[i]);
	}
	else
	{
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);
	}
	return;
}
