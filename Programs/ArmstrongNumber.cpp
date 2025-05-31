// #include <iostream>
// #include <cmath>
// using namespace std;

// // Function to check if a number is an Armstrong number
// bool isArmstrong(int num) {
//     int originalNum = num, sum = 0, digits = 0;
    
//     // Count the number of digits
//     while (num > 0) {
//         num /= 10;
//         digits++;
//     }
    
//     num = originalNum;
    
//     // Calculate the sum of digits raised to the power of the number of digits
//     while (num > 0) {
//         int digit = num % 10;
//         sum += pow(digit, digits);
//         num /= 10;
//     }
    
//     // Check if the sum is equal to the original number
//     return sum == originalNum;
// }

// int main() {
//     // Find and display all Armstrong numbers between 1 and 1000
//     cout << "Armstrong numbers between 1 and 1000 are: " << endl;
//     for (int i = 1; i <= 1000; i++) {
//         if (isArmstrong(i)) {
//             cout << i << endl;
//         }
//     }
    
//     return 0;
// }



// #include <stdio.h>
// #include <math.h>

// // Function to check if a number is an Armstrong number
// int isArmstrong(int num) {
//     int originalNum = num, sum = 0, digits = 0;

//     // Count the number of digits
//     while (num > 0) {
//         num /= 10;
//         digits++;
//     }

//     num = originalNum;

//     // Calculate the sum of digits raised to the power of the number of digits
//     while (num > 0) {
//         int digit = num % 10;
//         sum += pow(digit, digits);
//         num /= 10;
//     }

//     // Check if the sum is equal to the original number
//     return sum == originalNum;
// }

// int main() {
//     // Find and display Armstrong numbers between 10 and 1000, excluding single digits
//     printf("Armstrong numbers between 10 and 1000 are:\n");
//     for (int i = 1; i <= 1000; i++) {  // Start from 10 to exclude single digits
//         if (isArmstrong(i)) {
//             printf("%d\n", i);
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNum, remainder, n = 0, result;

    printf("Armstrong numbers between 1 and 1000 are:\n");

    // Loop through each number from 1 to 1000
    for (num = 1; num <= 1000; ++num) {
        result = 0;
        originalNum = num;
        n = (int) log10(num) + 1; // Get number of digits in the number

        // Calculate Armstrong number
        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += pow(remainder, n);
            originalNum /= 10;
        }

        // If the number is equal to the sum of the powers of its digits, it is an Armstrong number
        if (result == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}

