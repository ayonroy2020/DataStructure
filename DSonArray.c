#include<stdio.h>
#include<stdlib.h>
#define size 5

int data[size],loc=-1;

void append();
void insert();
void modify();
void Delete();
void traverse();
void linearSearch();

int main()
{
	int ch;
	while(1)
	{
		printf("1.Append.\n2.Insert.\n3.Modify.\n4.Remove/Delete.\n5.Traverse()\n6.LinearSearch.\n7.Exit\nEnter your choose:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: append();
				break;
			case 2: insert();
				break;
			case 3: modify();
				break;
			case 4: Delete();
				break;
			case 5: traverse();
				break;
			case 6: linearSearch();
				break;
			default: exit(0);
		}
	}
}

void append()
{
	if((loc+1)==size)
	{
		printf("Array is full.\n");
		return;
	}
	loc++;
	printf("Enter a data: ");
	scanf("%d",&data[loc]);
}

void insert()
{
	int pos, i, val;
	if((loc+1)==size)
	{
		printf("Array is full.\n");
		return;
	}
	printf("Enter position and value: ");
	scanf("%d%d",&pos,&val);
	
	if((pos-1)>=0 && (pos-1)<=loc)
	{
		for(i=loc;i>=(pos-1);i--)
		{
			data[i+1]=data[i];
		}
		data[pos-1]=val;
		loc++;
	}
}

void modify()
{
	int pos, val;
	printf("Enter position and modifying value: ");
	scanf("%d%d",&pos,&val);
	
	if((pos-1)>=0 && (pos-1)<=loc)
	{
		data[pos-1]=val;
	}
}

void Delete()
{
	int pos, i;
	if(loc==-1)
	{
		printf("Nothing to delete.\n");
		return;
	}
	
	printf("Enter delete position: ");
	scanf("%d",&pos);
	if((pos-1)>=0 && (pos-1)<=loc)
	{
		for(i=(pos-1);i<loc;i++)
		{
			data[i]=data[i+1];
		}
		loc--;
	}
}


void traverse()
{
	int i;
	if(loc==-1)
	{
		printf("Array is Empty.\n");
		return;
	}
	printf("Array elements are: ");
	for(i=0;i<=loc;i++)
		printf("%d\t",data[i]);
	printf("\n\n");
}

void linearSearch()
{
	int a[size] = {20,60,40,80,50};
	int n, i, pos=-1;
	printf("Enter any no for search: ");
	scanf("%d",&n);
	
	for(i=0;i<size && pos==-1;i++)
	{
		if(a[i]==n)
			pos=i;
	}
	if(pos==-1)
		printf("%d does not exist in array.\n",n);
	else
		printf("%d is found in %d position.\n",n,(pos+1));
}



