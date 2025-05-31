// Checking if the Matrix is Sparse or Not! using Dynamic Memory Allocation
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;  // Declare a pointer for the matrix
    int r, c;
    int count = 0;

    // Input the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    // Dynamic memory allocation for the matrix
    arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        arr[i] = (int *)malloc(c * sizeof(int));
    }

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter the element at position [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);

            // Count the number of zeros
            if (arr[i][j] == 0) {
                count++;
            }
        }
    }

    // Check if the matrix is sparse
    if (count > (r * c) / 2) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }

    // Display the number of zeros
    printf("There are %d zeros in the matrix of size %d\n", count, r * c);

    // Free dynamically allocated memory
    for (int i = 0; i < r; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
