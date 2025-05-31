#include<iostream>
using namespace std;

class Dad
{
public:
    void Drive()
    {
        cout << "Driving..." << endl;
    }
};

class Mom
{
public:
    void Cook()
    {
        cout << "Cooking...." << endl;
    }
};

class Child : public Dad, public Mom
{
public:
    void Study()
    {
        cout << "Studying..." << endl;
    }
};

int main()
{
    Child c;
    c.Drive();
    c.Cook();
    c.Study();
}