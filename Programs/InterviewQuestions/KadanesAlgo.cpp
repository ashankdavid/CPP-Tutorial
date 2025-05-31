#include <iostream>
using namespace std;
int kadaneAlgorithm(int arr[], int size)
{
    int currentMax = arr[0];
    int maximum = arr[0];
    for (int i = 1; i < size; i++)
    {
        currentMax = max(arr[i], currentMax + arr[i]);
        maximum = max(maximum, currentMax);
    }
    return maximum;
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxSum = kadaneAlgorithm(arr, size);
    cout << "Maximum sum subarray: " << maxSum << endl;
    return 0;
}