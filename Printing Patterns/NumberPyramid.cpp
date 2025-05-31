#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the number pyramid pattern: ";
    cin >> size;

    for (int i = 1; i <= size; i++) {
        for (int j = size - i; j > 0; j--) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << k;
        }
        cout << endl;
    }

    return 0;
}