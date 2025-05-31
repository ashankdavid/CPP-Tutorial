#include<iostream>
using namespace std;

// Recursive Binary Search Function
int recursiveBinarySearch(int arr[], int start, int end, int key)
{
    // Base case: If the start index exceeds the end index
    if (start > end) {
        return -1; // Element not found
    }

    int mid = (start + end) / 2; // Calculate the mid element

    if (arr[mid] == key) { // If the middle element matches the key
        return mid;
    }
    else if (arr[mid] > key) { // If the key is smaller than the mid element
        return recursiveBinarySearch(arr, start, mid - 1, key);
    }
    else { // If the key is greater than the mid element
        return recursiveBinarySearch(arr, mid + 1, end, key);
    }
}

int main()
{
    int n;
    cout << "Enter the Size of the Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    // Call the recursive binary search function
    int result = recursiveBinarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
