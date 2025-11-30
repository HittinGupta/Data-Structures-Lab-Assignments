#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head4 = NULL;

void push4(int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = head4;
    head4 = n;
}

void reverse()
{
    Node *prev = NULL;
    Node *curr = head4;
    while (curr)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head4 = prev;
}

void print4()
{
    Node *t = head4;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int main()
{
    push4(3);
    push4(2);
    push4(1);
    reverse();
    print4();
    return 0;
}
