/*
Write a C++ function incrementByTwo that takes an integer argument by reference and increments the value by 2. Display the original and modified values in the main function. Call this function to demonstrate the increment operation.
*/

#include <iostream>

void incrementByTwo(int *num) {
    *num += 2;
}

int main() {
    int x = 10;

    std::cout << "Original value: " << x << std::endl;

    incrementByTwo(&x);

    std::cout << "Value after incrementing by 2: " << x << std::endl;

    return 0;
}
