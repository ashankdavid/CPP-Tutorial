#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createNode(int data)
{
    Node* newNode = new Node();
    return newNode;
}

void BFS(Node* root) {
    if(root == NULL) { return; }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        
        if(current->left != NULL) {
            q.push(current->left);
        }
        
        if(current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main()
{
    // Level 1
    Node* root = createNode(1);
    
    // Level 2
    root->left = createNode(2);
    root->right = createNode(3);

    // Level 3
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Level 4
    root->left->right->left = createNode(8);
    root->right->left->left = createNode(15);
    root->right->left->right = createNode(9);

    BFS(root);
}
