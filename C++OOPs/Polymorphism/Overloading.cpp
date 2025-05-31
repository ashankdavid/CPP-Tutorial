#include <iostream>
using namespace std;
class Addition
{
public:
    int add(int a, int b)
    {
        return a+b;
    }

    int add(int a, int b, int c)
    {
        return a+b+c;
    }

    float add(float a, float b)
    {
        return a+b;
    }
};

int main()
{
    Addition obj;
    cout << obj.add(6,4) << endl;
    cout << obj.add(6,4,10) << endl;
}