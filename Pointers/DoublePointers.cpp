#include <iostream>
using namespace std;
int main()
{
    int i = 50;
    int * ptr;
    int **dptr;
    int ***ddptr;
    ptr = &i;
    dptr = &ptr;
    ddptr = &dptr;
    cout << **dptr << endl;
    cout << *ptr << endl;
    cout << ***ddptr <<  endl;
}