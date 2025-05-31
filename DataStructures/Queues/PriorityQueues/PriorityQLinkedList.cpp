#include <iostream>
using namespace std;

// Node class for Priority Queue
class Node {
private:
    int data;
    int priority;
    Node* next;

public:
    // Constructor
    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }

    // Getter for data
    int getData(){
        return data;
    }

    // Getter for priority
    int getPriority(){
        return priority;
    }

    // Getter for next
    Node* getNext(){
        return next;
    }

    // Setter for next
    void setNext(Node* node) {
        next = node;
    }
};

// Function to create a new node
Node* newNode(int d, int p) {
    return new Node(d, p);
}

// Return the value at head
int peek(Node** head) {
    return (*head)->getData();
}

// Removes the element with the highest priority from the list
void pop(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->getNext();
    delete temp;
}

// Function to push according to priority
void push(Node** head, int d, int p) {
    Node* start = (*head);
    Node* temp = newNode(d, p);

    if ((*head)->getPriority() < p) {
        temp->setNext(*head);
        (*head) = temp;
    } else {
        while (start->getNext() != nullptr && start->getNext()->getPriority() > p) {
            start = start->getNext();
        }
        temp->setNext(start->getNext());
        start->setNext(temp);
    }
}

// Function to check if list is empty
bool isEmpty(Node** head) {
    return (*head) == nullptr;
}

// Driver code
int main() {
    // Create a Priority Queue: 7->4->5->6
    Node* pq = newNode(4, 1);
    push(&pq, 5, 2);
    push(&pq, 6, 3);
    push(&pq, 7, 0);

    while (!isEmpty(&pq)) {
        cout << " " << peek(&pq);
        pop(&pq);
    }

    return 0;
}
