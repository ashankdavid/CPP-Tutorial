// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

#include <stdio.h>
void sortZeroOneTwo(int arr[], int size){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    // Count the number of 0s, 1s & 2s
    for (int i=0; i<size; i++){
        if (arr[i] == 0){
            count0++;
        }
        else if (arr[i] == 1){
            count1++;
        } else {
            count2++;
        }
    }
    int index = 0;
    // Overwrite the original array based on the count of 0s, 1s & 2s
    while (count0 > 0){
        arr[index++] = 0;
        count0--;
    }
    while (count1 > 0){
        arr[index++] = 1;
        count1--;
    }
    while (count2 > 0){
        arr[index++] = 2;
        count2--;
    }
}
int main() {
    int size;
    printf("Enter the size:\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array (0 or 1 or 2)\n");
    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Before Sorting:\n");
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    sortZeroOneTwo(arr, size);
    printf("After Sorting:\n");
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}