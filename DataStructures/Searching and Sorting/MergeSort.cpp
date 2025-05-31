#include <stdio.h>
void merge_sort(int arr[], int n);
void merge(int arr[],int left[], int right[],int left_size, int right_size);

int main(){
    int arr[] = {4,84,17,88,75,53,45,23,46,0,106,21,95,50,11};
    int n = sizeof(arr)/ sizeof(arr[0]);
    merge_sort(arr,n);
    for(int i =0; i< n;i++)
        printf("%d\t", arr[i]);
    return 0;
}

void merge_sort(int arr[], int n){
    if(n < 2)
        return;
    int mid = n/2;
    int left[mid], right[n-mid];
    for(int i = 0;i < mid; i++)
        left[i] = arr[i];
    for(int i = mid;i < n; i++)
        right[i - mid] = arr[i];
    merge_sort(left,mid);
    merge_sort(right,n-mid);
    merge(arr,left,right,mid,n - mid);
}

void merge(int arr[],int left[], int right[],int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    while(i < left_size && j < right_size){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < left_size){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < right_size){
        arr[k] = right[j];
        j++;
        k++;
    }
}