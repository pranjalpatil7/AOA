#include <stdio.h>

void binary(int a[], int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    
    while (low<=high)
    {
        mid =(high+low)/2;
        if (a[mid] == key)
        {
            printf("\n Key found at index %d ", mid);
            return 0 ;
        }
    
        if(a[mid] < key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    if(low>high)
    {
        printf("\nKey not found in the array\n");
        return -1;
    }    

} 
int main()
{
    int n, key;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
  

    int a[n];
    printf("\nEnter the elements of array : \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\n Enter number to be searched : ");
    scanf("%d", &key);

    binary(a,n, key);

    return 0;
}