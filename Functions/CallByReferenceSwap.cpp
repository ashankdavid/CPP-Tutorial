#include <iostream>
using namespace std;
int swap(int *, int *);
int main()
{
    int a = 10;
    int b = 20;
    cout << "Before Swapping in Main Function a = " << a << ", b = " << b << endl;
    swap(&a, &b); // Call by Reference
    cout << "After Swapping in Main Funtion a = "  << a << ", b = " << b << endl;
    // After Swapping in Main Function "a" and "b" values will be changed in their Original Memory Location
}
int swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cout << "After Swapping in Swap Function a = " << *a << ", b = " << *b << endl;
    // No point of writing this cout here because Originally values are changed outside this Function as well!
}