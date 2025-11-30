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

    cout << "Frequency of each number:\n";
    for (auto &p : freq)
    {
        cout << p.first << " -> " << p.second << endl;
    }
    return 0;
}
