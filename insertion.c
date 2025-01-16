#include <stdio.h>


void insertionSort(int arr[], int n) 
{
    int i, key, j;
    
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];  // Move larger element one position to the right
            j = j - 1;  // Move to the previous element
        }
        
        // Place key in its correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int n;
    
    // Get the number of elements in the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Get the array elements from the user
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: \n");
    printArray(arr, n);

    // Perform Insertion Sort
    insertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
