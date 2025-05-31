#include <iostream>
using namespace std;
int main() {
    int size = 5;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i + j) % 2 == 0) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << endl;
    }
    return 0;
}
