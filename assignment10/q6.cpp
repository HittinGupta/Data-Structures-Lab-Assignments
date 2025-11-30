#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

Node *buildTree(const vector<int> &arr, int i)
{
    if (i >= (int)arr.size() || arr[i] == -1)
        return NULL;
    Node *root = new Node(arr[i]);
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);
    return root;
}

bool hasDuplicate(Node *root, unordered_set<int> &seen)
{
    if (!root)
        return false;
    if (seen.count(root->val))
        return true;
    seen.insert(root->val);
    return hasDuplicate(root->left, seen) || hasDuplicate(root->right, seen);
}

int main()
{
    int n;
    cout << "Enter number of nodes in level-order array representation of the tree: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " values (-1 for NULL nodes) in level order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = buildTree(arr, 0);
    unordered_set<int> seen;

    bool dup = hasDuplicate(root, seen);
    if (dup)
        cout << "Duplicates Found" << endl;
    else
        cout << "No Duplicates" << endl;

    return 0;
}
