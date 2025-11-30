#include <iostream>
using namespace std;

struct DNode
{
    char data;
    DNode *prev;
    DNode *next;
};

DNode *head = NULL;
DNode *tail = NULL;

void insertEnd(char ch)
{
    DNode *n = new DNode();
    n->data = ch;
    n->next = NULL;
    if (!head)
    {
        n->prev = NULL;
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

bool isPalindrome()
{
    if (!head)
        return true;
    DNode *left = head;
    DNode *right = tail;
    while (left != right && right->next != left)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter a string (characters for doubly linked list): ";
    cin >> s;
    for (char c : s)
        insertEnd(c);
    if (isPalindrome())
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;
    return 0;
}
