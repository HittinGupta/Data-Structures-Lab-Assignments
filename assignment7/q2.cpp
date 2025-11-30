#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int minIndex = i;
        int maxIndex = i;

        for (int j = i; j < n - i; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);

        if (maxIndex == i)
        {
            maxIndex = minIndex;
        }

        swap(arr[n - i - 1], arr[maxIndex]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n--- Improved Selection Sort ---\n";

    cout << "\nOriginal Array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}