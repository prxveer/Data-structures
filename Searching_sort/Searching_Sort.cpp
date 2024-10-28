#include<iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    for(int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for(int j = i + 1; j <= n - 1; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n;
    cout << "Give input: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    selection_sort(arr, n);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }    
    return 0;
}
