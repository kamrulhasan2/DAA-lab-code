// 9. 11 Color (Graph Coloring)

#include<iostream>
using namespace std;

int i, j, m, n, x[5], g[5][5];

void nextvalue(int k);

void mcoloring(int k)
{
    do 
    {
        nextvalue(k);

        if(!x[k])
            break;

        if(k == n)
        {
            for(int i = 1; i <= n; i++)
                cout << x[i] << ' ';

            cout << endl;
        }

        else
            mcoloring(k + 1);
        
    } while(1);
}


void nextvalue(int k)
{
    do 
    {
        x[k] = (x[k] + 1) % (m + 1);

        if(!x[k])
            return;

        for(int j = 1; j <= k - 1; j++)
        {
            if((g[k][j] != 0) && (x[k] == x[j]))
                break;
        }

        if(j == k)
            return;

    } while(1);
}


int main()
{
    cout << "Enter Vertex Number: ";
    cin >> n;

    cout << "Enter Color Number: ";
    cin >> m;

    for(i = 1; i <= n; i++)
        x[i] = 0;

    cout << "\nEnter Edge Info\n\n";

    for(i = 1; i < n + 1; i++)
    {
        for(j = 1; j < n + 1; j++)
        {
            cout << "Edge From Vertex " << i << " To Vertex " << j << " : ";
            cin >> g[i][j];
        }

        cout << endl;
    }

    mcoloring(1);

    return 0;
}

/*
Sample Input/Output:

Enter Vertex Number: 4 
Enter Color Number: 3

Enter Edge Info

Edge From Vertex 1 To Vertex 1 : 0    
Edge From Vertex 1 To Vertex 2 : 5    
Edge From Vertex 1 To Vertex 3 : 0    
Edge From Vertex 1 To Vertex 4 : 7    

Edge From Vertex 2 To Vertex 1 : 5    
Edge From Vertex 2 To Vertex 2 : 0    
Edge From Vertex 2 To Vertex 3 : 8    
Edge From Vertex 2 To Vertex 4 : 0    

Edge From Vertex 3 To Vertex 1 : 0    
Edge From Vertex 3 To Vertex 2 : 8    
Edge From Vertex 3 To Vertex 3 : 0    
Edge From Vertex 3 To Vertex 4 : 9    

Edge From Vertex 4 To Vertex 1 : 7    
Edge From Vertex 4 To Vertex 2 : 0    
Edge From Vertex 4 To Vertex 3 : 9    
Edge From Vertex 4 To Vertex 4 : 0    

*/
