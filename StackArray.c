/*
	Appilication of liner data structure :- 1. Stack. 2. Queue.
	Stack :- Stack is a liner data structure where we can add data from one end and delete data from same end. These mechanism is called LIFO(last in first out).
	Operation :- push, pop, traverse.
*/
#include<stdio.h>
#include<stdlib.h>
#define size 5

int stack[size], top;
void push();
void pop();
void traverse();

int main()
{
	int ch;
	top=-1;

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

// Push:- To add new data at the end of the list.

void push()
{
	if((top+1)==size)
	{
		printf("\nStack is Overflow.\n");
		return;
	}
	top++;
	printf("\nEnter any data: ");
	scanf("%d",&stack[top]);
}

// Pop:- To remove data at the end of the list.

void pop()
{
	if(top==-1)
	{
		printf("\nStack is Underflow.\n");
		return;
	}
	printf("\nDeleted data is: %d\n",stack[top]);
	top--;
}

//Traverse:- To desplay the data.

void traverse()
{
	int i;
	if(top==-1)
	{
		printf("\nNothing to display.\n");
		return;
	}
	printf("All values in stack:-------- \n");
	for(i=top; i>=0; i--)
		printf("\t%d position is %d\n",stack[i],i);
}

