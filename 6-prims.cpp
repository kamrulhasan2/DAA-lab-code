// Prim's Algorithm

#include<iostream>

#define INF 25000
#define R 50

using namespace std;

// Function Prototype

int total, n, t[R][3], cost[R][R];

int input();
void display(int mincost);
int Prim();

// Main Fuction

int main()
{
    int q, mincost;

    do
    {
        cout << "1. Input Data\n";
        cout << "2. Evalute Minimum-Cost Spanning Tree\n";
        cout << "3. Exit\n\n";
        cout << "Enter Choice: ";

        cin >> q;

        if(q == 1)
            n = input();

        else if(q == 2)
        {
            mincost = Prim();
            display(mincost);
        }
    }while(q != 3);
}

void display(int mincost)
{
    int i;

    cout << "\n\nPrim's Minimum-Cost Spanning Tree is: " << mincost << endl;
    cout << "The Spanning Tree is:\n\n";

    for(i = 1; i <= total; i++)
        cout << t[i][1] << " -> " << t[i][2] << endl;

    cout << "\n\n";
}

// Data Input

int input()
{
    int V, x, y, kost;

    cout << "Enter Number of Vertices: ";
    cin >> V;

    for(x = 0; x <= V; x++)    // Elements of Cost[][] is Initiazing by Infinite
    {
        for(y = 0; y <= V; y++)
        {
            cost[x][y] = INF;
            cost[y][x] = INF;
        }
    }

    do 
    {
        cout << "\nEnter Edge (-1, -1 to Exit): ";
        cin >> x >> y;

        if(x == -1 || y == -1)
            break;

        cout << "Enter Cost: ";
        cin >> kost;

        cost[x][y] = kost;
        cost[y][x] = kost;

    }while(1);

    return V;
}

// Prim's Minimum-Cost Spanning Tree

int Prim()
{
    int i, j, k, l, mincost, adjacent[R];

    k = l = 1; 
    total = 0;

    for(i = 1; i <= n; i++)     // Finding an Edge of Minimum Cost
    {
        for(j = 1; j <= n; j++)
        {
            if(cost[i][j] < cost[k][l])
            {
                k = i;
                l = j;
            }
        }
    }

    mincost = cost[k][l];
    t[1][1] = k;
    t[1][2] = l;
    total++;

    for(i = 2; i <= n; i++)
    {
        if(cost[i][l] < cost[i][k])
            adjacent[i] = l;

        else
            adjacent[i] = k;
    }

    adjacent[k] = adjacent[l] = 0;

    for(i = 2; i < n; i++)
    {
        l = INF;

        for(k = 1; k <= n; k++)
        {
            if(cost[k][adjacent[k]] < l)
            {
                l = cost[k][adjacent[k]];
                j = k;
            }
        }

        t[i][1] = adjacent[j];
        t[i][2] = j;
        total++;
        mincost = mincost + cost[j][adjacent[j]];
        adjacent[j] = 0;

        // Updating adjacent[]
        for(k = 1; k <= n; k++)
        {
            if(adjacent[k] != 0 && cost[k][adjacent[k]] > cost [k][j])
                adjacent[k] = j;
        }

    }

    return mincost;
}


/*
Sample Input/Output:

1. Input Data
2. Evalute Minimum-Cost Spanning Tree
3. Exit

Enter Choice: 1
Enter Cost: 4
Enter Edge (-1, -1 to Exit): 4 3
Enter Cost: 2
Enter Edge (-1, -1 to Exit): 4 5
Enter Cost: 1
Enter Edge (-1, -1 to Exit): 2 3
Enter Cost: 10
Enter Edge (-1, -1 to Exit): 5 3
Enter Cost: 6
Enter Edge (-1, -1 to Exit): 3 1
Enter Cost: 3
Enter Edge (-1, -1 to Exit): -1 -1
1. Input Data
2. Evalute Minimum-Cost Spanning Tree
3. Exit

Enter Choice: 2


Prim's Minimum-Cost Spanning Tree is: 10
The Spanning Tree is:

4 -> 5
4 -> 3
3 -> 1
4 -> 2


1. Input Data
2. Evalute Minimum-Cost Spanning Tree
3. Exit

Enter Choice: 3
(Exit)

*/