#include <iostream>
#include <unordered_set>
using namespace std;

// Node class for representing elements in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class to manage operations on the linked list
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the linked list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data;
            if (current->next) {
                cout << "->";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Function to remove duplicates from the linked list
    void removeDuplicates() {
        if (!head) {
            return;
        }

        unordered_set<int> uniqueValues;
        Node* current = head;
        Node* prev = nullptr;

        while (current) {
            if (uniqueValues.count(current->data)) {
                // Duplicate found, skip current node
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                // Add current node's data to set
                uniqueValues.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
    }


    // void removeDuplicates() {
    //     if (!head) {
    //         return;
    //     }

    //     Node* current = head;
    //     while (current) {
    //         // Pointer to traverse the list to check for duplicates
    //         Node* runner = current;
    //         while (runner->next) {
    //             if (runner->next->data == current->data) {
    //                 // Duplicate found, skip the next node
    //                 Node* duplicate = runner->next;
    //                 runner->next = runner->next->next;
    //                 delete duplicate;
    //             } else {
    //                 // Move to the next node
    //                 runner = runner->next;
    //             }
    //         }
    //         current = current->next;
    //     }
    // }
};

int main() {
    // Given input array
    int arr[] = {1, 6, 3, 7, 2, 7, 3, 8, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a linked list and insert elements from the array
    LinkedList myList;
    for (int i = 0; i < n; i++) {
        myList.insert(arr[i]);
    }

    // Display linked list before removing duplicates
    cout << "Linked List Before Removing Duplicates: ";
    myList.display();

    // Remove duplicates from the linked list
    myList.removeDuplicates();

    // Display linked list after removing duplicates
    cout << "Linked List After Removing Duplicates: ";
    myList.display();

    return 0;
}
