#include <iostream>
using namespace std;
class Student
{
private:
    int marks;
public:
    string name;
    int usn;
    Student(string n, int u)
    {
        name = n;
        usn = u;
    }
    void setMarks(int m)
    {
        marks = m;
    }

    int getMarks()
    {
        return marks;
    }

    void printDetails()
    {
        cout << "Name is: " << name << endl;
        cout << "USN is: " << usn << endl;
    }
};

int main()
{
    int marks;
    cout << "Enter Marks: " << endl;
    cin >> marks;
    Student s1("Ashank", 123);
    s1.setMarks(marks);
    s1.printDetails();
    cout << "Marks are: " << s1.getMarks();
}