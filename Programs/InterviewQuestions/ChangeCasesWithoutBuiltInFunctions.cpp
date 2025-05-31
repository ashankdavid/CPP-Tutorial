#include <iostream>
using namespace std;

int main() {
    string s = "ashank";
    
    // Convert lowercase to uppercase
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
    cout << s << endl;

    // Convert uppercase to lowercase
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    cout << s << endl;

    return 0;
}
