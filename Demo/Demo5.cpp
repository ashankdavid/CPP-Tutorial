#include <iostream>
#include <string>
using namespace std;

// Function to replace all occurrences of a character in a string
void replaceChar(string &str, char oldChar, char newChar) {
    // Loop through the string and replace occurrences of oldChar
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    string str;
    char oldChar, newChar;

    // Input the string
    cout << "Enter a string: ";
    getline(cin, str);

    // Input the character to be replaced and the new character
    cout << "Enter the character to replace: ";
    cin >> oldChar;
    cout << "Enter the new character: ";
    cin >> newChar;

    // Replace the old character with the new one
    replaceChar(str, oldChar, newChar);

    // Output the modified string
    cout << "Modified string: " << str << endl;

    return 0;
}