#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int BinarySearchRecursive(int arr[], int l, int r, int k)
{
    if (l > r)
        return -1;

    int m = (l + r) / 2;

    if (k == arr[m])
        return m;
    else if (k < arr[m])
        return BinarySearchRecursive(arr, l, m - 1, k);
    else
        return BinarySearchRecursive(arr, m + 1, r, k);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0, r = n - 1;
    int k = 7;

    int result1 = BinarySearch(arr, n, k);
    int result2 = BinarySearchRecursive(arr, l, r, k);

    if (result1 != -1)
        cout << "Element found at index (Iterative): " << result1 << endl;

    if (result2 != -1)
        cout << "Element found at index (Recursive): " << result2 << endl;

    if (result1 == -1 && result2 == -1)
        cout << "Element not found";

    return 0;
}
