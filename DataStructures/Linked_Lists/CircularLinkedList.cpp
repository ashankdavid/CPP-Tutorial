#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert an element at the beginning of the circular linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert an element at the end of the circular linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    // Delete a specific element from the circular linked list
    void deleteElement(int value) {
        if (!head)
            return;

        if (head->data == value) {
            Node* temp = head;
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = head->next;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current->next != head && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current->next == head)
            return;

        prev->next = current->next;
        delete current;
    }

    // Search for a specific element in the circular linked list and return its position
    int search(int value) {
        if (!head)
            return -1;

        int position = 0;
        Node* current = head;

        do {
            position++;
            if (current->data == value)
                return position;
            current = current->next;
        } while (current != head);

        return -1;
    }

    // Display the elements of the circular linked list
    void display() {
        if (!head)
            return;

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    // Destructor to free dynamically allocated memory
    ~CircularLinkedList() {
        if (!head)
            return;

        Node* current = head;
        while (current->next != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete current;
    }
};

int main() {
    CircularLinkedList list;
    int choice, value, searchValue, position;

    do {
        std::cout << "\nCircular Linked List Operations:\n";
        std::cout << "1. Insert at the beginning\n";
        std::cout << "2. Insert at the end\n";
        std::cout << "3. Delete element\n";
        std::cout << "4. Search element\n";
        std::cout << "5. Display list\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                std::cout << "Enter element to delete: ";
                std::cin >> value;
                list.deleteElement(value);
                break;
            case 4:
                std::cout << "Enter element to search: ";
                std::cin >> searchValue;
                position = list.search(searchValue);
                if (position != -1) {
                    std::cout << searchValue << " found at position " << position << "\n";
                } else {
                    std::cout << searchValue << " not found in the list.\n";
                }
                break;
            case 5:
                std::cout << "Circular Linked List: ";
                list.display();
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
