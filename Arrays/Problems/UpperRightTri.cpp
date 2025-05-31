// Printing Upper Triangle Matrix Pattern
#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    int r, c;
    cout << "Enter the number of rows:" << endl;
    cin >> r;
    cout << "Enter the number of columns:" << endl;
    cin >> c;
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nEntered Matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\nUpper Triangular Matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j >= i) {
                cout << arr[i][j] << "  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
    return 0;
}
