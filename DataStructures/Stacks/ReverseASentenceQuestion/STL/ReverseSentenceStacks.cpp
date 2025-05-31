#include <iostream>
#include<stack>
using namespace std;

void reverseSentence(string s)
{
    stack<string> st; //creating stack using STL(Standard Template Library C++)

    for(int i=0;i<s.length();i++)
    {
        string word = "";
        while(s[i]!=' ' && i<s.length()) //checking for spaces and adding words to the variable and last checking if the sentence is finished or not
        {
            word+=s[i]; // This will add the word to the variable!
            i++;
        }
        st.push(word); //After word is added to the var, it is then pushed to the stack!
    }

    while(!st.empty()) // For printing the stack to the output
    {
        cout << st.top() << " "; //Print the top element
        st.pop(); //Pop the already printed element
    }
    cout << endl;
}

int main()
{
    string s = "Hey, how are you doing?";
    reverseSentence(s);

}
