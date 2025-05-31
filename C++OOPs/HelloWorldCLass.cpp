#include <iostream>
using namespace std;
class HelloWorld
{
public:
    void PrintHelloWorld()
    {
        cout << "Hello World!" << endl;
    }
};

int main(){
    HelloWorld obj; 
    obj.PrintHelloWorld();
    return 0;
}