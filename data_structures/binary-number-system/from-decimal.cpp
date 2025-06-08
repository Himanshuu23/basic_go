#include <bits/stdc++.h>
using namespace std;

string decimalToBase(int decimal, int base) {
    if (decimal == 0) return "0";
    
    string result = "";
    char digits[] = "0123456789ABCDEF";

    while (decimal > 0) {
        int remainder = decimal % base;
        result += digits[remainder];
        decimal /= base;
    }

    reverse(result.begin(), result.end());
    return result;
}
int main() {
    
    cout << decimalToBase(255, 2) << endl;
    cout << decimalToBase(255, 8) << endl;
    cout << decimalToBase(255, 16) << endl;
    
    return 0;
}
