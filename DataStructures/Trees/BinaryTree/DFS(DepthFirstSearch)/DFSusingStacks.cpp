#include <iostream>
#include <stack>
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

Node* createNode(int val) {
    Node* n = new Node(val);
    return n;
}

void predfsUsingStack(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    s.push(root);

    cout << "DFS (Preorder) using stack: ";

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Push right child first so that left is processed first
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
    cout << endl;
}

void indfsUsingStack(Node* root) {
    stack<Node*> s;
    Node* current = root;

    cout << "Inorder traversal using stack: ";

    while (current != NULL || !s.empty()) {
        // Reach the leftmost node of current
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        // current is NULL now, backtrack
        current = s.top();
        s.pop();

        cout << current->data << " ";

        // Visit the right subtree
        current = current->right;
    }

    cout << endl;
}

void postdfsUsingStacks(Node* root) {
    if (root == NULL) return;

    stack<Node*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        Node* current = stack1.top();
        stack1.pop();
        stack2.push(current);

        // Push left first, so right is processed first
        if (current->left) stack1.push(current->left);
        if (current->right) stack1.push(current->right);
    }

    cout << "Postorder traversal using stacks: ";
    while (!stack2.empty()) {
        cout << stack2.top()->data << " ";
        stack2.pop();
    }
    cout << endl;
}

int main() {
    Node* root = createNode(1); // level 1

    root->left = createNode(2); // level 2
    root->right = createNode(3);

    root->left->left = createNode(4); // level 3
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(8); // level 4
    root->right->left->left = createNode(15);
    root->right->left->right = createNode(9);

    predfsUsingStack(root);
    indfsUsingStack(root);
    return 0;
}
