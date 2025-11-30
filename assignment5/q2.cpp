#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head2 = NULL;

void push(int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = head2;
    head2 = n;
}

int countAndDelete(int key)
{
    int cnt = 0;
    while (head2 && head2->data == key)
    {
        Node *t = head2;
        head2 = head2->next;
        delete t;
        cnt++;
    }
    Node *t = head2;
    while (t && t->next)
    {
        if (t->next->data == key)
        {
            Node *d = t->next;
            t->next = d->next;
            delete d;
            cnt++;
        }
        else
            t = t->next;
    }
    return cnt;
}

void printList()
{
    Node *t = head2;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int main()
{
    push(1);
    push(3);
    push(1);
    push(2);
    push(1);
    push(2);
    push(1);
    int key = 1;
    int c = countAndDelete(key);
    cout << c << endl;
    printList();
    return 0;
}
