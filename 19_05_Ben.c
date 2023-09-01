#include<stdio.h> 

int main()

{

int size;

	printf("enter no of elements in an array\n");	
	
	scanf("%d",&size);
	
int arr[size];
	for(int i=0;i<=(size-1);i++)
	{
		printf("enter element for base index [%d]: ",i ); 
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<=(size-1);i++)
	{
		printf("element for base index [%d] is: %d ",i,arr[i]); 
		printf("\n");
	}
	for(int i=0;i<=(size-1);i++)
	{
		if(arr[0]<arr[i])				
		{	
			arr[0]=arr[i];
			
		}
	}
		printf("The largest element in the given array is: %d",arr[0]);

return 0;
}

