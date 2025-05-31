#include<iostream>
using namespace std;
class Student
{
public:
    string name;
    int usn;

    Student(string name, int usn)
    {
        this->name = name;
        this->usn = usn;
    }

    void display()
    {
        cout << "Name is: " << name << endl;
        cout << "USN is: " << usn << endl;
    }
};

int main()
{
    Student s1("Ashank", 123);
    Student s2("David", 456);

    s1.display();
    s2.display();
}