#include<iostream>
using namespace std;
void selection_sort(int arr[], int n);
void swap(int *a, int *b);

int main()
{
    int arr[] = {66,84,5, 10, 51,15,58,17,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    for(int i =0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

void selection_sort(int arr[], int n){
    for(int i = 0;i < n - 1;i++)
    {
        int min_index = i;
        for(int j = i + 1;j < n;j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}