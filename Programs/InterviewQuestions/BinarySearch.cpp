/*
You are given a sorted array of integers. Write a C++ program that performs a binary search to find a specific target element in the array. Your program should allow the user to input the target element, and it should output whether the target element was found and its index if it exists in the array.
*/

#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int sortedArray[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int target;

    cout << "Enter the target element you want to find: ";
    cin >> target;

    int index = binarySearch(sortedArray, size, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
