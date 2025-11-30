#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertNode(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insertNode(root->right, val);
    }
    else
    {
        cout << "Duplicate value " << val << " not inserted.\n";
    }

    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
    {
        cout << "Value " << val << " not found in the tree.\n";
        return root;
    }

    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        // no child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // one child
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // two child
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int maxDepth(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int minDepth(Node *root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right != nullptr)
    {
        return 1 + minDepth(root->right);
    }
    if (root->right == nullptr && root->left != nullptr)
    {
        return 1 + minDepth(root->left);
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int choice, val;

    while (true)
    {
        cout << "\n--- BST Operations ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Maximum Depth\n";
        cout << "5. Minimum Depth\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insertNode(root, val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;

        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
            break;

        case 5:
            cout << "Minimum Depth of BST: " << minDepth(root) << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}