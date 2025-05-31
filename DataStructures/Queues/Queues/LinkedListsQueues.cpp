#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Queue{
    Node* front;
    Node* rear;

    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val){
        Node* n = new Node(val);
        if(front == NULL){
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    void dequeue(){
        if(front == NULL){
            cout << "Queue Underflow!" << endl;
            return;
        }
        Node* todelete = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        delete todelete;
    }

    int peek(){
        if(front == NULL){
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void display(){
        Node* temp = front;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    Queue q;
    cout << "Enqueue Operation: " << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    cout << "Dequeue Operation: " << endl;
    q.dequeue();
    q.display();

    cout << "Peek Operation: " << endl;
    cout << "Front element is: " << q.peek() << endl;

    return 0;

}