//In Binary Search the array needs to be sorted first
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start=0; 
    int end=n;
    while(start<=end)
    {
        int mid = (start+end)/2;  //finding mid element 

        if(arr[mid]==key) // checking if target value is equal to mid
        {
            return mid;
        }
        else if(arr[mid]>key) //if the key is less than mid means its before mid!
        {
            end = mid-1;
        }
        else //otherwise element is present before mid element
        {
            start=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the Size of the Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    cout << binarySearch(arr,n,key) << endl;
}