#include <stdio.h> 

void swap(int* arr, int i, int j) 
{ 
	int temp = arr[i]; 
	arr[i] = arr[j]; 
	arr[j] = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n - 1; i++) { 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i + 1; j < n; j++) 
			if (arr[j] < arr[min_idx]) 
				min_idx = j; 

		// Swap the found minimum element with the first 
		// element 
		swap(arr, min_idx, i); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n - 1; i++) 

		// Last i elements are already 
		// in place 
		for (j = 0; j < n - i - 1; j++) 
			if (arr[j] > arr[j + 1]) 
				swap(arr, j, j + 1); 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = { 64, 25, 12, 22, 11 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	// selectionSort(arr, n); 
    bubbleSort(arr, n);
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
}