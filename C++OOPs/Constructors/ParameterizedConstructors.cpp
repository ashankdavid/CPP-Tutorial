#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    int usn;

    Student(string n, int u)  // Parameterized Constructor
    {
        this->name = n;
        this->usn = u;
    }

    void printDetails()
    {
        cout << "Name is: " << name << endl;
        cout << "USN is: " << usn << endl;
    }
};

int main()
{
    Student s1("Ashank", 123);
    Student s2("David", 456);

    s1.printDetails();
    s2.printDetails();
}