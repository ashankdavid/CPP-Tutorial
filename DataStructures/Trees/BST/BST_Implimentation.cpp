#include <iostream>
#include<queue>
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

    // Helper function to recursively search for a key in the BST
    bool searchRec(Node* root, int key) {
        if (root == nullptr) {
            return false;
        }

        if (root->key == key) {
            return true;
        } else if (key < root->key) {
            return searchRec(root->left, key);
        } else {
            return searchRec(root->right, key);
        }
    }

    // Helper function to perform inorder traversal of the BST
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

    // Helper function to find the minimum node in a subtree
    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to recursively delete a key from the BST
    Node* deleteRec(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRec(root->right, key);
        } else {
            // Node to be deleted found

            // Case 1: No child or one child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node with two children
            Node* temp = findMin(root->right); // finding inroder successor, to maintain bst properties
            root->key = temp->key;
            root->right = deleteRec(root->right, temp->key);
        }
        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    // Public method to insert a key into the BST
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Public method to search for a key in the BST
    bool search(int key) {
        return searchRec(root, key);
    }

    // Public method to delete a key from the BST
    void remove(int key) {
        root = deleteRec(root, key);
    }

    // Public method to perform inorder traversal of the BST
    void inorderTraversal() {
        inorderRec(root);
        cout << endl;
    }

    // Public method to perform Breadth-First Search (BFS) traversal of the BST
    void bfsTraversal() {
        bfsHelper(root);
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
    cout << "Inorder traversal of BST: ";
    bst.inorderTraversal();

    // Perform BFS traversal of the BST
    cout << "BFS traversal of BST: ";
    bst.bfsTraversal();

    // Search for a key in the BST
    int key = 60;
    if (bst.search(key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " not found in the BST." << endl;
    }

    // Delete a key from the BST
    key = 30;
    bst.remove(key);
    cout << "Inorder traversal after deleting " << key << ": ";
    bst.inorderTraversal();

    // Search for a key not in the BST
    key = 90;
    if (bst.search(key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " not found in the BST." << endl;
    }

    return 0;
}
