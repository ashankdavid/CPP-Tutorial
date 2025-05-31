#include <iostream>
using namespace std;

// TreeNode class representing nodes of the binary tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// BinaryTree class representing the entire binary tree structure
class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    // Method to insert a value into the BST
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // Helper function for recursive insertion
    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->val) {
            node->left = insertRecursive(node->left, val);
        } else {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    // Method to check if the tree is a valid BST
    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    // Helper function for recursive BST validation
    bool isBSTUtil(TreeNode* node, int minValue, int maxValue) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= minValue || node->val >= maxValue) {
            return false;
        }

        return isBSTUtil(node->left, minValue, node->val) &&
               isBSTUtil(node->right, node->val, maxValue);
    }
};

int main() {
    // Example usage of your implemented BinaryTree class
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    // Check if the tree is a BST
    bool isValidBST = tree.isBST();
    cout << "Is the tree a valid BST? " << (isValidBST ? "Yes" : "No") << endl;  // Output: Yes

    return 0;
}
