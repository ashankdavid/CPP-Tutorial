#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class SLL {
public:
    Node* head;

    SLL() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverseInGroups(Node* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int count = 0;
        
        // Reverse in groups of size k
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // Count the total number of nodes in the linked list
        Node* temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        
        // If there are remaining nodes, call reverse recursively
        if (next != NULL && length - count >= k) {
            head->next = reverseInGroups(next, k);
        } else {
            head->next = next;  // Attach remaining nodes as they are
        }

        return prev;
    }

    void reverseGroups(int k) {
        head = reverseInGroups(head, k);
    }
};

int main() {
    SLL obj;
    obj.insertAtHead(10);
    obj.insertAtHead(9);
    obj.insertAtHead(8);
    obj.insertAtHead(7);
    obj.insertAtHead(6);
    obj.insertAtHead(5);
    obj.insertAtHead(4);
    obj.insertAtHead(3);
    obj.insertAtHead(2);
    obj.insertAtHead(1);

    cout << "Original List: ";
    obj.display();

    int k = 3;
    obj.reverseGroups(k);

    cout << "Reversed List in Groups of " << k << ": ";
    obj.display();

    return 0;
}
