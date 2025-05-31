#include <iostream>
#include <queue>
using namespace std;

enum Color { RED, BLACK };

class Node {
public:
    int data;
    bool color;
    Node* left;
    Node* right;
    Node* parent;

    // Constructor with 'this' keyword
    Node(int data) {
        this->data = data;
        this->color = RED;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};


class RedBlackTree {
private:
    Node* root;

    // Utility function to rotate node left
    void leftRotate(Node*& root, Node*& node) {
        Node* nodeRight = node->right;
        node->right = nodeRight->left;

        if (node->right != nullptr)
            node->right->parent = node;

        nodeRight->parent = node->parent;

        if (node->parent == nullptr)
            root = nodeRight;
        else if (node == node->parent->left)
            node->parent->left = nodeRight;
        else
            node->parent->right = nodeRight;

        nodeRight->left = node;
        node->parent = nodeRight;
    }

    // Utility function to rotate node right
    void rightRotate(Node*& root, Node*& node) {
        Node* nodeLeft = node->left;
        node->left = nodeLeft->right;

        if (node->left != nullptr)
            node->left->parent = node;

        nodeLeft->parent = node->parent;

        if (node->parent == nullptr)
            root = nodeLeft;
        else if (node == node->parent->left)
            node->parent->left = nodeLeft;
        else
            node->parent->right = nodeLeft;

        nodeLeft->right = node;
        node->parent = nodeLeft;
    }

    // Function to fix violations after insertion
    void fixInsert(Node*& root, Node*& node) {
        Node* parent = nullptr;
        Node* grandParent = nullptr;

        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandParent = node->parent->parent;

            // Parent is left child of grandparent
            if (parent == grandParent->left) {
                Node* uncle = grandParent->right;

                // Case 1: Uncle is RED, just recoloring
                if (uncle != nullptr && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandParent;
                } else {
                    // Case 2: Node is right child, left rotate
                    if (node == parent->right) {
                        leftRotate(root, parent);
                        node = parent;
                        parent = node->parent;
                    }

                    // Case 3: Node is left child, right rotate
                    rightRotate(root, grandParent);
                    swap(parent->color, grandParent->color);
                    node = parent;
                }
            } 
            // Parent is right child of grandparent
            else {
                Node* uncle = grandParent->left;

                // Case 1: Uncle is RED, recoloring
                if (uncle != nullptr && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandParent;
                } else {
                    // Case 2: Node is left child, right rotate
                    if (node == parent->left) {
                        rightRotate(root, parent);
                        node = parent;
                        parent = node->parent;
                    }

                    // Case 3: Node is right child, left rotate
                    leftRotate(root, grandParent);
                    swap(parent->color, grandParent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK;
    }

    // Helper function for standard BST insertion
    Node* insertBST(Node* root, Node* node) {
        if (root == nullptr)
            return node;

        if (node->data < root->data) {
            root->left = insertBST(root->left, node);
            root->left->parent = root;
        } else if (node->data > root->data) {
            root->right = insertBST(root->right, node);
            root->right->parent = root;
        }

        return root;
    }

public:
    RedBlackTree() : root(nullptr) {}

    // Public insert function
    void insert(int data) {
        Node* node = new Node(data);
        root = insertBST(root, node);
        fixInsert(root, node);
    }

    // Level order traversal (BFS)
    void levelOrderTraversal() {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " (" << (current->color == RED ? "R" : "B") << ") ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    }
};

int main() {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    cout << "Level order traversal of Red-Black Tree:" << endl;
    tree.levelOrderTraversal();

    return 0;
}
