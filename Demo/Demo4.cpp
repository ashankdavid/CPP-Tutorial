#include<iostream>
using namespace std;

void function(int** a, int** b)
{
    int sum = **a + **b;
    cout << **a << "+" << **b << "=" << sum << endl;

}

int main()
{
    int num1 = 10;
    int num2 = 20;

    int *ptr1 = &num1;
    int *ptr2 = &num2;

    function(&ptr1, &ptr2);
}