#include <iostream>
using namespace std;
void greet(); //Function Prototyping..
int main()
{
    greet();
    greet();
}

void greet()
{
    cout << "Good Morning" << endl;
    cout << "Have a Nice Day!" << endl;
}