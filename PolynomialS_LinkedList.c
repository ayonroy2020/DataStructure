// Polynomial addition using singaly linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct st{
	int coff, exp;
	struct st *next; // self referencial pointer.
}node;

node *first, *second, *final;

node *create(node*);
node *addition(node*, node*);
void display(node*);

int main()
{
	int ch;
	first = second = NULL;
	while(1)
	{
		printf("1.Create first list.\n2.Create second list.\n3.Addition\n0.Exit.\n");
		printf("Enter the choose: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: first=create(first);
				display(first);
				break;
			case 2: second=create(second);
				display(second);
				break;
			case 3: final=addition(first, second);
				display(final);
				break;
			default:exit(0);
		}
	}
}

node *create(node *start)
{
	node *temp, *current;
	int c, x;
	
	while(1)
	{
		printf("\nEnter coff and exp in desending order: ");
		scanf("%d%d",&c,&x);
		
		if(c==0 || x==0)
			break;
		temp = (node*)malloc(sizeof(node));
		if(start==NULL)
		{
			start = temp;
			current = temp;
		}
		else
		{
			current->next = temp;
			current = temp;
		}
		current->coff = c;
		current->exp = x;
		current->next = NULL;
	}
	return (start);
}

void display(node *start)
{
	if(start == NULL)
	{
		printf("\nNothing to display.");
		return;
	}
	printf("\n Display output: --------------------------- : ");
	for(;start!=NULL; start = start->next)
	{
		printf("%dx^%d+",start->coff,start->exp);
	}
	printf("\b_\n");
}

node *addition(node *s1, node *s2)
{
	node *temp, *current;
	final = NULL;
	
	while(s1!=NULL && s2!=NULL)
	{
		temp = (node*)malloc(sizeof(node));
		if(final==NULL)
		{
			final = temp;
			current = temp;
		}
		else
		{
			current->next = temp;
			current = temp;
		}
		
		if(s1->exp > s2->exp)
		{
			current->coff = s1->coff;
			current->exp = s1->exp;
			s1 = s1->next;
		}
		else if(s1->exp < s2->exp)
		{
			current->coff = s2->coff;
			current->exp = s2->exp;
			s2 = s2->next;
		}
		else if(s1->exp == s2->exp)
		{
			current->coff = s1->coff + s2->coff;
			current->exp = s1->exp; // or s2->exp
			s1 = s1->next;
			s2 = s2->next;
		}
		current->next = NULL;
	}
	
	if(s1!=NULL)
	{
		for(; s1!=NULL; s1=s1->next)
		{
			temp = (node*)malloc(sizeof(node));
			current->next = temp;
			current = temp;
			current->coff = s1->coff;
			current->exp = s1->exp;
		}
		current->next = NULL;
	}
	if(s2!=NULL)
	{
		for(; s2!=NULL; s2=s2->next)
		{
			temp = (node*)malloc(sizeof(node));
			current->next = temp;
			current = temp;
			current->coff = s2->coff;
			current->exp = s2->exp;
		}
		current->next = NULL;
	}
	return final;
}

