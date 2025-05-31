/* HackerEarth : DXC
 * Problem Statement: Imagine you have a printer which can print n number of pages
 * Create a Printer Class
 * Provide attributes : name, availablePaper
 * Create a parameterised constructor to take the given values from the user
 * If the printer can print the length of the textDocument divided 10 / page,
 * demonstrate how you will handle exceptions
 * if the printer runs out of Paper in all the possible ways.
 */

#include <iostream>
using namespace std;
class Printer {
    string _name;
    int _availablePaper;
public:
    Printer(string name, int paper){
        _name = name;
        _availablePaper = paper;
    }
    void PrintDoc(string txtDoc){
        int requiredPaper = txtDoc.length() / 10; // 40/10 = 4 paper
        if (requiredPaper > _availablePaper){
            throw 404;
            throw "Please Add More Paper Before Printing..!!";
        }
        cout << "Printing....!!!!" << txtDoc << endl;
        _availablePaper -= requiredPaper;
    }
};
int main() {
    Printer myPrinter("HP LaserJet M293", 10);
    try {
        myPrinter.PrintDoc("Hello, I am Prerana. I am a Data Scientist");
        myPrinter.PrintDoc("Hello, I am Shreya. I am a Data Engineer");
        myPrinter.PrintDoc("Hello, I am Punya. I am a Data Analyst");
    }catch (int errorCode){
        cout << errorCode << " No paper available..!!" << endl;
    }catch (const char * txtException){
        cout << "Exception: " << txtException << endl;
    }catch (...){
        cout << "Something unexpected happened..!!" << endl;
    }
    return 0;
}