#include<stdio.h>
using namespace std;
void function1()
{  
    int x=10;//local variable  
    static int y=10;//static variable  
    x=x+1;  
    y=y+1;  
    printf("%d,%d\n",x,y);  
}
int main()
{
  function1();
  function1();
  function1();
  function1();
}