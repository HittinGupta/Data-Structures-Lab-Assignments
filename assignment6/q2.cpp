#include <iostream>
using namespace std;

struct CNode
{
    int data;
    CNode *next;
};

CNode *head = NULL;

void insertEnd(int x)
{
    CNode *n = new CNode();
    n->data = x;
    if (!head)
    {
        n->next = n;
        head = n;
        return;
    }
    CNode *t = head;
    while (t->next != head)
        t = t->next;
    t->next = n;
    n->next = head;
}

void displayWithHeadRepeat()
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }
    CNode *t = head;
    cout << "Circular Linked List elements: ";
    do
    {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data << endl;
}

int main()
{
    int n, val;
    cout << "Enter number of nodes to insert in circular linked list: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertEnd(val);
    }
    displayWithHeadRepeat();
    return 0;
}
