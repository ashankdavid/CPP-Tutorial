#include<iostream>
using namespace std;
class Student  //Class Definition
{
public:
    //data member or instance variables
    string name;
    int usn;
    string address;
};
int main()
{
    Student s1;
    s1.name = "Ashank David";
    s1.usn = 123;
    s1.address = "Bangalore";

    cout << s1.name << endl;
    cout << s1.usn << endl;
    cout << s1.address << endl;

    return 0;
}