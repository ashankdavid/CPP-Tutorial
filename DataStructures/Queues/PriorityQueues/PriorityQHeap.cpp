#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

const int MAX_SIZE = 50;
int H[MAX_SIZE]; // Array to store the heap elements
int size = -1;    // Current size of the heap

// Function to return the index of the parent node of a given node
int parent(int i) {
    return (i - 1) / 2;
}

// Function to return the index of the left child of the given node
int leftChild(int i) {
    return (2 * i) + 1;
}

// Function to return the index of the right child of the given node
int rightChild(int i) {
    return (2 * i) + 2;
}

// Function to swap two elements in the heap
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to shift up the node to maintain the heap property after insertion
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// Function to shift down the node to maintain the heap property after extraction or changes
void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l <= size && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    if (r <= size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// Function to insert a new element into the priority queue
void insert(int p) {
    if (size >= MAX_SIZE - 1) {
        cout << "Heap is full. Cannot insert.\n";
        return;
    }
    
    size++;
    H[size] = p;
    shiftUp(size);
}

// Function to extract the element with maximum priority (root of the heap)
int extractMax() {
    if (size == -1) {
        cout << "Heap is empty. Cannot extract.\n";
        return INT_MIN; // Return minimum integer value if heap is empty
    }

    int result = H[0];
    H[0] = H[size];
    size--;
    shiftDown(0);
    return result;
}

// Function to change the priority of an element at given index
void changePriority(int i, int p) {
    if (i < 0 || i > size) {
        cout << "Invalid index.\n";
        return;
    }

    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// Function to remove the element at a specific index
void remove(int i) {
    if (i < 0 || i > size) {
        cout << "Invalid index.\n";
        return;
    }

    H[i] = INT_MAX; // Set to a large value (assumed INT_MAX is defined)
    shiftUp(i);      // Shift up to bring to the root
    extractMax();    // Extract the maximum element (removal)
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    cout << "Priority Queue: ";
    for (int i = 0; i <= size; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Maximum Priority Element: " << extractMax() << "\n";

    cout << "Priority Queue after extraction: ";
    for (int i = 0; i <= size; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    changePriority(2, 49);

    cout << "Priority Queue after priority change: ";
    for (int i = 0; i <= size; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    remove(3);

    cout << "Priority Queue after removal: ";
    for (int i = 0; i <= size; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}
