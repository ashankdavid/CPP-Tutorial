#include <iostream>
using namespace std;
int swap(int,int);
int main()
{
    int a = 10;
    int b = 20;
    cout << "Before Swapping in Main Function a = " << a << ", b = " << b << endl;
    swap(a,b); // call by value
    cout << "After Swapping in Main Function a = " << a << ", b = " << b << endl;
    // After swapping in Main Function "a" and "b" values remains the same
}
int swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "After Swapping in Swap Function a = " << a << ", b = " << b << endl;
    // After swapping in Swap Function "a" and "b" values are Swapped!
    return 0;
}
