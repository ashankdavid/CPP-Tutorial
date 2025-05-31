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

    // Helper function to count nodes in the tree
    int countNodes(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Helper function to store tree nodes in an array (inorder traversal)
    void storeNodes(TreeNode* node, TreeNode** nodeList, int& index) {
        if (node == nullptr) return;

        // Recursive traversal (inorder)
        storeNodes(node->left, nodeList, index);
        nodeList[index++] = node;
        storeNodes(node->right, nodeList, index);
    }

    // Helper function to sort an array of tree nodes based on their values
    void sortNodes(TreeNode** nodeList, int nodeCount) {
        // Using bubble sort for simplicity (can use other sorting algorithms)
        for (int i = 0; i < nodeCount - 1; ++i) {
            for (int j = 0; j < nodeCount - i - 1; ++j) {
                if (nodeList[j]->val > nodeList[j + 1]->val) {
                    swap(nodeList[j], nodeList[j + 1]);
                }
            }
        }
    }

    // Helper function to build a BST from a sorted array of nodes
    TreeNode* buildBST(TreeNode** nodeList, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* newNode = nodeList[mid];

        // Recursively build left and right subtrees
        newNode->left = buildBST(nodeList, left, mid - 1);
        newNode->right = buildBST(nodeList, mid + 1, right);

        return newNode;
    }

    // Helper function for inorder traversal (recursive)
    void inorderUtil(TreeNode* node) {
        if (node == nullptr) return;
        inorderUtil(node->left);
        cout << node->val << " ";
        inorderUtil(node->right);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    // Method to insert a value into the BST
    void insert(int val) {
        root = insertRecursive(root, val);
    }


    // Method to convert the binary tree to a binary search tree (BST)
    void convertToBST() {
        int nodeCount = countNodes(root);
        TreeNode** nodeList = new TreeNode*[nodeCount];
        int index = 0;
        storeNodes(root, nodeList, index);

        // Sort the nodes based on their values
        sortNodes(nodeList, nodeCount);

        // Rebuild the tree using the sorted nodes
        root = buildBST(nodeList, 0, nodeCount - 1);

        // Clean up dynamically allocated memory
        delete[] nodeList;
    }

    // Function to perform inorder traversal of the BST
    void inorderTraversal() {
        inorderUtil(root);
    }
    
};

int main() {
    // Example usage of the modified BinaryTree class
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    // Convert the binary tree to a binary search tree (BST)
    tree.convertToBST();

    // Output the inorder traversal of the converted BST
    cout << "Inorder traversal of the converted BST: ";
    tree.inorderTraversal();
    cout << endl;

    return 0;
}
