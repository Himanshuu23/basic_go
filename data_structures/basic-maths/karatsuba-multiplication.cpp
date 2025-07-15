/*
    Author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

// Helper: Adds leading zeros to make lengths equal
void padZero(string &a, string &b) {
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
}

// Helper: Adds two big integers as strings
string addStr(const string &a, const string &b) {
    string res = "";
    int carry = 0;
    int n = max(a.size(), b.size());
    padZero(const_cast<string&>(a), const_cast<string&>(b));
    for (int i = n - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        res += (sum % 10) + '0';
    }
    if (carry) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}

// Helper: Subtracts b from a (a > b assumed)
string subStr(const string &a, const string &b) {
    string res = "";
    int borrow = 0;
    string A = a, B = b;
    padZero(A, B);
    int n = A.size();
    for (int i = n - 1; i >= 0; i--) {
        int diff = (A[i] - '0') - (B[i] - '0') - borrow;
        if (diff < 0) diff += 10, borrow = 1;
        else borrow = 0;
        res += (diff + '0');
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back(); // remove leading zeros
    reverse(res.begin(), res.end());
    return res;
}

// Karatsuba recursive function
string karatsuba(string x, string y) {
    padZero(x, y);
    int n = x.size();
    if (n == 0) return "0";
    if (n == 1)
        return to_string((x[0] - '0') * (y[0] - '0'));

    int m = n / 2;
    string a = x.substr(0, n - m);
    string b = x.substr(n - m);
    string c = y.substr(0, n - m);
    string d = y.substr(n - m);

    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string ab_cd = karatsuba(addStr(a, b), addStr(c, d));
    string ad_plus_bc = subStr(subStr(ab_cd, ac), bd);

    // Multiply with powers of 10 by adding zeros
    ac += string(2 * m, '0');
    ad_plus_bc += string(m, '0');

    string result = addStr(addStr(ac, ad_plus_bc), bd);
    // remove leading zeros
    int i = 0;
    while (i < result.size() - 1 && result[i] == '0') i++;
    return result.substr(i);
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    cout << karatsuba(num1, num2) << endl;
    return 0;
}
