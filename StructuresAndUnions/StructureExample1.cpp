#include <iostream>
using namespace std;
struct Student
{
    string name;
    int rollNo;
}s1,s2;

int main()
{
    // Assigning Values of S1 Attributes
    s1.name = "Ashank";
    s1.rollNo = 001;

    // Assigning Values of S2 Attributes
    s2.name = "David";
    s2.rollNo = 002;

    //Printing the Details of S1
    cout << "Name is: " << s1.name << endl;
    cout << "RollNo is: " << s1.rollNo << endl;

    cout << " " << endl; // To print Space in Between

    //Printing the Details of S2
    cout << "Name is: " << s2.name << endl;
    cout << "RollNo is: " << s2.rollNo << endl;

}