/*
	Circular Singly Linked List:- Here each node contains data part and one address part. The address part of the last node points to the first node. So, no concept of NULL node.
	Properties of Circular linked list:-
		1. We can traverse from any arbitary node.
		2. We do not need to hold the starting node.
		3. Last node points to the first node.
		4. It is mainly use to implement Game theory like JOSEPHUS problem.

*/
#include<stdio.h>
#include<stdlib.h>


typedef struct st{
	int data;
	struct st *next;
}node;

node *current, *temp;

void create();
void traverse();
void jusephus();

int main()
{
	int ch;
	current = NULL;
	while(1)
	{
		printf("1.Create.\n2.Traverse.\n3.Application of Circular Linked List(Jusephus Problem)\n.0.Exit.\nEnter your choose: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: traverse();
				break;
			case 3: jusephus();
				break;
			default: exit(0);
		}
	}
	return 0;
}

void create()
{
	temp = (node *)malloc(sizeof(node));
	if(current == NULL)
	{
		current = temp;
		current->next = temp;  //Or temp->next = current;
	}
	else
	{
		temp->next = current->next;
		current->next = temp;
		current = temp;
	}
	printf("\nEnter data: ");
	scanf("%d",&temp->data);
}

void traverse()
{
	if(current == NULL)
	{
		printf("\nNothing to display.");
		return;
	}
	
	temp = current;
	do
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}while(temp != current);
	printf("\n");
}

void jusephus()
{
	int i, val;
	node *ptr;
	printf("\nEnter any value: ");
	scanf("%d",&val);
	
	temp = current;
	while(temp!=temp->next)
	{
		for(i=0; i<=val; i++)
		{
			ptr = temp;
			temp = temp->next;
		}
		ptr->next = temp->next;
		temp = temp->next;
	}
	printf("Winner node is: %d\n", temp->data);
}
