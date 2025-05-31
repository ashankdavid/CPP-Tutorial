#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class SLL{
    public:
    Node* head;
    SLL(){
        this->head = NULL;
    }

    void insertAtHead(int val){
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtTail(int val){
        Node* n = new Node(val);
        if(head==NULL){
            head = n;
        }else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    int getSize(){
        int size = 0;
        Node* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        return size;
    }

    void insertAtPos(int val, int pos){
        int size = getSize();
        if(pos<0 || pos>size){
            cout << "INVALID POSITION" << endl;
        }else if(pos==0){
            insertAtHead(val);
        }else{
            Node* n = new Node(val);
            Node* temp = head;
            while(--pos){
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }

    void deleteAtHead(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteByVal(int val){
        if(head->data==val){
            deleteAtHead();
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL && temp->next->data!=val){
            temp=temp->next;
        }
        if(temp->next==NULL){
            cout << "Value "<< val << " Not Found!" << endl;
            return;
        }
        Node* todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }

    void displayLL(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

int main(){
    SLL obj;
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