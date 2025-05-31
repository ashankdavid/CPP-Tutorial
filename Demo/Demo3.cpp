#include <stdio.h>

int main() {
    int n1, n2, i, j;

    // Input for first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements of the first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input for second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements of the second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merging both arrays
    int mergedArray[n1 + n2];
    for (i = 0; i < n1; i++) {
        mergedArray[i] = arr1[i];
    }
    for (j = 0; j < n2; j++) {
        mergedArray[i + j] = arr2[j];
    }

    printf("Merged array: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}