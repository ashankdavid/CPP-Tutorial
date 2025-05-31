#include <iostream>
#include <unordered_set>
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

    // Helper function to perform inorder traversal and search for pair
    bool findPairUntil(Node* root, int k, unordered_set<int>& visited) {
        if (root == nullptr)
            return false;

        // Check if current node's complement has been visited
        if (visited.count(k - root->key) > 0)
            return true;

        // Mark current node as visited
        visited.insert(root->key);

        // Recursively search in the left and right subtrees
        return findPairUntil(root->left, k, visited) || findPairUntil(root->right, k, visited);
    }

public:
    BST() {
        root = nullptr;
    }

    // Public method to insert a key into the BST
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Public method to find a pair of distinct nodes with sum k
    bool findPair(int k) {
        unordered_set<int> visited;
        return findPairUntil(root, k, visited);
    }
};

// Main function to test the BST implementation
int main() {
    BST bst;

    // Insert keys into the BST
    bst.insert(8);
    bst.insert(3);
    bst.insert(11);
    bst.insert(1);
    bst.insert(6);
    bst.insert(4);
    bst.insert(7);
    bst.insert(15);
    bst.insert(13);

    // Find pair with sum 14
    int targetSum = 14;
    if (bst.findPair(targetSum)) {
        cout << "Pair with sum " << targetSum << " exists in the BST." << endl;
    } else {
        cout << "Pair with sum " << targetSum << " does not exist in the BST." << endl;
    }

    // Find pair with sum 20
    targetSum = 20;
    if (bst.findPair(targetSum)) {
        cout << "Pair with sum " << targetSum << " exists in the BST." << endl;
    } else {
        cout << "Pair with sum " << targetSum << " does not exist in the BST." << endl;
    }

    // Find pair with sum 10
    targetSum = 10;
    if (bst.findPair(targetSum)) {
        cout << "Pair with sum " << targetSum << " exists in the BST." << endl;
    } else {
        cout << "Pair with sum " << targetSum << " does not exist in the BST." << endl;
    }

    return 0;
}
