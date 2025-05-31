#include <iostream>
using namespace std;

struct Task {
    int id;
    int priority;

    // Default constructor
    Task() {
        id = 0;
        priority = 0;
    }

    // Parameterized constructor
    Task(int _id, int _priority) {
        id = _id;
        priority = _priority;
    }
};

class PriorityQueue {
private:
    Task* tasks;      // Array to store tasks
    int maxSize;      // Maximum size of the queue
    int currentSize;  // Current number of tasks in the queue

public:
    // Constructor to initialize the priority queue with a given size
    PriorityQueue(int size) {
        maxSize = size;
        currentSize = 0;
        tasks = new Task[maxSize];  // Initialize tasks array
    }

    // Destructor to free memory
    ~PriorityQueue() {
        delete[] tasks;
    }

    // Insert a new task with its priority into the queue
    void insertTask(int id, int priority) {
        if (currentSize == maxSize) {
            cout << "Priority Queue is full. Cannot insert more tasks.\n";
            return;
        }

        tasks[currentSize].id = id;
        tasks[currentSize].priority = priority;
        currentSize++;

        // Restore heap property by bubbling up the new task
        bubbleUp(currentSize - 1);
    }

    // Remove and return the highest priority task from the queue
    Task removeHighestPriorityTask() {
        if (currentSize == 0) {
            cout << "Priority Queue is empty. No task to remove.\n";
            return Task();  // Return default-constructed Task
        }

        Task highestPriorityTask = tasks[0];
        tasks[0] = tasks[--currentSize];

        // Restore heap property by heapifying from the root
        heapify(0);

        return highestPriorityTask;
    }

    // Get the task identifier of the highest priority task without removing it
    int peekHighestPriorityTask() const {
        if (currentSize == 0) {
            cout << "Priority Queue is empty.\n";
            return -1;  // Return an invalid task ID
        }

        return tasks[0].id;
    }

private:
    // Helper function to restore heap property by bubbling up
    void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (tasks[index].priority > tasks[parent].priority) {
                swap(tasks[index], tasks[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to restore heap property by heapifying down
    void heapify(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < currentSize && tasks[left].priority > tasks[largest].priority) {
            largest = left;
        }
        if (right < currentSize && tasks[right].priority > tasks[largest].priority) {
            largest = right;
        }

        if (largest != index) {
            swap(tasks[index], tasks[largest]);
            heapify(largest);
        }
    }
};

int main() {
    // Example usage of PriorityQueue
    PriorityQueue pq(5);

    // Insert tasks with their priorities
    pq.insertTask(1, 3);
    pq.insertTask(2, 1);
    pq.insertTask(3, 5);
    pq.insertTask(4, 2);
    pq.insertTask(5, 4);

    // Peek and remove tasks with highest priority
    cout << "Highest priority task (peek): " << pq.peekHighestPriorityTask() << endl;

    Task t = pq.removeHighestPriorityTask();
    cout << "Removed highest priority task: " << t.id << endl;

    t = pq.removeHighestPriorityTask();
    cout << "Removed highest priority task: " << t.id << endl;

    return 0;
}
