/***
	Singly Linked List:- Here each node contains data part and one address part. The address part points to the next node.

	Features of Singly Linked List:-
		1. Each node contains one address part that points to the next node.
		2. We can travrese the list in forword direction only.
		3. We have to hold the starting address.
		4. It is mainly use to implement linear data structure like stack, queue, polynomial addition etc.
	free(<ptr>);
	It is an inbuilt in c that helps to deallocate or delete or remove that memory at runtime.
	Dangling Pointer: After deletion of a particular node, the node still exists into the memory , this pointer is called dangling pointer.
	We are unable to access it.
***/

#include<stdio.h>
#include<stdlib.h>


typedef struct st{
	int data;
	struct st *next;
}node;

node *start, *current, *temp;

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
	
	if(start == NULL)
	{
		start = temp;
		current = temp;
	}
	else
	{
		current->next = temp;
		current = temp;
	}
	printf("\nEnter a data: ");
	scanf("%d",&current->data);
	current->next = NULL;
}

// To display the Lists elements.

void traverse()
{
	if(start == NULL)
	{
		printf("\nNothing to display.\n");
		return;
	}
	
	printf("\nAll values of the list are: \n");
	
	for(temp=start; temp!=NULL; temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
	printf("\n");
}

//Insert any node at the starting of the linked list.

void InsertFirst()
{
	if(start == NULL)
	{
		create();
		printf("\nIt is the first node.\n");
	}
	else
	{
		temp = (node *)malloc(sizeof(node));
		printf("\nEnter a data: ");
		scanf("%d",&temp->data);
		temp->next = start;
		start = temp;
	}
}

//Insert any node at the middle of the linked list.

void InsertMiddle()
{
	node *prev;
	int pos, c=1, i=0;
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter a data: ");
	scanf("%d",&temp->data);
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	
	for(current=start; current!=NULL; current=current->next)
	{
		i++;
	}
	if(i == 0 || i==1 || pos>i-1)
	{
		printf("\nInsetion at Middle Not Possible.\n(i).Length is less than 1 [OR]\n(ii).Position is greater than length of the node\n");
		return;
	}
	else
	{
		for(prev=start, current=start->next; current!=NULL; current=current->next)
		{
			if(pos == c)
			{
				prev->next = temp;
				temp->next = current;
				break;
			}
			c++;
			prev = current;
		}
	}
}

//Insert any node at the end of the linked list.

void InsertLast()
{
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter a data: ");
	scanf("%d",&temp->data);
	
	if(start == NULL)
	{
		printf("\nThere is no node created.\n");
	}
	else
	{
		for(;current->next!=NULL; current = current->next);
	
		current->next = temp;
		current = temp;
		current->next = NULL;
	}
}

//Delete node from first.
void DeleteFirst()
{
	if(start==NULL)
	{
		printf("\nLinked List is Empty.\n");
		return;
	}
	temp = start;
	start = start->next;
	printf("Deleted node is: %d\n",temp->data);
	free(temp);
}

//Delete middle node of the given position from a linked list.

void DeleteMiddle()
{
	int pos, c=1;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	if(start==NULL)
	{
		printf("\nLinked List is Empty.\n");
		return;
	}
	else if(pos==1)
	{
		printf("\nIt is the first node.\n");
		DeleteFirst();
		return;
	}
	else
	{
		for(temp=current=start; temp->next!=NULL; temp=temp->next)
		{
			if(pos==c)
			{
				current->next = temp->next;
				printf("\nDelete node is: %d\n",temp->data);
				free(temp);
				break;
			}
			c++;
			current = temp;
		}
		for(current=start; current->next!=NULL; current=current->next);
	}
}

// Delete last node from the linked list.
 
void DeleteLast()
{
	for(temp=start; temp->next!=NULL; temp=temp->next)
		current = temp;
	
	current->next=NULL;
	printf("\nDeleted node is: %d\n",temp->data);
	free(temp);
}
