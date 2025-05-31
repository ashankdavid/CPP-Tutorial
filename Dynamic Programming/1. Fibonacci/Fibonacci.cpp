#include <iostream>
using namespace std;
int fib(int);  // function prototyping
int main() {
    int x , i;
    cout << "Enter the number of terms of series : ";
    cin >> x;
    cout << "\nFibonnaci Series : ";
    for(i=0;i<x;i++)
    {
        cout << " " << fib(i);
    }
    return 0;
}

int fib(int x) {
    if((x==1)||(x==0)) {
        return(x);
    }else {
        return(fib(x-1)+fib(x-2));
    }
}