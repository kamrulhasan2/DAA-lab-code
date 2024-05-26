#include<stdio.h>

// s = Density, w = Weight, p = Profit, n = Items
void knapsack(float s[], float w[], float p[], int n)
{
    int i, j;
    float t, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j] < s[j + 1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int m, n, i, rest;
    float p[10], w[10], s[10], x[10], profit;

    printf("Bag Size: ");
    scanf("%d", &m);

    printf("How Manny Items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\n%d. ", i);

        printf("Weight: ");
        scanf("%f", &w[i]);

        printf("   Profit: ");
        scanf("%f", &p[i]);
    }

    for(i = 0; i < n; i++)
        s[i] = p[i] / w[i];

    knapsack(s, w, p, n);       // s = Density, w = Weight, p = Profit, n = Items

    rest = m;
    profit = 0;

    for(i = 0; i < n; i++)
        x[i] = 0.0;

    for(i = 0; i < n; i++)
    {
        if(w[i] > rest)
            break;

        x[i] = 1.0;
        profit = profit + p[i];
        rest = rest - w[i];   
    }

    if(i < n)
    {
        x[i] = rest/w[i];
        profit = profit + (x[i] * p[i]);
    }

    printf("\tProfit\tWeight\n");

    for(i = 0; i < n; i++)
    {
        printf("\t%.2f", w[i]);
        printf("\t%.2f", p[i]);
        printf("\n");
    }

    printf("\n");

    for(i = 0; i < n; i++)
        printf("\t%.2f", x[i]);

    printf("\n\nProfit: %.2f\n", profit);

    return 0;
}

/*
Sample Input/Output:

Bag Size: 15
How Manny Items: 7

1. Weight: 1
   Profit: 5

2. Weight: 3
   Profit: 10

3. Weight: 5
   Profit: 15

4. Weight: 4
   Profit: 7

5. Weight: 1
   Profit: 8

6. Weight: 3
   Profit: 9

7. Weight: 2
   Profit: 4
        Profit  Weight
        1.00    8.00
        1.00    5.00
        3.00    10.00
        5.00    15.00
        3.00    9.00
        2.00    4.00
        4.00    7.00

        1.00    1.00    1.00    1.00    1.00    1.00    0.00    1.00    1.00    0.00

Profit: 51.00


Bag Size: 16
How Manny Items: 6

0. Weight: 6
   Profit: 6

1. Weight: 10
   Profit: 2

2. Weight: 3
   Profit: 1

3. Weight: 5
   Profit: 8

4. Weight: 1
   Profit: 3

5. Weight: 3
   Profit: 5
        Profit  Weight
        1.00    3.00
        3.00    5.00
        5.00    8.00
        6.00    6.00
        3.00    1.00
        10.00   2.00

        1.00    1.00    1.00    1.00 0.33  0.00

Profit: 22.33


*/
