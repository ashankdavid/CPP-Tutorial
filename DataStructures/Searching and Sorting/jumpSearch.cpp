#include<iostream>
#include<cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key)
{
    int step = sqrt(n); // Step size to jump
    int prev = 0;

    // Jumping through blocks to find the range where the key might exist
    while (arr[min(step, n) - 1] < key) 
    {
        prev = step;
        step += sqrt(n); // Jump to the next block
        if (prev >= n) { // If the step exceeds the array size
            return -1; // Element not found
        }
    }

    // Perform linear search within the identified block
    for (int i = prev; i < min(step, n); i++) 
    {
        if (arr[i] == key) {
            return i; // Return the index if the element is found
        }
    }

    return -1; // Element not found
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

    int result = jumpSearch(arr, n, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
