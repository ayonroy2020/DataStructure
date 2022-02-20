/*
	Queue:- Queue is a linear data structure where we can add data from one end using 'rear' pinter and remove data from another end using 'front' pointer. This mechanism is called 
	FIFI (First in First out).
*/

#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size], front, rear;

void add_queue();
void del_queue();
void traverse();

int main()
{
	int ch;
	front = 0;
	rear = -1;
	while(1)
	{
		printf("1.Add queue.\n2.Delete queue.\n3.Traverse\n0.Exit.\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add_queue();
				break;
			case 2: del_queue();
				break;
			case 3: traverse();
				break;
			default: exit(0);
		}
	}
	return 0;
}

void add_queue()
{
	if((rear+1)==size)
	{
		printf("Queue is Overflow.\n");
		return;
	}
	rear++;
	printf("Enter data: ");
	scanf("%d",&queue[rear]);
}

void del_queue()
{
	if(front==(rear+1))
	{
		printf("Nothing to delete.\n");
		return;
	}
	printf("Deleted data is: %d\n",queue[front]);
	front++;
}

void traverse()
{
	int i;
	if(front==(rear+1))
	{
		printf("Nothing to delete.\n");
		return;
	}
	printf("All values are: ");
	for(i=front; i<=rear; i++)
		printf("%d\t",queue[i]);
	printf("\n");
}

