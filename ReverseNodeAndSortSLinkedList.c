#include<stdio.h>
#include<stdlib.h>


typedef struct st{
	int data;
	struct st *next;
}node;

node *start, *current, *temp;

void create();
void traverse();
void sort();
void ReverseDisplay();
void ReverseNode();

int main()
{
	int ch;
	while(1)
	{
		printf("1.Create.\n2.Traverse.\n3.Sort the Linked List.\n4.Display reverse.\n5.Reverse physically\n6.Exit\nEnter your choose: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: traverse();
				break;
			case 3: sort();
				break;
			case 4: ReverseDisplay();
				break;
			case 5: ReverseNode();
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


// Sorting the linked list.

void sort()
{
	node *prev, *min;
	int val;
	
	for(prev=start; prev->next!=NULL; prev=prev->next)
	{
		min = prev;
		for(current=prev->next; current!=NULL; current=current->next)
		{
			if(min->data > current->data)
				min = current;
		}
		
		if(prev!=min)
		{
			val = prev->data; 
			prev->data = min->data;
			min->data = val;
		}
	}
}

//Display the linked list elememts in reversed order.

void ReverseDisplay()
{
	int i=0, j;
	
	for(temp=start; temp!=NULL; temp=temp->next)
		i++;
	
	printf("\nReversed order elements are: \n");
	for(;i>=1;i--)
	{
		temp = start;
		for(j=1;j<i;j++)
		{
			temp = temp->next;
		}
		printf("%d\t",temp->data);
	}
	printf("\n");
}

//Reverse linked list physically and display the linked list elememts in reversed order.

void ReverseNode()
{
	node *p1, *p2, *p3;
	
	p1 = start;
	p2 = p1->next;
	p3 = p2->next;
	p2->next = p1;
	p1->next = NULL;
	
	while(p3!=NULL)
	{
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
		p2->next = p1;
	}
	start = p2;
}

