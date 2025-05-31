#include <iostream>
using namespace std;

#define N 3  // Define the size of the matrix (can be changed as needed)

void rotateMatrix(int matrix[N][N], int n) {
    // First step is to transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Second step is to reverse each row manually
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

void printMatrix(int matrix[][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    printMatrix(matrix, N);

    rotateMatrix(matrix, N);

    cout << "Matrix after 90 degrees clockwise rotation:" << endl;
    printMatrix(matrix, N);

    return 0;
}
