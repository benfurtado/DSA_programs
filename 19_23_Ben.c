#include <stdio.h>

/* To display array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k, merged[high - low + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            merged[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            merged[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        merged[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        merged[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = merged[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void main()
{
    // User defined arrray
    int n;
    printf("Enter the no of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /*
    // Static array
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    */

    // for merge sort
    mergeSort(arr, 0, n);

    printf("Sorted array: \n");
    printArray(arr, n);
}