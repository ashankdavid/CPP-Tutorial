#include <stdio.h>
void radix_sort(int arr[], int n);
int find_max(int arr[], int n);
void count_sort(int arr[], int n, int p);
int main(){
    int arr[] = {84,599,150,0,420,76,9,1000,68};
    int n = sizeof(arr)/ sizeof(arr[0]); //length of array
    radix_sort(arr,n);
    printf("The Sorted array is :\n");
    for(int i = 0;i < n; i++)
        printf("%d\t",arr[i]);
    return 0;
}

void radix_sort(int arr[], int n){
    int max = find_max(arr, n);
    for(int p = 1;max/p > 0;p *= 10)
        count_sort(arr, n, p);
}

int find_max(int arr[], int n){
    int max = arr[0];
    for(int i = 1;i < n;i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

void count_sort(int arr[], int n, int p){
    int output[n];
    int count[10] = {0};
    for(int i = 0;i < n;i++)
        count[(arr[i]/p)% 10]++;

    for(int i =1; i < 10; i++)
        count[i] += count[i-1];

    for(int i = n-1;i >= 0;i--){
        output[count[(arr[i]/p) % 10] - 1] = arr[i];
        count[(arr[i]/p) % 10]--;
    }

    for(int i = 0;i < n;i++)
        arr[i] = output[i];
}