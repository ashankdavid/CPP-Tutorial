#include <iostream>
using namespace std;
int main()
{
    // total, average, inTwoYears

    int size;
    cout << "Enter the size of a Array: ";
    cin >> size;
    float monthsArray[size]; // = {100, 220, 300, 0, 200, 250};

    float total=0;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter Amount for Month "<< i+1 << ": ";
        cin >> monthsArray[i];
        total = total + monthsArray[i];
    }

    float average = total / (float)size;
    float inTwoYears = average * 24;

    cout << "Total = " << total << endl;
    cout << "Average = " << average << endl;
    cout << "Total in Two Years = " << inTwoYears<< endl;



}