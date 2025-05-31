#include <iostream>
using namespace std;
int addition(int,int); // Function Prototyping..
int main()
{
    cout << addition(6,4) << endl;
    cout << addition(10,20) << endl;
}
int addition(int a, int b)
{
    int total = a + b;
    return total;
}