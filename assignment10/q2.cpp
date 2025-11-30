#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> A(n1);
    cout << "Enter " << n1 << " integers for first array: ";
    for (int i = 0; i < n1; i++)
        cin >> A[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> B(n2);
    cout << "Enter " << n2 << " integers for second array: ";
    for (int i = 0; i < n2; i++)
        cin >> B[i];

    unordered_set<int> s(A.begin(), A.end());
    unordered_set<int> printed;

    cout << "Common elements: ";
    for (int x : B)
    {
        if (s.count(x) && !printed.count(x))
        {
            cout << x << " ";
            printed.insert(x);
        }
    }
    cout << endl;
    return 0;
}
