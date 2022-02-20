/*
	Stack implementation using linked list.
*/

#include<stdio.h>
#include<stdlib.h>
#define size 5

typedef struct st{
	int data;
	struct st *next;
}node;

node *temp, *top;

void push();
void pop();
void traverse();

int main()
{
	int ch;
	top = NULL;

	while(1)
	{
		printf("1.Push.\n2.Pop.\n3.traverse.\n0.Exit\nEnter your choose: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: traverse();
				break;
			default: exit(0);
		}
	}
	return 0;
}

void push()
{
	temp = (node*)malloc(sizeof(node));
	if(top==NULL)
	{
		top = temp;
		top->next = NULL;
	}
	else
	{
		temp->next = top;
		top = temp;
	}
	printf("\nEnter the data: ");
	scanf("%d",&temp->data);
}

void pop()
{
	if(top == NULL)
	{
		printf("\nStack Underflow.\n");
		return;
	}
	temp = top;
	top = top->next;
	printf("\nDeleted data is: %d\n",temp->data);
	free(temp);
}

void traverse()
{
	if(top==NULL)
	{
		printf("\nNothing to display.\n");
		return;
	}
	printf("\nAll values are: ");
	for(temp = top; temp!=NULL; temp= temp->next)
		printf("%d\t",temp->data);
	printf("\n");
}

