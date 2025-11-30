
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

void insertBeg(int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = NULL;
    if (!head)
    {
        head = n;
        return;
    }
    Node *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
}

void insertBefore(int val, int x)
{
    if (!head)
        return;
    if (head->data == val)
    {
        insertBeg(x);
        return;
    }
    Node *t = head;
    while (t->next && t->next->data != val)
        t = t->next;
    if (t->next)
    {
        Node *n = new Node();
        n->data = x;
        n->next = t->next;
        t->next = n;
    }
}

void insertAfter(int val, int x)
{
    Node *t = head;
    while (t && t->data != val)
        t = t->next;
    if (t)
    {
        Node *n = new Node();
        n->data = x;
        n->next = t->next;
        t->next = n;
    }
}

void delBeg()
{
    if (!head)
        return;
    Node *t = head;
    head = head->next;
    delete t;
}

void delEnd()
{
    if (!head)
        return;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *t = head;
    while (t->next->next)
        t = t->next;
    delete t->next;
    t->next = NULL;
}

void delSpecific(int x)
{
    if (!head)
        return;
    if (head->data == x)
    {
        delBeg();
        return;
    }
    Node *t = head;
    while (t->next && t->next->data != x)
        t = t->next;
    if (t->next)
    {
        Node *d = t->next;
        t->next = d->next;
        delete d;
    }
}

int searchNode(int x)
{
    int pos = 1;
    Node *t = head;
    while (t)
    {
        if (t->data == x)
            return pos;
        t = t->next;
        pos++;
    }
    return -1;
}

void display()
{
    Node *t = head;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main()
{
    int ch, x, val;
    do
    {
        cin >> ch;
        if (ch == 1)
        {
            cin >> x;
            insertBeg(x);
        }
        else if (ch == 2)
        {
            cin >> x;
            insertEnd(x);
        }
        else if (ch == 3)
        {
            cin >> val >> x;
            insertBefore(val, x);
        }
        else if (ch == 4)
        {
            cin >> val >> x;
            insertAfter(val, x);
        }
        else if (ch == 5)
            delBeg();
        else if (ch == 6)
            delEnd();
        else if (ch == 7)
        {
            cin >> x;
            delSpecific(x);
        }
        else if (ch == 8)
        {
            cin >> x;
            cout << searchNode(x) << endl;
        }
        else if (ch == 9)
            display();
    } while (ch != 10);
    return 0;
}
