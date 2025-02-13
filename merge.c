#include <stdio.h>

void combine(int a[], int low, int mid, int high)
{
    int l1,l2,i,j,k;
    l1= mid-low+1;
    l2= high -mid;

    int left[l1+1],right[l2+1];

    for(i=0; i<l1; i++)
    {
            left[i] = a[low+i];
    }

    for(j=0;j<l2;j++)
    {
        right[j]=a[mid+j+1];
    }

    //sentinal values
    left[l1] = 99999;
    right[l2] = 99999;

    i=0;
    j=0;
    for(k=low; k<=high; k++)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
    }
}

void merge(int a[], int low, int high)
{
    if(low<high)
    {
        int mid = (high+low)/2;
        merge(a,low,mid);
        merge(a,mid+1,high);
        combine(a,low,mid,high);
    }
}



int main()
{
    int n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements of array : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    merge(a, 0, n-1);
    printf("\nSorted array :  ");
    for(i=0; i<n; i++)
    {
        printf("%d  \t", a[i]);
    }
    return 0;
}