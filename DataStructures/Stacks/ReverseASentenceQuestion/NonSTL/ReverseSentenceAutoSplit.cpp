#include <iostream>
#include <sstream>
using namespace std;
#define n 100

// String stack
class StringStack
{
    string * arr;
    int top;

    public:
    StringStack()
    {
        arr = new string[n];
        top = -1;
    }

    void push(string x)
    {
        if (top == n-1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No Element to Pop" << endl;
            return;
        }
        top--;
    }

    string Top()
    {
        if (top == -1)
        {
            return "";
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

// Function to reverse a sentence using StringStack
void reverseSentence(string exp)
{
    StringStack st;
    string word;
    stringstream ss(exp);

    // Step 1: Push words onto stack
    while (ss >> word)
    {
        st.push(word);
    }

    // Step 2: Pop words from stack to print in reverse
    while (!st.empty())
    {
        cout << st.Top() << " ";
        st.pop();
    }

    cout << endl;
}

// main function to test
int main()
{
    string sentence = "Hello how are You?";
    cout << "Original Sentence: " << sentence << endl;
    cout << "Reversed Sentence: ";
    reverseSentence(sentence);

    return 0;
}
