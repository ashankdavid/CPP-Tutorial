#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrangeAndSort(int arr[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(&arr[i], &arr[j]);
            j++;
        }
    }
    // Sort the negative part
    sort(arr, arr + j);
    // Sort the positive part
    sort(arr + j, arr + n);
}

// A utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeAndSort(arr, n);
    printArray(arr, n);
    return 0;
}
