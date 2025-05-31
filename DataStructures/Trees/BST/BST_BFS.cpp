#include <iostream>
#include <queue>
using namespace std;

// TreeNode class representing a node in the binary search tree (BST)
class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize TreeNode with given key
    TreeNode(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

// BinarySearchTree class for performing BFS traversal on a BST
class BinarySearchTree {
private:
    TreeNode* root;

public:
    // Constructor to initialize an empty BST
    BinarySearchTree() {
        root = nullptr;
    }

    // Method to insert a new key into the BST
    void insert(int key) {
        root = insertNode(root, key);
    }

    // Helper function to recursively insert a new key into the BST
    TreeNode* insertNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key);
        }
        return node;
    }

    // Perform Breadth-First Search (BFS) traversal of the BST
    void bfsTraversal() {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        cout << "BFS traversal (BST): ";
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};

// Main function to test the BinarySearchTree class
int main() {
    BinarySearchTree bst;

    // Insert keys into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform BFS traversal on the BST
    bst.bfsTraversal();

    return 0;
}
