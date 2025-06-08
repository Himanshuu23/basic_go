#include <bits/stdc++.h>
using namespace std;

string addBinary(const string& a, const string& b) {
    string result = "";
    int carry = 0;

    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int bitA = (i >= 0) ? a[i] - '0' : 0;
        int bitB = (i >= 0) ? b[i] - '0' : 0;

        int sum = bitA + bitB + carry;

        result += (sum % 2) + '0';
        carry = sum / 2;

        --i;
        --j;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a = "1101";
    string b = "1011";

    cout << addBinary(a, b) << endl;

    return 0;
}
