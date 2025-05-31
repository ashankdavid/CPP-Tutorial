#include <iostream>
using namespace std;
#define n 100

// Custom stack for strings
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

// 👇 Custom function to split words without stringstream
void reverseSentence(string exp)
{
    StringStack st;
    string word = "";

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == ' ')
        {
            if (word.length() > 0)
            {
                st.push(word);
                word = "";
            }
        }
        else
        {
            word += ch;
        }
    }

    // Push the last word if any
    if (word.length() > 0)
    {
        st.push(word);
    }

    // Pop and print words in reverse order
    while (!st.empty())
    {
        cout << st.Top() << " ";
        st.pop();
    }

    cout << endl;
}

// 🧪 Main function to test
int main()
{
    string sentence = "Hello how are you?";
    cout << "Original Sentence: " << sentence << endl;
    cout << "Reversed Sentence: ";
    reverseSentence(sentence);

    return 0;
}
