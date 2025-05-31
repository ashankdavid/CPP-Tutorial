#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL {
public:
    Node* head;

    DLL() {
        this->head = NULL;
    }

    void insertAtHead(int val) {
        Node* n = new Node(val);
        if (head != NULL) {
            head->prev = n;
        }
        n->next = head;
        head = n;
    }

    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }

    int getSize() {
        int size = 0;
        Node* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void insertAtPos(int val, int pos) {
        int size = getSize();
        if (pos < 0 || pos > size) {
            cout << "Get Lost" << endl;
        } else if (pos == 0) {
            insertAtHead(val);
        } else {
            Node* n = new Node(val);
            Node* temp = head;
            while (--pos) {
                temp = temp->next;
            }
            n->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = n;
            temp->next = n;
            n->prev = temp;
        }
    }

    void deleteAtHead() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }

    void deleteByVal(int val) {
        if (head == NULL) return;

        if (head->data == val) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value " << val << " Not Found!" << endl;
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void displayLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DLL obj;
    obj.insertAtHead(10);
    obj.insertAtHead(20);
    obj.insertAtHead(30);
    obj.insertAtHead(100);
    obj.displayLL();
    obj.insertAtTail(1000);
    obj.displayLL();
    obj.insertAtPos(300, 1000);
    obj.displayLL();
    obj.deleteAtHead();
    obj.displayLL();
    obj.deleteByVal(300);
    obj.displayLL();
}
