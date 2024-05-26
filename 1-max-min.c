// 1. Max-Min (Divide & Conquer Method) (09-01)
// Group- Q (061-125)

#include <stdio.h>

int max, min, a[100];

void maxmin(int i, int j)
{
    int max1, min1, mid;

    if(i == j)
        max = min = a[i];

    else
    {
        if(i == j - 1)
        {
            if(a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        
        else
        {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);

            if(max < max1)
                max = max1;

            if(min > min1)
                min = min1;
        }
    }
}

int main()
{
    int i, n;

    printf("Enter The Total Number of Numbers: ");
    scanf("%d", &n);
    printf("Enter The Numbers: ");

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    max = a[0];
    min = a[0];
    maxmin(1, n);

    printf("\nMinimum Element In An Array: %d\n", min);
    printf("Maximum Element In An Array: %d\n", max);

    return 0;
}


/*
Sample Input/Output:

Enter The Total Number of Numbers: 5
Enter The Numbers: 20 30 50 40 10

Minimum Element In An Array: 10
Maximum Element In An Array: 50

*/
