#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the diamond pattern: ";
    cin >> size;

    for (int i = 1; i <= size; i++) {
        for (int j = i; j < size; j++) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = size - 1; i > 0; i--) {
        for (int j = i; j < size; j++) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";    
        }
        cout << endl;
    }

    return 0;
}
