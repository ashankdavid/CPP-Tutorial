#include<iostream>
using namespace std;
class Student
{
public:
    string name;
    int usn;

    void insert(string n, int u)
    {
        name = n;
        usn = u;
    }

    void display()
    {
        cout << "Name is: " << name << endl;
        cout << "USN is: " << usn << endl;
    }
};

int main()
{
    Student s1;
    Student s2;

    s1.insert("Ashank", 123);
    s1.display();

    s2.insert("David", 456);
    s2.display();
}