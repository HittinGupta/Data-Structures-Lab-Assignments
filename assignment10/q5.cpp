#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Empty list. No loop." << endl;
        return 0;
    }

    cout << "Enter " << n << " node values: ";
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    int pos;
    cout << "Enter position (0-based index) where last node should point to create a loop (-1 for no loop): ";
    cin >> pos;

    if (pos >= 0 && pos < n)
    {
        Node *cur = head;
        for (int i = 0; i < pos; i++)
            cur = cur->next;
        tail->next = cur;
    }

    unordered_set<Node *> seen;
    Node *curr = head;
    bool hasLoop = false;

    while (curr)
    {
        if (seen.count(curr))
        {
            hasLoop = true;
            break;
        }
        seen.insert(curr);
        curr = curr->next;
    }

    cout << "Linked list contains loop? " << (hasLoop ? "true" : "false") << endl;
    return 0;
}
