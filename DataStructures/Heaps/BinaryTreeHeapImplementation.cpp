#include <iostream>

using namespace std;

// Node class representing a node in the binary tree
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

// MinHeap class representing a Min-Heap implemented using a binary tree
class MinHeap {
private:
    Node* root;
    int size;

    // Helper function to find the last node in the heap
    Node* getLastNode() {
        if (root == nullptr) {
            return nullptr;
        }

        Node* temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }

    // Helper function to restore heap property by moving a node up This happens for insertion
    void heapifyUp(Node* node) {
        Node* current = node;
        while (current != root) {
            Node* parent = nullptr;
            Node* temp = root;

            // Find parent of current node
            while (temp != nullptr && temp->left != current && temp->right != current) {
                temp = temp->left;
                if (temp == nullptr || temp->right == current) {
                    temp = temp->right;
                }
            }

            parent = temp;
            if (parent != nullptr && current->key < parent->key) {
                swap(current->key, parent->key);
                current = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to restore heap property by moving a node down used for deletion
    void heapifyDown(Node* node) {
        Node* current = node;
        while (current != nullptr) {
            Node* smallest = current;
            if (current->left != nullptr && current->left->key < smallest->key) {
                smallest = current->left;
            }
            if (current->right != nullptr && current->right->key < smallest->key) {
                smallest = current->right;
            }

            if (smallest != current) {
                swap(current->key, smallest->key);
                current = smallest;
            } else {
                break;
            }
        }
    }

public:
    MinHeap() {
        root = nullptr;
        size = 0;
    }

    // Public function to insert a new element into the Min-Heap
    void insert(int value) {
        Node* new_node = new Node(value);
        if (root == nullptr) {
            root = new_node;
        } else {
            Node* temp = getLastNode();
            if (temp->left == nullptr) {
                temp->left = new_node;
            } else {
                temp->right = new_node;
            }
        }
        size++;
        heapifyUp(new_node); // Restore heap property after insertion
    }

    // Public function to extract the minimum element (root) from the Min-Heap
    int extractMin() {
        if (root == nullptr) {
            return INT_MAX; // Heap is empty
        }

        int min_value = root->key;

        // Find the last node in the heap
        Node* last_node = getLastNode();

        // Swap root with the last node
        swap(root->key, last_node->key);

        // Remove the last node
        if (last_node == root) {
            delete root;
            root = nullptr;
            
        // The if (last_node == root) condition checks if the last node (the node that was swapped with the root) is actually the root node itself.
        // If last_node is indeed the root node, it means that the Min-Heap had only one node (the root node), which is now being extracted. In this case, we simply delete the root node (delete root;) and set the root pointer to nullptr to indicate that the heap is now empty.     

        // If the last node is not the root (i.e., there are multiple nodes in the heap), we need to find the parent node of the last_node in order to correctly delete the last_node while maintaining the binary tree structure.   

        } else {
            Node* temp = root;
            while (temp->left != last_node && temp->right != last_node) {
                temp = temp->left;
                if (temp == nullptr || temp->right == last_node) {
                    temp = temp->right;
                }
            }

            if (temp->left == last_node) {
                delete temp->left;
                temp->left = nullptr;
            } else {
                delete temp->right;
                temp->right = nullptr;
            }
        }

        size--;
        heapifyDown(root); // Restore heap property after extraction

        return min_value;
    }

    // Public function to print the elements of the Min-Heap (pre-order traversal)
    void printHeap() {
        cout << "Min-Heap elements (pre-order traversal): ";
        printPreOrder(root);
        cout << endl;
    }

    // Helper function to perform pre-order traversal
    void printPreOrder(Node* node) {
        if (node != nullptr) {
            cout << node->key << " ";
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }
};

int main() {
    // Test the MinHeap class
    MinHeap heap;

    // Insert elements into the Min-Heap
    heap.insert(5);
    heap.printHeap(); // Output: Min-Heap elements (pre-order traversal): 5

    heap.insert(3);
    heap.printHeap(); // Output: Min-Heap elements (pre-order traversal): 5 3

    heap.insert(8);
    heap.printHeap(); // Output: Min-Heap elements (pre-order traversal): 5 3 8

    heap.insert(1);
    heap.printHeap(); // Output: Min-Heap elements (pre-order traversal): 5 3 8 1

    heap.insert(6);
    heap.printHeap(); // Output: Min-Heap elements (pre-order traversal): 5 3 8 1 6

    // Extract the minimum element from the Min-Heap
    int min_value = heap.extractMin();
    cout << "Extracted min value: " << min_value << endl; // Output: Extracted min value: 1

    // Print the Min-Heap after extraction
    heap.printHeap(); // Output: Min-Heap elements (pre-order traversal): 3 6 8 5

    return 0;
}

