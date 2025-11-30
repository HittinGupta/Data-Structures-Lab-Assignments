#include <iostream>
using namespace std;

#define MAX 100

int heapArr[MAX];
int heapSize = 0;

void swapInt(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void heapifyDown(int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < heapSize && heapArr[l] > heapArr[largest])
        largest = l;
    if (r < heapSize && heapArr[r] > heapArr[largest])
        largest = r;
    if (largest != i)
    {
        swapInt(heapArr[i], heapArr[largest]);
        heapifyDown(largest);
    }
}

void heapifyUp(int i)
{
    while (i != 0)
    {
        int parent = (i - 1) / 2;
        if (heapArr[parent] < heapArr[i])
        {
            swapInt(heapArr[parent], heapArr[i]);
            i = parent;
        }
        else
            break;
    }
}

void insertKey(int key)
{
    if (heapSize == MAX)
    {
        cout << "Priority queue overflow." << endl;
        return;
    }
    heapArr[heapSize] = key;
    heapifyUp(heapSize);
    heapSize++;
}

int getMax()
{
    if (heapSize <= 0)
        return -1;
    return heapArr[0];
}

int extractMax()
{
    if (heapSize <= 0)
        return -1;
    if (heapSize == 1)
    {
        heapSize--;
        return heapArr[0];
    }
    int root = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return root;
}

void displayPQ()
{
    if (heapSize == 0)
    {
        cout << "Priority queue is empty." << endl;
        return;
    }
    cout << "Priority queue elements (heap array): ";
    for (int i = 0; i < heapSize; i++)
        cout << heapArr[i] << " ";
    cout << endl;
}

int main()
{
    int choice, val;
    do
    {
        cout << "\nPriority Queue Using Max-Heap Menu\n";
        cout << "1. Insert\n";
        cout << "2. Get maximum\n";
        cout << "3. Extract maximum\n";
        cout << "4. Display priority queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            insertKey(val);
            break;
        case 2:
            val = getMax();
            if (val == -1)
                cout << "Priority queue is empty." << endl;
            else
                cout << "Maximum value is: " << val << endl;
            break;
        case 3:
            val = extractMax();
            if (val == -1)
                cout << "Priority queue is empty." << endl;
            else
                cout << "Extracted maximum value: " << val << endl;
            break;
        case 4:
            displayPQ();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
