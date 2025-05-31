#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    int r, c;
    int count = 0;

    // Get the number of rows and columns from the user
    cout << "Enter the number of rows: ";
    cin >> r;
    cout << "Enter the number of columns: ";
    cin >> c;

    // Get the elements of the matrix from the user
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                count++;
            }
        }
    }

    // Check if the matrix is sparse
    if (count > (r * c) / 2) {
        cout << "The matrix is sparse." << endl;
    } else {
        cout << "The matrix is not sparse." << endl;
    }

    // Print the number of zeros and the size of the matrix
    cout << "There are " << count << " zeros in the matrix of size " << r * c << "." << endl;

    return 0;
}
