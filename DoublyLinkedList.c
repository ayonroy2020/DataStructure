/***
	Doubly Linked List:- Here each node contains data part and two address part. The first address points to the previous node and second address points to the
	next node. The previous address of the first node and next address of the last node is NULL.

	Features of Doubly Linked List:-
		1. We can traverse all nodes at any direction in a doubaly linked list.
		2. We don't need to hold the starting node.
		3. Previous address of the first node and next address of the last node is NULL.
		4. It is use to implement Tree and Graph.
***/

#include<stdio.h>
#include<stdlib.h>


typedef struct st{
	int data;
	struct st *prev, *next;
}node;

node *current, *temp;

void create();
void traverse();
void InsertFirst();
void InsertMiddle();
void InsertLast();
void DeleteFirst();
void DeleteMiddle();
void DeleteLast();

int main()
{
	int ch;
	current = NULL;
	while(1)
	{
		printf("1.Create.\n2.Traverse.\n3.Insert First.\n4.Insert Middle.\n5.Insert Last\n6.Delete First.\n7.Delete Middle\n8.Delete Last\n9.Exit.\nEnter your choose: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: traverse();
				break;
			case 3: InsertFirst();
				break;
			case 4: InsertMiddle();
				break;
			case 5: InsertLast();
				break;
			case 6: DeleteFirst();
				break;
			case 7: DeleteMiddle();
				break;
			case 8: DeleteLast();
				break;
			default: exit(0);
		}
	}
	return 0;
}

// Create node and insert a value into it.

void create()
{
	temp = (node *)malloc(sizeof(node));
	
	if(current == NULL)
	{
		current = temp;
		current->prev = NULL;
	}
	else
	{
		for(;current->next!=NULL; current=current->next);
		current->next = temp;
		temp->prev = current;
		current = temp;
	}
	printf("\nEnter a data: ");
	scanf("%d",&current->data);
	current->next = NULL;
}

// To display the Lists elements.

void traverse()
{
	if(current == NULL)
	{
		printf("\nNothing to display.\n");
		return;
	}
	
	for(;current->prev!=NULL; current=current->prev);
	printf("\nAll values of the list are: \n");
	
	for(temp=current; temp!=NULL; temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
	printf("\n");
}

//Insert any node at the starting of the linked list.

void InsertFirst()
{
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter a data: ");
	scanf("%d",&temp->data);
	
	for(;current->prev!=NULL; current=current->prev);
	current->prev = temp;
	temp->next = current;
	temp->prev = NULL;
}

//Insert any node at the middle of the linked list.

void InsertMiddle()
{
	int pos, c=1;
	if(current==NULL)
	{
		printf("\nNode is Empty.\n");
		return;
	}
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter a data: ");
	scanf("%d",&temp->data);
	printf("\nEnter position for insert: ");
	scanf("%d",&pos);
	
	for(;current->prev!=NULL; current=current->prev);
	for(;current->next!=NULL; current=current->next)
	{
		if(c==pos)
		{
			current->next->prev = temp;
			temp->next = current->next;
			current->next = temp;
			temp->prev = current;
			break;
		}
		c++;
	}
	
}

//Insert any node at the end of the linked list.

void InsertLast()
{
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter a data: ");
	scanf("%d",&temp->data);
	
	for(;current->next!=NULL; current=current->next);
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
}

//Delete node from first.

void DeleteFirst()
{
	for(;current->prev!=NULL; current=current->prev);
	temp = current;
	current = current->next;
	current->prev = NULL;
	printf("\nDelete node is: %d\n",temp->data);
	free(temp);
}

//Delete middle node of the given position from a linked list.

void DeleteMiddle()
{
	int pos, c=1;
	printf("\nEnter position for delete: ");
	scanf("%d",&pos);
	
	for(;current->prev!=NULL; current=current->prev);
	for(temp=current;temp->next!=NULL; temp=temp->next)
	{
		if(pos == 1)
		{
			DeleteFirst();
			return;
		}
		if(pos==c)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			printf("\nDelete node is: %d\n",temp->data);
			free(temp);
			
			/*current = temp->prev;
			current->next = temp->next;
			temp->next->prev = current;
			free(temp);*/
			break;
		}
		c++;
	}
}

// Delete last node from the linked list.
 
void DeleteLast()
{
	for(;current->prev!=NULL; current=current->prev);
	for(temp=current;temp->next!=NULL;temp=temp->next);
	temp->prev->next = NULL;
	printf("\nDelete node is: %d\n",temp->data);
	free(temp);
	/*for(;current->next!=NULL; current=current->next);
	temp = current;
	current = current->prev;
	current->next = NULL;
	free(temp);*/
}




