#include <iostream>
using namespace std;

#define N 3  // Define the size of the matrix (can be changed as needed)


void rotateMatrix(int matrix[N][N], int n) {
    for(int j=0; j<n; j++){
        for(int i=n-1; i>=0; i--){
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

    cout << "Original Matrix was:" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix after 90 degrees clockwise rotation:" << endl;
    rotateMatrix(matrix, N);

    return 0;
}
