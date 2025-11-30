#include <iostream>
#include <climits>
using namespace std;

bool isBSTUtil(int arr[], int n, int idx, long long minVal, long long maxVal)
{
    if (idx >= n || arr[idx] == -1)
        return true;
    if (arr[idx] <= minVal || arr[idx] >= maxVal)
        return false;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    return isBSTUtil(arr, n, left, minVal, arr[idx]) &&
           isBSTUtil(arr, n, right, arr[idx], maxVal);
}

int main()
{
    int n;
    cout << "Enter number of nodes in the complete binary tree: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " node values in level order (-1 for no node): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (isBSTUtil(arr, n, 0, LLONG_MIN, LLONG_MAX))
        cout << "The given binary tree is a BST." << endl;
    else
        cout << "The given binary tree is not a BST." << endl;
    delete[] arr;
    return 0;
}
