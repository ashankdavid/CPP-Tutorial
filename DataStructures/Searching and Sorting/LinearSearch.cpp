#include <iostream>
using namespace std;

int LinearSearch(int arr[], int size, int key)
{
    for(int i=0;i<size;i++) //so that the array can be travesed
    {
        if(arr[i] == key) //checking if the element is found
        {
            cout << "Element is on index: ";
            return i; //returning the index
        }
    }
    return -1; //if the element is not found then return -1!
}

int main()
{
    int n; //for the size of the array
    cout << "Enter the Size of the Array: ";
    cin >> n;

    cout << "Please Enter " << n << " Elements in the Array: " << endl;
    int arr[n];
    for(int i=0;i<n;i++) //to take the input in the array
    {
        cin >> arr[i];
    }

    int key; //so that the element that needs to be searched can be asked by the user.
    cout << "Enter the Element to be Searched: ";
    cin >> key;

    cout << LinearSearch(arr, n, key); //calling the Linear Search function
}