// Aggregation: HAS-A relation
#include <iostream>
using namespace std;
class Address
{
public:
    string addressLine;
    string city;
    string state;

    Address(string addressLine, string city, string state)
    {
        this->addressLine = addressLine;
        this->city = city;
        this->state = state;
    }
};

class Student
{
private:
    Address* address;  //Student HAS-A Address
public:
    string name;
    int usn;

    Student(string name, int usn, Address* address)
    {
        this->name = name;
        this->usn = usn;
        this->address = address;
    }

    void display()
    {
        cout << "Name is: " << name << endl;
        cout << "USN is: " << usn << endl;
        cout << "Address is: " << address->addressLine << address->city << address->state << endl;
    }
};

int main()
{
    Address a1 = Address("RR Nagar, ", "Bangalore, ", "Karnataka");
    Student s1("Ashank", 123, &a1);
    s1.display();
}