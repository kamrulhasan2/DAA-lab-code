// 3. Bubble Sort (30-01)

#include<iostream>
using namespace std;

int main()
{
    int n, i, arr[50], j, temp;

    cout << "Enter The Size: ";
    cin >> n;
    cout << "Enter " << n << " Numbers: ";

    for(i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Sorting The Array Using Bubble Sort...\n";

    for(i = 0; i < (n - 1); i++)
    {
        for(j = 0; j < (n - i - 1); j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "The Sorted Elements: ";

    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}


/*
Sample Input/Output:

Enter The Size: 5
Enter 5 Numbers: 4 3 5 1 2
Sorting The Array Using Bubble Sort...
The Sorted Elements: 1 2 3 4 5  

*/
