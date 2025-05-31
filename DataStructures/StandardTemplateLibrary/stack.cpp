#include <iostream>
#include <stack>  // Include the stack library

using namespace std;

int main() {
    // Create a stack of integers
    stack<int> myStack;

    // Check if the stack is empty
    if (myStack.empty()) {
        cout << "Stack is empty.\n";
    }

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Display the top element
    cout << "Top element is: " << myStack.top() << endl;

    // Pop the top element
    myStack.pop();

    // Display the top element after pop
    cout << "After popping, the top element is: " << myStack.top() << endl;

    // Push another element onto the stack
    myStack.push(40);

    // Display the top element after push
    cout << "After pushing 40, the top element is: " << myStack.top() << endl;

    // Pop all elements to empty the stack
    while (!myStack.empty()) {
        cout << "Popping element: " << myStack.top() << endl;
        myStack.pop();
    }

    // Final check if the stack is empty
    if (myStack.empty()) {
        cout << "Stack is now empty.\n";
    }

    return 0;
}
