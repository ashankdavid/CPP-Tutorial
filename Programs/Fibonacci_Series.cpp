#include <iostream>
using namespace std;
int i, n, n1 = 0, n2 = 1, sum = 0;
int main()
{
    cout << "Enter a Number: ";
    cin >> n;
    cout << n1 << " " << n2;
    for(i=2;i<n;i++)
    {
        sum = n1+n2;
        cout << " " <<sum;
        n1 = n2;
        n2 = sum;
    }
}