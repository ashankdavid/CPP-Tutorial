#include <iostream>
using namespace std;
int x, y;
int main()
{
    x = 10;
    y = 20;
    cout << "Before Swapping values are x = " << x << ", y = " << y << endl;
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << "After Swapping values are x = " << x << ", y = " << y << endl;
}