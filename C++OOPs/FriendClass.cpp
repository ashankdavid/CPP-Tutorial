#include <iostream>
using namespace std;
class ClassB;
class ClassA {
private:
    int numA;
    friend class ClassB;  // friend class declaration

public:
    ClassA()  // constructor to initialize numA to 12
    {
        numA = 12;
    }
};

class ClassB {
private:
    int numB;

public:
    ClassB()  // constructor to initialize numB to 1
    {
        numB = 1;
    }

    int add()  // member function to add numA from ClassA and numB from ClassB
    {
        ClassA ParameterClassA;
        return ParameterClassA.numA + numB;
    }
};

int main() {
    ClassB objectB;
    cout << "Sum: " << objectB.add();
    return 0;
}