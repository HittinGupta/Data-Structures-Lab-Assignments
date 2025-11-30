#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
};

struct CNode
{
    int data;
    CNode *next;
};

DNode *dhead = NULL;
CNode *chead = NULL;

void dInsertEnd(int x)
{
    DNode *n = new DNode();
    n->data = x;
    n->next = NULL;
    if (!dhead)
    {
        n->prev = NULL;
        dhead = n;
        return;
    }
    DNode *t = dhead;
    while (t->next)
        t = t->next;
    t->next = n;
    n->prev = t;
}

void cInsertEnd(int x)
{
    CNode *n = new CNode();
    n->data = x;
    if (!chead)
    {
        n->next = n;
        chead = n;
        return;
    }
    CNode *t = chead;
    while (t->next != chead)
        t = t->next;
    t->next = n;
    n->next = chead;
}

int dSize()
{
    int cnt = 0;
    DNode *t = dhead;
    while (t)
    {
        cnt++;
        t = t->next;
    }
    return cnt;
}

int cSize()
{
    if (!chead)
        return 0;
    int cnt = 0;
    CNode *t = chead;
    do
    {
        cnt++;
        t = t->next;
    } while (t != chead);
    return cnt;
}

int main()
{
    int nd, nc, val;
    cout << "Enter number of nodes for doubly linked list: ";
    cin >> nd;
    cout << "Enter " << nd << " values for doubly linked list: ";
    for (int i = 0; i < nd; i++)
    {
        cin >> val;
        dInsertEnd(val);
    }
    cout << "Size of doubly linked list: " << dSize() << endl;
    cout << "Enter number of nodes for circular linked list: ";
    cin >> nc;
    cout << "Enter " << nc << " values for circular linked list: ";
    for (int i = 0; i < nc; i++)
    {
        cin >> val;
        cInsertEnd(val);
    }
    cout << "Size of circular linked list: " << cSize() << endl;
    return 0;
}
