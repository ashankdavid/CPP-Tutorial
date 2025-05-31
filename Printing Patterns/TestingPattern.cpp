#include <iostream>
#include <cmath>  // For using mathematical functions like sqrt()
using namespace std;

void print_heart(int width) {
    float height = width * 0.6;  // Approximate height of the heart

    // Upper part of the heart
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= 4 * width; j++) {
            // Equation of heart shape in terms of (x, y)
            float dist1 = sqrt(pow(i - width, 2) + pow(j - width, 2));
            float dist2 = sqrt(pow(i - width, 2) + pow(j - 3 * width, 2));

            if ((dist1 < width + 0.5 && dist1 > width - 1.5) || (dist2 < width + 0.5 && dist2 > width - 1.5))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    // Lower part of the heart
    for (int i = 1; i <= 2 * width; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = 0; j < 4 * width + 1 - 2 * i; j++) {
            if (i == 1 || j == 0 || j == 4 * width - 2 * i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int width = 8;  // Adjust the width for a smoother heart
    print_heart(width);
    return 0;
}
