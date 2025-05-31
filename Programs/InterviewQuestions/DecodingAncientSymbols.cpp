/*
In an archaeological expedition to a remote island, a team of researchers discovered a set of ancient inscriptions. These inscriptions appear to be encoded using a numeral system that is unique to this civilization. Your task is to design a data structure and algorithm to decode these inscriptions and convert them into modern numerals.

Question:
The ancient inscriptions consist of sequences of symbols that are believed to represent numbers. The symbols are hieroglyphic-like characters, and initial analysis suggests that they follow a certain pattern. After thorough examination, the following rules have been deciphered:

Each numeral in the ancient system is represented by one or more symbols.
Symbols can be of three types: 'I', 'V', and 'X'.
A number is formed by combining these symbols from left to right.
If a smaller numeral precedes a larger numeral, you subtract the smaller numeral. For example, 'IV' represents 4 (5 - 1) and 'IX' represents 9 (10 - 1).
If a smaller numeral follows a larger numeral, you add the smaller numeral. For example, 'VI' represents 6 (5 + 1) and 'XII' represents 12 (10 + 1 + 1).
Your task is to write a C++ program that takes a string of ancient symbols as input and converts it into its corresponding modern numeral representation.

Constraints:

The length of the input string will not exceed 20 symbols.
The input will be a valid ancient numeral representation.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int romanToDecimal(string s) {
    unordered_map<char, int> symbolValues = {{'I', 1}, {'V', 5}, {'X', 10}};
    int result = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && symbolValues[s[i]] < symbolValues[s[i + 1]]) {
            result -= symbolValues[s[i]];
        } else {
            result += symbolValues[s[i]];
        }
    }
    
    return result;
}

int main() {
    string ancientSymbols;
    cout << "Enter ancient symbols: ";
    cin >> ancientSymbols;
    
    int modernNumeral = romanToDecimal(ancientSymbols);
    cout << "Modern numeral representation: " << modernNumeral << endl;
    
    return 0;
}


/**
 * If by chance u want to modify your code for invalid inputs then
 * then you can modify the code like this:
 * 
 * 
#include <iostream>
#include <unordered_map>

using namespace std;

bool isValidRomanNumeral(const string& s) {
    unordered_map<char, int> validSymbols = {{'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    for (int i = 0; i < s.size(); i++) {
        if (validSymbols.find(s[i]) == validSymbols.end()) {
            return false; // Invalid symbol found
        }
        
        if (i > 0 && validSymbols[s[i]] > validSymbols[s[i - 1]]) {
            // Check for valid order of symbols
            if ((s[i - 1] == 'I' && (s[i] == 'V' || s[i] == 'X')) ||
                (s[i - 1] == 'X' && (s[i] == 'L' || s[i] == 'C')) ||
                (s[i - 1] == 'C' && (s[i] == 'D' || s[i] == 'M'))) {
                return false; // Invalid order of symbols
            }
        }
    }
    
    return true;
}

int romanToDecimal(string s) {
    unordered_map<char, int> symbolValues = {{'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && symbolValues[s[i]] < symbolValues[s[i + 1]]) {
            result -= symbolValues[s[i]];
        } else {
            result += symbolValues[s[i]];
        }
    }
    
    return result;
}

int main() {
    string ancientSymbols;
    cout << "Enter ancient symbols: ";
    cin >> ancientSymbols;
    
    if (!isValidRomanNumeral(ancientSymbols)) {
        cout << "Invalid Roman numeral input." << endl;
        return 1; // Exit with an error code
    }
    
    int modernNumeral = romanToDecimal(ancientSymbols);
    cout << "Modern numeral representation: " << modernNumeral << endl;
    
    return 0;
}
*/