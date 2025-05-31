#include <iostream>
#include <cstring>
using namespace std;

void changePosition(char *ch1, char *ch2)
{
    char tmp;
    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}
void charPermu(char *cht, int stno, int endno)
{
   int i;
   if (stno == endno)
     cout << cht << " ";
   else
   {
       for (i = stno; i <= endno; i++)
       {
          changePosition((cht+stno), (cht+i));
          charPermu(cht, stno+1, endno);
          changePosition((cht+stno), (cht+i)); 
       }
   }
}
 
int main()
{
    char str[] = "abcd"; 
    int n = strlen(str);
    cout << " The permutations of the string are : " << endl;
    charPermu(str, 0, n-1);
     cout << endl;
    return 0;
}
