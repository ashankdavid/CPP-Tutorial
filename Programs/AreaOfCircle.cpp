#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, area;

    // Asking user for the radius of the circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculating the area of the circle
    area = PI * radius * radius;

    // Displaying the result
    printf("The area of the circle is: %.2f\n", area);

    return 0;
}
