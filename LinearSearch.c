#include<stdio.h>
#include<stdlib.h>
#define size 5



int main()
{
	//int a[size] = {20,60,40,80,50};
	int a[size];
	int n, i, pos=-1;
	
	printf("Enter array elements: ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter searching no: ");
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
