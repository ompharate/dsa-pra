#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    bool isThreaded;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->isThreaded = false;
    return temp;
}

Node *insertNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return newNode(key);
    }

    if (key < root->key)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insertNode(root->right, key);
    }

    return root;
}

Node *buildTreeFromInput()
{
    Node *root = nullptr;
    int value;

    cout << "Enter root data: ";
    cin >> value;
    root = newNode(value);

    while (true)
    {
        cout << "Enter node data (or -1 to stop): ";
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insertNode(root, value);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    Node *current = root;

    while (current->left != nullptr)
    {
        current = current->left;
    }

    while (current != nullptr)
    {
        cout << current->key << " ";

        if (current->isThreaded)
        {
            current = current->right;
        }
        else
        {
            current = current->right;
            if (current != nullptr)
            {
                while (current->left != nullptr)
                {
                    current = current->left;
                }
            }
        }
    }
}

void createThread(Node *root, Node *&prev)
{
    if (root == nullptr)
    {
        return;
    }

    createThread(root->left, prev);

    if (prev != nullptr && prev->right == nullptr)
    {
        prev->right = root;
        prev->isThreaded = true;
    }

    prev = root;

    createThread(root->right, prev);
}

int main()
{
    Node *root = buildTreeFromInput();

    Node *prev = nullptr;
    createThread(root, prev);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
