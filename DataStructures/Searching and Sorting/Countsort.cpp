#include<iostream>
using namespace std;

void count_sort(int arr[], int n)
{
    int k = arr[0];
    for(int i=0;i<n;i++) // to find the max number of elements in the array
    {
        if (arr[i] > k) 
        {
            k = arr[i];
        }
    }

    int count[10] = {0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++; // to arange the elements in count array according to there indexes
    }  

    for(int i=1;i<=k;i++) // to modify the count array!
    {
        count[i]+=count[i-1]; // to add the element with the count of previous element
    }

    int output[n]; // final output array
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]] = arr[i]; //finally keeping the elements in there place by decrementing there idenxes by one 
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=output[i]; // finally coping the contents to the original array
    }
}

int main()
{
    int arr[] = {1,3,2,3,4,1,6,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    count_sort(arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}