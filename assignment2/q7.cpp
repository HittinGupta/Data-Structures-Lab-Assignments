#include <iostream>
using namespace std;

int countInversions(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = 5;
    cout << "Inversions: " << countInversions(arr, n);
    return 0;
}