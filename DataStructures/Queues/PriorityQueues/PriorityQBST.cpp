#include <iostream>
#include <stdexcept>

using namespace std;

// Node class representing a node in the BST
class Node {
public:
    int key;
    int priority;
    Node* left;
    Node* right;

    Node(int k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
};

// Priority Queue implemented using BST
class PriorityQueueBST {
private:
    Node* root;

    // Helper function to insert a node with given key and priority
    Node* _insert(Node* root, int key, int priority) {
        if (!root) {
            return new Node(key, priority);
        }
        if (priority < root->priority) {
            root->left = _insert(root->left, key, priority);
        } else {
            root->right = _insert(root->right, key, priority);
        }
        return root;
    }

    // Helper function to find and remove the node with minimum priority
    Node* _removeMin(Node* root) {
        if (!root) {
            return nullptr;
        }
        if (!root->left) {
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        }
        root->left = _removeMin(root->left);
        return root;
    }

    // Helper function to find the node with minimum priority
    Node* _findMinNode(Node* root) {
        if (!root) {
            return nullptr;
        }
        while (root->left) {
            root = root->left;
        }
        return root;
    }

public:
    // Constructor
    PriorityQueueBST() : root(nullptr) {}

    // Destructor to free memory
    ~PriorityQueueBST() {
        // Implement a function to recursively delete all nodes
        clear(root);
    }

    // Function to insert an element into the priority queue with given priority
    void insert(int key, int priority) {
        root = _insert(root, key, priority);
    }

    // Function to remove and return the element with the minimum priority
    int removeMin() {
        if (!root) {
            throw runtime_error("Priority queue is empty");
        }
        Node* minNode = _findMinNode(root);
        int minValue = minNode->key;
        root = _removeMin(root);
        return minValue;
    }

    // Function to clear the priority queue and free memory
    void clear(Node* root) {
        if (root) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }
};

// Example usage
int main() {
    PriorityQueueBST pq;

    // Insert elements with priorities
    pq.insert(10, 3);
    pq.insert(20, 1);
    pq.insert(30, 2);

    // Remove elements in order of priority
    cout << "Removing element with minimum priority: " << pq.removeMin() << endl;  // Output: 20
    cout << "Removing element with minimum priority: " << pq.removeMin() << endl;  // Output: 30
    cout << "Removing element with minimum priority: " << pq.removeMin() << endl;  // Output: 10

    return 0;
}
