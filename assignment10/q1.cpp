#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_set<int> s;
    bool hasDup = false;
    for (int x : nums)
    {
        if (s.count(x))
        {
            hasDup = true;
            break;
        }
        s.insert(x);
    }

    cout << "Contains duplicates? " << (hasDup ? "true" : "false") << endl;
    return 0;
}
