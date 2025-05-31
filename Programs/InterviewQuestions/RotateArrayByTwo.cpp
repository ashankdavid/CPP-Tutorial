#include <iostream>
using namespace std;

void rotateArray(int arr[], int size, int positions) {
    // Store the last 'positions' elements in a temporary array
    int temp[positions];
    for (int i = 0; i < positions; i++) {
        temp[i] = arr[size - positions + i];
    }

    // Shift the array towards the right by 'positions'
    for (int i = size - 1; i >= positions; i--) {
        arr[i] = arr[i - positions];
    }

    // Place the stored elements at the beginning
    for (int i = 0; i < positions; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int positions = 2; // Rotate by 2 positions

    rotateArray(arr, size, positions);

    cout << "Rotated Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
