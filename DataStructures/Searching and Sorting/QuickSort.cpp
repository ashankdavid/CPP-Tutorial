#include <stdio.h>
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a,int *b);

int main(){
    int arr[] = {50,40,10,90,80,100,200,20,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n - 1);
    for (int i = 0; i < n; i++)
        printf("%d\t",arr[i]);
    return 0;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int part = partition(arr,low,high);
        quickSort(arr,low,part - 1);
        quickSort(arr,part + 1,high);
    }
}
int partition(int arr[], int low, int high){
    int pivot  = arr[low];
    int i = low + 1,j = high;
    while(i <= j){
        while(i <= j && arr[i] < pivot)
            i++;
        while(i <= j && arr[j] > pivot)
            j--;
        if(i <= j){
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}