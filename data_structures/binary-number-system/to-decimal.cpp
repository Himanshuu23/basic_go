#include <bits/stdc++.h>
using namespace std;

int baseToDecimal(const string& number, int base) {
    int decimal = 0;
    int power = 1; 

    for (int i = number.length() - 1; i >= 0; --i) {
        char digitChar = toupper(number[i]);
        int digit;

        if (isdigit(digitChar)) {
            digit = digitChar - '0';
        } else if (digitChar >= 'A' && digitChar <= 'F') {
            digit = digitChar - 'A' + 10;
        } else {
            throw invalid_argument("Invalid character in input number");
        }

        if (digit >= base) {
            throw invalid_argument("Digit exceeds base");
        }

        decimal += digit * power;
        power *= base;
    }

    return decimal;
}

int main() {
    string s;
    getline(cin, s);

    cout << baseToDecimal(s, 2) << endl;
    cout << baseToDecimal(s, 8) << endl;
    cout << baseToDecimal(s, 16) << endl;

    return 0;
}
