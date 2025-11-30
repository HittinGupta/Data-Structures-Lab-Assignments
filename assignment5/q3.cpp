#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head3 = NULL;

void push3(int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = head3;
    head3 = n;
}

int middle()
{
    Node *slow = head3;
    Node *fast = head3;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    push3(5);
    push3(4);
    push3(3);
    push3(2);
    push3(1);
    cout << middle();
    return 0;
}
