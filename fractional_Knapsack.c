#include<stdio.h>

int main()
{
    /* Provide input on sorted manner*/
    float weight[50], profit[50], ratio[50],totalprofit , capacity, temp;
    int i, j, n;
    printf("Enter number of items :");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter weight and profit for item[%d] : ", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of Knapsack : ");
    scanf("%f", &capacity);

    for(i=0; i<n; i++)
    {
        ratio[i] = profit[i]/weight[i];
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] =temp;

                temp = profit[j];
                profit[j] = profit [i];
                profit[i] = temp;
            }
        }
    }
    printf("\nFractional Kanpsack problem using GD");
    for(i=0; i<n; i++)
    {
        if(weight[i] > capacity)
        {
            break;
        }
        else
        {
            totalprofit = totalprofit + profit[i];
            capacity = capacity - weight[i];
        }
    }

    if(i<n)
    {
        totalprofit = totalprofit + (ratio[i]*capacity);
        printf("\nTotal profit : %f ", totalprofit);
    }
    return 0;
}