// Travelling Salesman Problem

#include<stdio.h>

int ary[10][10], completed[10], n, cost = 0;

int least(int c);

void takeInput()
{
    int i, j;

    printf("Enter The Number of Villages: ");
    scanf("%d", &n);

    printf("\nEnter The Cost of Matrix\n");

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Elements of Row: %d\n", i + 1);

        for(j = 0; j < n; j++)
            scanf("%d", &ary[i][j]);

        completed[i] = 0;
    }

    printf("\n\nThe Cost List is: ");

    for(i = 0; i < n; i++)
    {
        printf("\n");

        for(j = 0; j < n; j++)
            printf("\t%d", ary[i][j]);
    }
}


void mincost(int city)
{
    int i, ncity;
    completed[city] = 1;

    printf("%d --> ", city + 1);

    ncity = least(city);

    if(ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity + 1);

        cost += ary[city][ncity];

        return;
    }

    mincost(ncity);
}

int least(int c)
{
    int i, nc = 999, min = 999, kmin;

    for(i = 0; i < n; i++)
    {
        if((ary[c][i] != 0) && (completed[i] == 0))
        {
            if(ary[c][i] + ary[i][c] < min)
            {
                min = ary[i][0] + ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
        }
    }

    if(min != 999)
        cost += kmin;

    return nc;
}


int main()
{
    takeInput();

    printf("\n\nThe Path is:\n");

    mincost(0);     // Passing 0 because starting vertex

    printf("\n\nMinimum Cost is: %d\n", cost);

    return 0;
}



/*

Sample Input/Output:

Enter The Number of Villages: 4

Enter The Cost of Matrix

Enter Elements of Row: 1
0 16 11 6

Enter Elements of Row: 2
8 0 13 16

Enter Elements of Row: 3
4 7 0 9

Enter Elements of Row: 4
5 12 2 0


The Cost List is:
        0       16      11      6
        8       0       13      16
        4       7       0       9
        5       12      2       0

The Path is:
1 --> 4 --> 3 --> 2 --> 1

Minimum Cost is: 23

*/
