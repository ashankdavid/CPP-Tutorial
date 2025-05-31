#include<iostream>
using namespace std;
int add1(int, int);
int add2(int*, int*);
int main()
{
    int a = 10;
    int b = 20;
    cout<<"sum1 "<<add1(a,b) <<" a ="<<a<<" b="<<b<<endl;
    cout<<"sum2 "<<add2(&a,&b) <<" a ="<<a<<" b="<<b<<endl;
}
int add1(int a, int b)
{
    int sum=0;
    a=a+1;
    b=b+1;
    sum=a+b;
    return sum;
}
int add2(int *a, int *b)
{
    int sum=0;
    *a=*a+1;
    *b=*b+1;
    sum=*a + *b;
    return sum;
}
