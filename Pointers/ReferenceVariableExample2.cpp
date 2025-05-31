#include <iostream>
using namespace std;
int main()
{
    int a=70; // variable initialization
    int &b=a;
    int &c=a;
    cout << "Value of a is :" <<&a<< endl;
    cout << "Value of b is :" <<&b<< endl;
    cout << "Value of c is :" <<&c<< endl;
    return 0;}