#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    bool rightThread;

    Node(int val) : data(val), left(nullptr), right(nullptr), rightThread(false) {}
};

class ThreadedBinaryTree {
private:
    Node* root;

public:
    ThreadedBinaryTree() : root(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;
        while (true) {
            if (val < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    newNode->right = curr;
                    newNode->rightThread = true;
                    return;
                }
                curr = curr->left;
            } else {
                if (!curr->rightThread || curr->right == nullptr) {
                    newNode->right = curr->right;
                    curr->right = newNode;
                    curr->rightThread = false;
                    newNode->rightThread = true;
                    return;
                }
                curr = curr->right;
            }
        }
    }

    Node* search(int val) {
        Node* curr = root;
        while (curr != nullptr) {
            if (val == curr->data) return curr;
            else if (val < curr->data) curr = curr->left;
            else if (curr->rightThread) curr = nullptr;
            else curr = curr->right;
        }
        return nullptr;
    }

    void inorderTraversal() {
        Node* curr = root;
        while (curr != nullptr) {
            while (curr->left != nullptr)
                curr = curr->left;
            std::cout << curr->data << " ";

            while (curr->rightThread) {
                curr = curr->right;
                if (curr == nullptr) return;
                std::cout << curr->data << " ";
            }
            curr = curr->right;
        }
    }
};

int main() {
    ThreadedBinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    std::cout << "Inorder traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    int searchValue = 7;
    Node* result = tree.search(searchValue);
    if (result != nullptr)
        std::cout << "Found " << searchValue << " in the tree." << std::endl;
    else
        std::cout << searchValue << " not found in the tree." << std::endl;

    return 0;
}
