#include <iostream>
#include <queue>
using namespace std;

// Define a node structure for the Splay Tree
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

// Splay Tree class
class SplayTree {
private:
    Node* root;

    // Right rotate utility function
    Node* rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    // Left rotate utility function
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // Splay function to bring the key to the root
    Node* splay(Node* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

        // Key lies in left subtree
        if (key < root->key) {
            if (root->left == nullptr) return root;

            // Zig-Zig (Left Left)
            if (key < root->left->key) {
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            }
            // Zig-Zag (Left Right)
            else if (key > root->left->key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right != nullptr) {
                    root->left = leftRotate(root->left);
                }
            }

            return (root->left == nullptr) ? root : rightRotate(root);
        }

        // Key lies in right subtree
        else {
            if (root->right == nullptr) return root;

            // Zag-Zag (Right Right)
            if (key > root->right->key) {
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            }
            // Zag-Zig (Right Left)
            else if (key < root->right->key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left != nullptr) {
                    root->right = rightRotate(root->right);
                }
            }

            return (root->right == nullptr) ? root : leftRotate(root);
        }
    }

    // Helper function to recursively insert a key into the Splay Tree
    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        root = splay(root, key);

        if (root->key == key) return root;

        Node* newNode = new Node(key);
        if (key < root->key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }
        return newNode;
    }

    // Helper function to search for a key in the Splay Tree
    Node* searchRec(Node* root, int key) {
        return splay(root, key);
    }

    // Helper function to perform inorder traversal of the Splay Tree
    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->key << " ";
            inorderRec(root->right);
        }
    }

    // Helper function to perform BFS traversal using a queue
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
    SplayTree() {
        root = nullptr;
    }

    // Public method to insert a key into the Splay Tree
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Public method to search for a key in the Splay Tree
    void search(int key) {
        root = searchRec(root, key);
    }

    // Public method to perform inorder traversal of the Splay Tree
    void inorderTraversal() {
        inorderRec(root);
        cout << endl;
    }

    // Public method to perform BFS traversal of the Splay Tree
    void bfsTraversal() {
        bfsHelper(root);
        cout << endl;
    }
};

// Main function to test the Splay Tree implementation
int main() {
    SplayTree st;

    // Insert some keys into the Splay Tree
    st.insert(50);
    st.insert(30);
    st.insert(70);
    st.insert(20);
    st.insert(40);
    st.insert(60);
    st.insert(80);

    // Perform inorder traversal of the Splay Tree
    cout << "Inorder traversal of Splay Tree: ";
    st.inorderTraversal();

    // Perform BFS traversal of the Splay Tree
    cout << "BFS traversal of Splay Tree: ";
    st.bfsTraversal();

    // Search for a key in the Splay Tree
    cout << "Searching for 60 in the Splay Tree..." << endl;
    st.search(60);
    cout << "BFS Traversal after splaying 60 to the root: ";
    st.bfsTraversal();

    return 0;
}
