// C++ implementation to find the smallest sum
// contiguous subarray
#include <iostream>
#include<climits>
using namespace std;

// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n)
{
	// to store the minimum value that is ending
	// up to the current index
	int currentMin = INT_MAX;
	
	// to store the minimum value encountered so far
	int minimum = INT_MAX;
	
	// traverse the array elements
	for (int i=0; i<n; i++)
	{
		// if CurrentMin > 0, then it could not possibly
		// contribute to the minimum sum further
		if (currentMin > 0)
			currentMin = arr[i];
		
		// else add the value arr[i] to CurrentMin
		else
			currentMin += arr[i];
		 
		// update minimum
		minimum = min(minimum, currentMin);		
	}
	
	// required smallest sum contiguous subarray value
	return minimum;
}


// Driver program to test above
int main()
{
	int arr[] = {3, -4, 2, -3, -1, 7, -5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Smallest sum: " << smallestSumSubarr(arr, n);
	return 0;
}
