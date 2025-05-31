// Rotate an array by one position in c
#include <iostream>
using namespace std;
void rotateArray(int arr[], int size){
    // Store the last element of the array
    int lastElement = arr[size-1];
    // Shift the array towards the right by one position
    for (int i=size-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    // Assign the last element as the first element
    arr[0] = lastElement;
}
int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    rotateArray(arr, size);
    cout << "Rotated Array: ";
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}