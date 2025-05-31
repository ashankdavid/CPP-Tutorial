#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue
void reverseQueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    // Remove the front element
    int data = q.front();
    q.pop();

    // Recursive call to reverse remaining queue
    reverseQueue(q);

    // Add the front element back to the end
    q.push(data);
}

// Function to print the queue
void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    printQueue(q);

    // Reverse the queue
    reverseQueue(q);

    cout << "Reversed Queue: ";
    printQueue(q);

    return 0;
}