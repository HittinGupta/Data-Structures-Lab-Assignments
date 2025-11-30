#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int choice;
    cout << "Choose order:\n1. Increasing\n2. Decreasing\nEnter choice: ";
    cin >> choice;
    heapSort(arr, n);
    if (choice == 1)
    {
        cout << "Array in increasing order: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    else
    {
        cout << "Array in decreasing order: ";
        for (int i = n - 1; i >= 0; i--)
            cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
