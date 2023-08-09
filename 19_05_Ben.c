#include<stdio.h> 

int main()

{

int size;

	printf("enter no of elements in an array\n");	//enter input for array size
	
	scanf("%d",&size);
	
int arr[size];
	for(int i=0;i<=(size-1);i++)
	{
		printf("enter element for base index [%d]: ",i ); //enter elements of array
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<=(size-1);i++)
	{
		printf("element for base index [%d] is: %d ",i,arr[i]); //displaying elements of all base index of an array
		printf("\n");
	}
	for(int i=0;i<=(size-1);i++)
	{
		if(arr[0]<arr[i])					//if arr[0] is less than the other assinging the element of that array to arr[0];
		{	
			arr[0]=arr[i];
			
		}
	}
		printf("The largest element in the given array is: %d",arr[0]);

return 0;
}

