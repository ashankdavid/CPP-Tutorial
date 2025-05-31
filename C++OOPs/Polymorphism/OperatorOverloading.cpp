#include <iostream>
using namespace std;
class A
{
public:
    int num;
    void operator ++(int num)  // overloading of ++ Operator
    {
        num = num + 2;
        cout << num;
    }
};
int main()
{
    A obj;
    obj.operator++(10);
}

//This program need to be updated...! but implementation of Operator Overloading is fine!