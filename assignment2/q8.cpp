#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        bool isDistinct = true;
        // check if arr[i] appeared before
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct)
        {
            count++;
        }
    }

    cout << "Distinct elements: " << count;

    return 0;
}