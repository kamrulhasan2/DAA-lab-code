// 2. Merge Sort Algorithm (16-01)

#include <iostream>
using namespace std;

void Merge(int a[], int low, int mid, int high)
{
    int b[80], h, i, j, k;

    h = low;
    i = low;
    j = mid + 1;

    while((h <= mid) && (j <= high))
    {
        if(a[h] <= a[j])
            b[i++] = a[h++];

        else
            b[i++] = a[j++];
    }

    if(h > mid)
    {
        for(k = j; k <= high; k++)
            b[i++] = a[k];        
    }

    else
    {
        for(k = h; k <= mid; k++)
            b[i++] = a[k];
    }

    for(k = low; k <= high; k++)
        a[k] = b[k];
}

void Mergesort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        Mergesort(a, low, mid);
        Mergesort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int n, a[100];

    cout << "How Many Elements You Want To Enter: ";
    cin >> n;
    cout << "Enter Elements: ";

    for(int i = 0; i < n; i++)
        cin >> a[i];

    Mergesort(a, 0, n - 1);

    cout << "After Merge Sort: ";

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n";

    return 0;
}

/*
Sample Input/Output:

How Many Elements You Want To Enter: 5
Enter Elements: 2 5 4 1 3
After Merge Sort: 1 2 3 4 5 

*/
