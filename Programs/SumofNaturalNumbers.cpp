#include <iostream>
using namespace std;
int i, num, sum = 0;
int main()
{
    cout << "Enter a Positive Number: ";
    cin >> num;
    for(i=1;i<=num;i++)
    {
        sum = sum + i;
    }
    cout << "Sum is: " << sum;
}