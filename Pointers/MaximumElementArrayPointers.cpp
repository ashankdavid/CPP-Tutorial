/*
Write a C++ program to find the maximum element in an integer array using pointers.

Write a program that prompts the user to input an array of integers, calculates the maximum element in the array using pointers, and then displays the maximum element.

Program Requirements:

Prompt the user to enter the number of elements in the array.
Dynamically allocate memory to store the array.
Ask the user to input each element of the array.
Use pointers to find and display the maximum element in the array.
Properly deallocate the dynamically allocated memory.
Write the complete C++ program to accomplish this task.
*/

#include <iostream>

int main() {
    int n;

    // Prompt the user to enter the number of elements in the array
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    // Dynamically allocate memory to store the array
    int* arr = new int[n];

    // Ask the user to input each element of the array
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Use pointers to find the maximum element in the array
    int* ptr = arr;  // Initialize a pointer to the first element
    int max = *ptr;  // Initialize max with the value of the first element

    for (int i = 1; i < n; i++) {
        ptr++;  // Move the pointer to the next element
        if (*ptr > max) {
            max = *ptr;
        }
    }

    // Display the maximum element in the array
    std::cout << "The maximum element in the array is: " << max << std::endl;

    // Properly deallocate the dynamically allocated memory
    delete[] arr;

    return 0;
}
