#include<stdio.h>
#include<stdlib.h>


typedef struct st{
	int data;
	struct st *next;
}node;

node *start, *current, *temp;

void create();
void traverse();
void min();
void MoveToEnd();
void MoveToFirst();

int main()
{
	int ch;
	while(1)
	{
		printf("1.Create.\n2.Traverse.\n3.Find Minimum Value.\n4.Set first node at end.\n5.Set last node at starting\n6.Exit\nEnter your choose: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: traverse();
				break;
			case 3: min();
				break;
			case 4: MoveToEnd();
				break;
			case 5: MoveToFirst();
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


// Find minimum value from the linked list.
void min()
{
	int m, i=1;
	m = start->data;
	for(current=start; current!=NULL; current=current->next)
	{
		if(m >= current->data)
		{
			m = current->data;
		}
	}
	for(current=start; current!=NULL; current=current->next)
	{
		if(m == current->data)
		{
			break;
		}
		i++;
	}
	
	printf("\nMinimum value is: %d and position is: %d\n",m,i);
	for(current=start; current->next!=NULL; current=current->next);
}

//Set first node at the end of the linked list.

void MoveToEnd()
{
	temp = start;
	start = temp->next;
	
	for(;current->next!=NULL; current = current->next);
	
	current->next = temp;
	temp->next=NULL;
	return;
}


//Set last node at the starting of the linked list.
void MoveToFirst()
{
	for(current=start; current->next!=NULL; current=current->next)
	{
		temp = current;
	}
	current->next = start;
	start = current;
	temp->next =NULL;
	return;
}

