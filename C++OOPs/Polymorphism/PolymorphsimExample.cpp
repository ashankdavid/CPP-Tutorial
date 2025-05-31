#include<iostream>
using namespace std;
class India
{
public:
    void Capital()
    {
        cout << "New Delhi is Capital of India" << endl;
    }
};

class USA
{
public:
    void Capital()
    {
        cout << "Washington DC is the Capital of USA" << endl;
    }
};

int main()
{
    India objIND;
    USA objUSA;
    objIND.Capital();
    objUSA.Capital();
}