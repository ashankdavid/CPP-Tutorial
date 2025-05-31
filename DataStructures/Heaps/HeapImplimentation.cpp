#include <iostream>
#include <limits>
using namespace std;

class MaxHeap {
    int* arr;       // Pointer to the array representing the heap
    int maxSize;    // Maximum size of the heap
    int heapSize;   // Current number of elements in the heap

    // Helper functions to navigate through the heap
    int parent(int i) { return (i - 1) / 2; }
    int lChild(int i) { return 2 * i + 1; }
    int rChild(int i) { return 2 * i + 2; }

    // Function to heapify a subtree rooted at index i
    void heapify(int i) {
        int l = lChild(i);
        int r = rChild(i);
        int largest = i;
        // Find the largest among root, left child, and right child
        if (l < heapSize && arr[l] > arr[i])
            largest = l;
        if (r < heapSize && arr[r] > arr[largest])
            largest = r;
        // If the largest is not the root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

public:
    // Constructor: Initialize the heap with specified maximum size
    MaxHeap(int maxSize) {
        this->maxSize = maxSize;
        heapSize = 0;
        arr = new int[maxSize];
    }

    // Destructor: Free the dynamically allocated memory
    ~MaxHeap() {
        delete[] arr;
    }

    // Insert a new key into the heap
    void insert(int key) {
        if (heapSize == maxSize) {
            cout << "Overflow: Could not insert key\n";
            return;
        }
        // Insert the key at the end of the heap
        heapSize++; // Increment the heapSize to insert the new element
        int i = heapSize - 1; // Index of the newly inserted element in the array
        arr[i] = key; // Place the new key at the end of the heap array

        // Maintain heap property by moving the key up (Heapify-Up)
        while (i > 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Extract the maximum element (root) from the heap
    int extractMax() {
        if (heapSize <= 0)
            return numeric_limits<int>::min(); // Return minimum value if heap is empty or use INT_MIN in this case!
        int root = arr[0];
        arr[0] = arr[heapSize - 1]; // Replace root with the last element
        heapSize--;
        heapify(0); // Restore heap property starting from root
        return root;
    }

    //Now this increase funciton we can write and explain later also using priotiy queue example!
    // Increase the value of a key at index i to a new value
    void increaseKey(int i, int newVal) {
        arr[i] = newVal;
        // Move the key up to restore heap property
        while (i > 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    // Suppose you have a max heap representing a priority queue of tasks with priorities (key values). If you need to increase the priority (value) of a specific task (represented by a key), you can use increaseKey to update its priority to a higher value. This ensures that the most urgent tasks (largest priority values) are processed first when extracting elements from the heap.
    // In summary, increaseKey is used to adjust key values in a max heap, allowing you to efficiently update and maintain the heap structure while preserving the max heap property for applications that require dynamic modifications to the heap's elements.


    // Delete a key at index i from the heap
    void deleteKey(int i) {
        increaseKey(i, INT_MAX); // Increase key to maximum value
        extractMax(); // Extract the maximum element (which is at index i)
    }

    // Get the maximum element (root) of the heap
    int getMax() {
        if (heapSize > 0)
            return arr[0];
        return INT_MIN; // Return minimum value if heap is empty
    }

    // Get the current size of the heap
    int size() {
        return heapSize;
    }
};

int main() {
    MaxHeap h(15);

    // Inserting keys into the heap
    int keys[] = {3, 10, 12, 8, 2, 14};
    for (int key : keys) {
        h.insert(key);
    }

    // Displaying current heap size and maximum element
    cout << "Current heap size: " << h.size() << endl;
    cout << "Maximum element: " << h.getMax() << endl;

    // Deleting key at index 2
    h.deleteKey(2);
    cout << "Heap size after deletion: " << h.size() << endl;

    // Inserting new keys into the heap
    h.insert(15);
    h.insert(5);
    cout << "Current heap size: " << h.size() << endl;
    cout << "Maximum element: " << h.getMax() << endl;

    return 0;
}
