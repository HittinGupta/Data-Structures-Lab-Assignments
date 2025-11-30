#include <iostream>
using namespace std;

struct CNode
{
    int data;
    CNode *next;
};

CNode *chead = NULL;

void cInsertFirst(int x)
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
    n->next = chead;
    t->next = n;
    chead = n;
}

void cInsertLast(int x)
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

void cInsertBefore(int key, int x)
{
    if (!chead)
        return;
    if (chead->data == key)
    {
        cInsertFirst(x);
        return;
    }
    CNode *prev = chead;
    CNode *curr = chead->next;
    while (curr != chead && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == chead)
        return;
    CNode *n = new CNode();
    n->data = x;
    prev->next = n;
    n->next = curr;
}

void cInsertAfter(int key, int x)
{
    if (!chead)
        return;
    CNode *curr = chead;
    do
    {
        if (curr->data == key)
        {
            CNode *n = new CNode();
            n->data = x;
            n->next = curr->next;
            curr->next = n;
            return;
        }
        curr = curr->next;
    } while (curr != chead);
}

void cDeleteValue(int key)
{
    if (!chead)
        return;
    if (chead->data == key && chead->next == chead)
    {
        delete chead;
        chead = NULL;
        return;
    }
    CNode *curr = chead;
    CNode *prev = NULL;
    do
    {
        if (curr->data == key)
        {
            if (!prev)
            {
                CNode *tail = chead;
                while (tail->next != chead)
                    tail = tail->next;
                chead = chead->next;
                tail->next = chead;
                delete curr;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != chead);
}

int cSearch(int key)
{
    if (!chead)
        return -1;
    int pos = 1;
    CNode *t = chead;
    do
    {
        if (t->data == key)
            return pos;
        t = t->next;
        pos++;
    } while (t != chead);
    return -1;
}

void cDisplay()
{
    if (!chead)
    {
        cout << "List is empty." << endl;
        return;
    }
    CNode *t = chead;
    cout << "Circular Linked List: ";
    do
    {
        cout << t->data << " ";
        t = t->next;
    } while (t != chead);
    cout << endl;
}

int main()
{
    int choice, val, key;
    do
    {
        cout << "\nCircular Linked List Menu\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a specific node\n";
        cout << "4. Insert after a specific node\n";
        cout << "5. Delete a specific node\n";
        cout << "6. Search for a node\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            cInsertFirst(val);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> val;
            cInsertLast(val);
            break;
        case 3:
            cout << "Enter value of node before which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            cInsertBefore(key, val);
            break;
        case 4:
            cout << "Enter value of node after which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            cInsertAfter(key, val);
            break;
        case 5:
            cout << "Enter value of node to delete: ";
            cin >> key;
            cDeleteValue(key);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            val = cSearch(key);
            if (val == -1)
                cout << "Node not found." << endl;
            else
                cout << "Node found at position " << val << "." << endl;
            break;
        case 7:
            cDisplay();
            break;
        case 8:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 8);
    return 0;
}
