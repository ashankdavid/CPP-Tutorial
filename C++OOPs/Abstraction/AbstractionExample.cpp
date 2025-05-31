#include <iostream>
using namespace std;
class Add
{
private:
    int num1, num2, total;
public:
    void sum()
    {
        cout << "Enter 2 numbers: " << endl;
        cin >> num1 >> num2;
        total = num1 + num2;
        cout << "Sum of the numbers Entered is: " << total << endl;
    }
};

int main()
{
    Add obj;
    obj.sum();
}