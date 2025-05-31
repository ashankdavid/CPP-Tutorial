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

    // Helper function to store tree nodes in an array (inorder traversal)
    void storeNodes(TreeNode* node, TreeNode** nodeList, int& index) {
        if (node == nullptr) return;

        // Recursive traversal (inorder)
        storeNodes(node->left, nodeList, index);
        nodeList[index++] = node;
        storeNodes(node->right, nodeList, index);
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

public:
    BinaryTree() {
        root = nullptr;
    }

    // Method to insert a value into the BST
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // Method to get the root node of the BST
    TreeNode* getRoot(){
        return root;
    }

    // Method to perform inorder traversal and return an array of node pointers
    TreeNode** inorderTraversal(TreeNode* node, int& nodeCount) {
        nodeCount = countNodes(node);
        TreeNode** nodeList = new TreeNode*[nodeCount];
        int index = 0;
        storeNodes(node, nodeList, index);
        return nodeList;
    }

    // Helper function to count nodes in the tree
    int countNodes(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Method to merge another BST into this BST
    void merge(BinaryTree& other) {
        int thisNodeCount, otherNodeCount;
        TreeNode** thisNodes = inorderTraversal(root, thisNodeCount);
        TreeNode** otherNodes = other.inorderTraversal(other.root, otherNodeCount);

        // Merge both sorted arrays of nodes into a single sorted array
        TreeNode** mergedNodes = new TreeNode*[thisNodeCount + otherNodeCount];
        int i = 0, j = 0, k = 0;
        
        while (i < thisNodeCount && j < otherNodeCount) {
            if (thisNodes[i]->val < otherNodes[j]->val) {
                mergedNodes[k++] = thisNodes[i++];
            } else {
                mergedNodes[k++] = otherNodes[j++];
            }
        }

        // Add remaining nodes from both arrays
        while (i < thisNodeCount) {
            mergedNodes[k++] = thisNodes[i++];
        }
        while (j < otherNodeCount) {
            mergedNodes[k++] = otherNodes[j++];
        }

        // Rebuild the current BST using the merged sorted array of nodes
        root = buildBST(mergedNodes, 0, thisNodeCount + otherNodeCount - 1);

        // Clean up dynamically allocated memory
        delete[] thisNodes;
        delete[] otherNodes;
        delete[] mergedNodes;
    }

    // Method to perform inorder traversal of the BST (for testing)
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->val << " ";
        inorderTraversal(node->right);
    }
};

int main() {
    // Example usage of the modified BinaryTree class
    BinaryTree bst1;
    bst1.insert(5);
    bst1.insert(3);
    bst1.insert(7);

    BinaryTree bst2;
    bst2.insert(10);
    bst2.insert(8);
    bst2.insert(12);

    // Merge bst2 into bst1
    bst1.merge(bst2);

    // Output the inorder traversal of the merged BST
    cout << "Inorder traversal of the merged BST: ";
    bst1.inorderTraversal(bst1.getRoot());
    cout << endl;

    return 0;
}
