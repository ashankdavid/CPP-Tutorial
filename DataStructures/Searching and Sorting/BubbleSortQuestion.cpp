// You are working on a retail management system that handles product prices. The system is designed to sort a list of product prices before generating a report for the store. However, you have been informed that the prices are initially in a random order, and the system needs to ensure that the prices are sorted in ascending order to facilitate accurate reporting.

// Your task is to implement a function that will sort an array of floating-point numbers representing product prices. You need to write a function to achieve this and demonstrate its usage with a sample array.

// Task:

// Write a C++ function sortPrices that sorts an array of floating-point numbers representing product prices in ascending order.
// The function should take an array of prices and its size as input parameters.
// In your main function, demonstrate the usage of sortPrices by sorting and displaying a sample array of product prices.

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no elements were swapped, break the loop
        if (!swapped) break;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
