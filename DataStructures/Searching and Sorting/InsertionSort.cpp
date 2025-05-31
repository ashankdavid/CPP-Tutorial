#include <stdio.h>
void print(int arr[], int n);
void insertion_Sort(int arr[], int n);
int main()
{
    int arr[] = {66,84,5,10,51,15,58,17,30};
    int n = sizeof(arr)/ sizeof(arr[0]);
    print(arr, n);
    insertion_Sort(arr, n);
    print(arr, n);
    return 0;
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
void insertion_Sort(int arr[], int n){
    int j, key;
    for(int i = 1;i < n;i++){
        key = arr[i];
        j = i - 1;
        while(j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}