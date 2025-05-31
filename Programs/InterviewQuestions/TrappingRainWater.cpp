// C++ implementation of the approach 
// Brute Force Approach!
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the maximum 
// water that can be stored 
int maxWater(int arr[], int n) 
{ 
	// To store the maximum water 
	// that can be stored 
	int res = 0; 

	// For every element of the array 
	for (int i = 1; i < n - 1; i++) { 

		// Find the maximum element on its left 
		int left = arr[i]; 
		for (int j = 0; j < i; j++) 
			left = max(left, arr[j]); 

		// Find the maximum element on its right 
		int right = arr[i]; 
		for (int j = i + 1; j < n; j++) 
			right = max(right, arr[j]); 

		// Update the maximum water 
		res = res + (min(left, right) - arr[i]); 
	} 

	return res; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {3,0,0,2,0,4}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << maxWater(arr, n); 

	return 0; 
}















// // C++ program to find maximum amount of water that can
// // be trapped within given set of bars.
// // Optimized Approach
// #include <bits/stdc++.h>
// using namespace std;

// int findWater(int arr[], int n)
// {
// 	int left[n];

// 	int right[n];

// 	int water = 0;

// 	left[0] = arr[0];
// 	for (int i = 1; i < n; i++)
// 		left[i] = max(left[i - 1], arr[i]);

// 	right[n - 1] = arr[n - 1];
// 	for (int i = n - 2; i >= 0; i--)
// 		right[i] = max(right[i + 1], arr[i]);

// 	for (int i = 1; i < n - 1; i++) {
// 		int var = min(left[i - 1], right[i + 1]);
// 		if (var > arr[i]) {
// 			water += var - arr[i];
// 		}
// 	}

// 	return water;
// }

// // Driver program
// int main()
// {
// 	int arr[] = {3,0,0,2,0,4};
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	cout << findWater(arr, n);
// 	return 0;
// }
