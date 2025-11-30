#include <iostream>
#include <vector>
#include <unordered_map>
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

    unordered_map<int, int> freq;
    for (int x : nums)
        freq[x]++;

    int ans = -1;
    for (int x : nums)
    {
        if (freq[x] == 1)
        {
            ans = x;
            break;
        }
    }

    if (ans == -1)
        cout << "No non-repeating element found." << endl;
    else
        cout << "First non-repeating element: " << ans << endl;

    return 0;
}
