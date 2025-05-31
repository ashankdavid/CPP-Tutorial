#include<iostream>
using namespace std;
class Student
{
public:
    Student() //Default Constructor
    {
        cout << "I'm a Constructor!!" << endl;
    }
};

int main()
{
    Student s1;
    Student s2;
}