#include <iostream>
using namespace std;

// Define a node structure for the BST
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Helper function to recursively insert a key into the BST
    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            root = new Node(key);
            return root;
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }

        return root;
    }

    // Helper function to perform inorder traversal recursively
    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->key << " ";
            inorderRec(root->right);
        }
    }

    // Helper function to perform preorder traversal recursively
    void preorderRec(Node* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    // Helper function to perform postorder traversal recursively
    void postorderRec(Node* root) {
        if (root != nullptr) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->key << " ";
        }
    }

public:
    BST() {
        root = nullptr;
    }

    // Public method to insert a key into the BST
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Public method to perform inorder traversal of the BST
    void inorderTraversal() {
        cout << "Inorder traversal: ";
        inorderRec(root);
        cout << endl;
    }

    // Public method to perform preorder traversal of the BST
    void preorderTraversal() {
        cout << "Preorder traversal: ";
        preorderRec(root);
        cout << endl;
    }

    // Public method to perform postorder traversal of the BST
    void postorderTraversal() {
        cout << "Postorder traversal: ";
        postorderRec(root);
        cout << endl;
    }
};

// Main function to test the BST implementation
int main() {
    BST bst;

    // Insert some keys into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform inorder traversal of the BST
    bst.inorderTraversal();

    // Perform preorder traversal of the BST
    bst.preorderTraversal();

    // Perform postorder traversal of the BST
    bst.postorderTraversal();

    return 0;
}
