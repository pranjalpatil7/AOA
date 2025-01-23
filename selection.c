#include <stdio.h>

void selectionSort(int A[], int n) {
    int i, j, min_j, min_x, temp;

    // Outer loop to iterate over the array
    for (i = 0; i < n - 1; i++) {
        // Assume the minimum is the first unsorted element
        min_j = i;
        min_x = A[i];

        // Inner loop to find the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (A[j] < min_x) {
                min_x = A[j];
                min_j = j;
            }
        }

        // If a new minimum is found, swap it with the current element
        if (min_j != i) {
            temp = A[i];
            A[i] = A[min_j];
            A[min_j] = temp;
        }
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];

    // Ask the user to input the array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, n);

    selectionSort(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
