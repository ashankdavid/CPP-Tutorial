#include <iostream>
using namespace std;
int main()
{
  // declare variables
  double x,y,z;

  // take inputs
  cout << "Enter Three Numbers: ";
  cin >> x >> y >> z;

  switch (x > y) 
  {
      // x is greater than y
      case 1 :
       switch(x > z)
        {
            // x is greater than z
            case 1 :
               cout << "Largest = " << x << endl;
               break;
            // z is greater than x
            case 0 :
               cout << "Largest = " << z << endl;
               break;
        }
        break;
      // y is greater than x
      case 0 :
        switch(y > z)
        {
            // y is greater than z
            case 1 :
               cout << "Largest = " << y << endl;
               break;
            // z is greater than y
            case 0 :
               cout << "Largest = " << z << endl;
               break;
        }
        break;
  }
  return 0;
}