#include <iostream>
using namespace std;
int main ()
{
    short x = 200;
    int y = x;
    cout << " Implicit Type Casting " << endl;
    cout << " The value of x: " << x << endl; // 200
    cout << " The value of y: " << y << endl; // 200

    int num = 20;
    char ch = 'a';
    int res = 20 + 'a'; // here "a" is equivalent of 97
    cout << " Type casting char to int data type ('a' to 20): " << res << endl; //117

    float val = num + 'A'; // here "A" is equivalent to 65
    cout << " Type casting from int data to float type: " << val << endl; //85
    return 0;
}