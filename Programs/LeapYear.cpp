#include <stdio.h>

int main() {
    int year;

    // Asking user to input the year
    printf("Enter a year: ");
    scanf("%d", &year);

    // Checking leap year conditions
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
