#include<iostream>
#include<queue> // Include queue for BFS
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createNode(int data) {
    Node* newNode = new Node(data);
    return newNode;
}

void preOrderDFS(Node* root) {
    if(root == NULL) { return; }
    cout << root->data << " ";
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}

void inOrderDFS(Node* root) {
    if(root == NULL) { return; }
    inOrderDFS(root->left);
    cout << root->data << " ";
    inOrderDFS(root->right);
}

void postOrderDFS(Node* root) {
    if(root == NULL) { return; }
    postOrderDFS(root->left);
    postOrderDFS(root->right);
    cout << root->data << " ";
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

int main() {
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

    cout << "Preorder traversal:" << endl;
    preOrderDFS(root);
    cout << endl;
    
    cout << "Inorder traversal:" << endl;
    inOrderDFS(root);
    cout << endl;
    
    cout << "Postorder traversal:" << endl;
    postOrderDFS(root);
    cout << endl;
    
    cout << "Breadth-First Search (BFS) traversal:" << endl;
    BFS(root);
    cout << endl;
    
    return 0;
}
