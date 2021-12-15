#include<stdio.h>
#include<stdlib.h>
#define size 5

//***It follows always """divide and conquere rule""" and its also """implements on sorted array"""***

int main()
{
	//int a[size] = {20,60,40,80,50};
	int a[size];
	int n, pos=-1, mid,lb,ub, i;
	
	printf("Enter sorted array elements: ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter searching no: ");
	scanf("%d",&n);
	
	lb=0;
	ub=size-1;
	mid=(lb+ub)/2;
	while(lb<=ub && pos==-1)
	{
		if(a[mid]==n)
			pos=mid;
		else if(a[mid]>n)
			ub=mid-1;
		else if(a[mid]<n)
			lb=mid+1;
		mid=(lb+ub)/2;
	} 
	if(pos==-1)
		printf("%d does not exist in array.\n",n);
	else
		printf("%d is found in %d position.\n",n,(pos+1));
}
