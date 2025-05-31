#include <iostream>
#include <cstdlib>
#define n 100
using namespace std;

int main()
{
    int *ptr;
    ptr=new int;
    *ptr=68;
    cout << "The value of p is : " <<*ptr<< endl;
    delete ptr;
    cout <<"The value after delete is : "  <<*ptr<< endl;
    return 0;
}
