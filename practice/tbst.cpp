#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded; // Indicates if the right pointer is threaded
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->isThreaded = false;
    return newNode;
}

// Function to insert a new node into the threaded BST
Node* insert(Node* root, int data) {
    if (!root)
        return createNode(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
        if (root->left->right == nullptr) {
            root->left->right = root;
            root->left->isThreaded = true;
        }
    } else {
        if (root->isThreaded || root->right == nullptr) {
            Node* temp = createNode(data);
            temp->right = root->right;
            root->right = temp;
            root->isThreaded = false;
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Function to do inorder traversal of TBST



int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);

    cout << "Inorder traversal of threaded BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
