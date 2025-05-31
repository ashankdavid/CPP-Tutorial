// Implementing stack using classes and arrays! (LIFO)
#include <iostream>
using namespace std;

#define n 100

class Stack
{
    int * arr;
    int top;

    public:
    Stack()
    {
        arr = new int[n]; //dynamically allocating memory to the array
        top = -1;
    }

    void push(int x)
    {
        if (top==n-1) // if it is last index?
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = x; // putting the value
    }

    void pop()
    {
        if(top==-1) // if array is empty?
        {
            cout << "No Element to Pop" << endl;
            return;
        }

        top--;
    }

    int Top()
    {
        if(top==-1) // if array is empty?
        {
            cout << "No Element in Stack" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top==-1;
    }

    void printStack()
    {
        if(top==-1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        for(int i=0;i<=top;i++)
        {
            cout << arr[i] << " ";
        }
    }

    // bool search(int key)
    // {
    //     if(top==-1)
    //     {
    //         cout << "Stack is Empty" << endl;
    //         return;
    //     }

    //     for(int i=0;i<=top;i++)
    //     {
    //         if(arr[i]==key)
    //         {
    //             return true;
    //         }
    //     }
    // }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    // cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    // st.printStack();
    cout << endl;
    // st.search(2);
    return 0;

}