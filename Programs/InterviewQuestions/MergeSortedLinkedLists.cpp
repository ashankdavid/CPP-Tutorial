#include <iostream>

using namespace std;

// Node class representing each node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with given data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Destructor to free memory occupied by the linked list
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Function to insert a new node at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to merge two sorted linked lists into a single sorted linked list
    static LinkedList mergeSortedLists(const LinkedList& list1, const LinkedList& list2) {
        LinkedList mergedList;
        Node* curr1 = list1.head;
        Node* curr2 = list2.head;

        // Traverse both lists and merge them
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->data <= curr2->data) {
                mergedList.insert(curr1->data);
                curr1 = curr1->next;
            } else {
                mergedList.insert(curr2->data);
                curr2 = curr2->next;
            }
        }

        // Append remaining nodes of list1
        while (curr1 != nullptr) {
            mergedList.insert(curr1->data);
            curr1 = curr1->next;
        }

        // Append remaining nodes of list2
        while (curr2 != nullptr) {
            mergedList.insert(curr2->data);
            curr2 = curr2->next;
        }

        return mergedList;
    }

    // Function to print all elements in the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to demonstrate the usage of merging two sorted linked lists
int main() {
    // Create and populate the first sorted linked list: 1 -> 3 -> 5
    LinkedList list1;
    list1.insert(1);
    list1.insert(3);
    list1.insert(5);

    // Create and populate the second sorted linked list: 2 -> 4 -> 6
    LinkedList list2;
    list2.insert(2);
    list2.insert(4);
    list2.insert(6);

    // Merge the two sorted linked lists
    LinkedList mergedList = LinkedList::mergeSortedLists(list1, list2);

    // Display the merged sorted linked list
    cout << "Merged Sorted Linked List: ";
    mergedList.display();

    return 0;
}
