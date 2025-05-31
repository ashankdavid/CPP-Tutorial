#include <iostream>
#include <functional>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* head = nullptr;
        TreeNode* prev = nullptr;

        // Helper function to perform in-order traversal
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            inorder(node->left);

            if (!head) {
                // Initialize the head of the doubly linked list
                head = node;
                prev = node;
            } else {
                // Link the current node with the previous node
                prev->right = node;
                node->left = prev;
                prev = node;
            }

            inorder(node->right);
        };

        // Start in-order traversal from the root
        inorder(root);

        // Connect the tail to the head to form a circular DLL
        head->left = prev;
        prev->right = head;

        return head;
    }
};

int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Convert the binary search tree to a sorted doubly linked list
    TreeNode* sortedDLL = solution.treeToDoublyList(root);

    // Print the sorted doubly linked list (circular)
    TreeNode* current = sortedDLL;
    do {
        cout << current->val << " ";
        current = current->right;
    } while (current != sortedDLL);

    cout << endl;

    // Clean up memory (optional)
    // Assuming you have a function to delete the tree nodes
    // deleteTree(root);

    return 0;
}
