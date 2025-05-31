#include <iostream>
#include <queue>
using namespace std;

// Node structure for AVL Tree
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1; // height of a new node is 1
    }
};

// AVL Tree class
class AVLTree {
private:
    Node* root;

    // Helper function to get the height of a node
    int getHeight(Node* node) {
        if (!node) return 0;  // Return 0 if the node is null
        return node->height;   // Otherwise, return the node's height
    }

    // Helper function to get the balance factor of a node
    int getBalance(Node* node) {
        if (!node) return 0;  // If the node is null, return balance as 0
        int leftHeight = getHeight(node->left);  // Get height of left subtree
        int rightHeight = getHeight(node->right);  // Get height of right subtree
        return leftHeight - rightHeight;  // Balance factor is the difference
    }

    // Helper function to right rotate subtree rooted with y
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // Return new root
        return x;
    }

    // Helper function to left rotate subtree rooted with x
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // Return new root
        return y;
    }

    // Helper function to recursively insert a key into the AVL tree
    Node* insertRec(Node* node, int key) {
        // 1. Perform the normal BST insert
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        } else {
            // Equal keys not allowed in BST
            return node;
        }

        // 2. Update the height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Helper function to perform inorder traversal of the AVL tree
    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->key << " ";
            inorderRec(root->right);
        }
    }

    // Helper function to perform level-order traversal (BFS) using a queue
    void bfsHelper(Node* root) {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    // Public method to insert a key into the AVL tree
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Public method to perform inorder traversal of the AVL tree
    void inorderTraversal() {
        inorderRec(root);
        cout << endl;
    }

    // Public method to perform Breadth-First Search (BFS) traversal of the AVL tree
    void bfsTraversal() {
        bfsHelper(root);
        cout << endl;
    }
};

// Main function to test the AVL tree implementation
int main() {
    AVLTree avl;

    // Insert some keys into the AVL tree
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    // Perform inorder traversal of the AVL tree
    cout << "Inorder traversal of AVL tree: ";
    avl.inorderTraversal();

    // Perform BFS traversal of the AVL tree
    cout << "BFS traversal of AVL tree: ";
    avl.bfsTraversal();

    return 0;
}
