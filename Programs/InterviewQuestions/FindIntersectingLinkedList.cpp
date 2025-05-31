#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
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

    Node* getTail() {
        Node* current = head;
        while (current && current->next) {
            current = current->next;
        }
        return current;
    }

    void intersect(LinkedList& other, int pos) {
        Node* tail = getTail();
        Node* intersectNode = other.head;
        while (pos > 0 && intersectNode) {
            intersectNode = intersectNode->next;
            pos--;
        }
        if (tail) {
            tail->next = intersectNode;
        }
    }
};

Node* findIntersection(Node* list1, Node* list2) {
    Node* ptr1 = list1;
    Node* ptr2 = list2;

    while(ptr1 != ptr2)
    {
        ptr1 = ptr1 ? ptr1->next : list2;
        ptr2 = ptr2 ? ptr2->next : list1;
    }

    return ptr1;
}

int main() {
    LinkedList list1;
    list1.append(1);
    list1.append(3);
    list1.append(5);

    LinkedList list2;
    list2.append(2);
    list2.append(4);

    LinkedList intersectionPoint;
    intersectionPoint.append(6);
    intersectionPoint.append(7);

    list1.intersect(intersectionPoint, 0);
    list2.intersect(intersectionPoint, 0);

    Node* intersection = findIntersection(list1.head, list2.head);
    if (intersection) {
        cout << "Intersection point data: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}