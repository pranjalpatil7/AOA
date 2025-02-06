#include <stdio.h>

void quicksort(int arr[], int low, int high)
{
   if(low < high)
   {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
   } 
}





int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; 
    int i = low; 
    for(int j = low+1; j <= high; j++) 
    {
        if(arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[i]); 
    return (i); 
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter elements in the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
