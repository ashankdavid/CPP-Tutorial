#include <iostream>
using namespace std;
class ClassB;
class ClassA {

private:
    int numA;
    friend int add(ClassA, ClassB); // friend function declaration

public:
    ClassA() // constructor to initialize numA to 12
    {
        numA = 12;
    }
};

class ClassB {

private:
    int numB;
    friend int add(ClassA, ClassB); // friend function declaration

public:
    ClassB() // constructor to initialize numB to 1
    {
        numB = 1;
    }
};

// access members of both classes
int add(ClassA ParameterClassA, ClassB ParameterClassB) {
    return (ParameterClassA.numA + ParameterClassB.numB);
}

int main() {
    ClassA objectA;
    ClassB objectB;
    cout << "Sum: " << add(objectA, objectB);
    return 0;
}