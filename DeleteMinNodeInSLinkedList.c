#include<stdio.h>
#include<stdlib.h>


typedef struct st{
	int data;
	struct st *next;
}node;

node *start, *current, *temp;

void create();
void traverse();
void DeleteMinNode();

int main()
{
	int ch;
	while(1)
	{
		printf("1.Create.\n2.Traverse.\n3.Delete Min Node\n4.Exit\nEnter your choose: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: traverse();
				break;
			case 3: DeleteMinNode();
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

//Find min node and delete that node.

void DeleteMinNode()
{
	int m, pos=1, c=1, k=1;
	if(start==NULL)
	{
		printf("\nLinked List is Empty.\n");
		return;
	}
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
		pos++;
	}
	printf("\nMinimum value is: %d and position is: %d\n",m,pos);
	for(current=start; current->next!=NULL; current=current->next)
		k++;
	
	if(pos==1)
	{
		temp = start;
		start = start->next;
		printf("Deleted node is: %d\n",temp->data);
		free(temp);
	}
	else if(pos>1 && pos<k)
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
	else
	{
		for(temp=start; temp->next!=NULL; temp=temp->next)
			current = temp;
		
		current->next=NULL;
		printf("\nDeleted node is: %d\n",temp->data);
		free(temp);
	}
}
