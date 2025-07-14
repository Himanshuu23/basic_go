/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    int i(0), n(s.size());
    while (i < n & s[i] == ' ') i++;
    
    bool isNegative = false;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        isNegative = (s[i] == '-');
        i++;
    }

    long res(0);
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';

        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
            return isNegative ? INT_MIN : INT_MAX;
        }

        res = res * 10 + digit;
        i++;
    }

    return isNegative ? -res : res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
