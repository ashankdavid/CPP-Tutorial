#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

// Function to return the minimum number of jumps to reach the end of the array
int minJumps(int arr[], int n) {
    // If the array is empty or the first element is 0, we can't move forward
    if (n == 0 || arr[0] == 0) {
        return INT_MAX;
    }

    // jumps[i] will hold the minimum number of jumps required to reach arr[i] from arr[0]
    int jumps[n];
    jumps[0] = 0;

    // Traverse the array and fill the jumps array
    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX; // Initialize jumps[i] to a very high value
        for (int j = 0; j < i; j++) {
            // Check if arr[i] is reachable from arr[j] and if jumps[j] is not INT_MAX
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = jumps[j] + 1;
                break; // Exit the inner loop once we find a valid jump
            }
        }
    }

    // The last element of jumps array will have the result
    return jumps[n - 1];
}

// Driver code
int main() {
    int arr[] = {1, 5, 2, 7, 5, 6, 3, 7, 8, 3, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = minJumps(arr, n);

    if (result == INT_MAX) {
        cout << "End of the array is not reachable" << endl;
    } else {
        cout << "Minimum number of jumps to reach the end is " << result << endl;
    }

    return 0;
}
