// Quick Sort (Divide & Conquer) (30-01)

#include<iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for(int i = start + 1; i <= end; i++)
    {
        if(arr[i] <= pivot)
            count++;
    }

    // Given pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    
    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    // Base Case
    if(start >= end)
        return;

    // Partitioning The Array
    int p = partition(arr, start, end);

    // Sorting
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[50], n, i;

    cout << "Enter The Size: ";
    cin >> n;
    cout << "Enter " << n << " Numbers: ";

    for(i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Sorting The Array Using Quick Sort Algorithm...\n";

    quickSort(arr, 0, n - 1);

    cout << "The Sorted Elements: ";

    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
Sample Input/Output:

Enter The Size: 6
Enter 6 Numbers: 9 3 4 2 1 8
Sorting The Array Using Quick Sort Algorithm...
The Sorted Elements: 1 2 3 4 8 9 

*/
