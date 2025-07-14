/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, string t) {
    int carry = 0;
    string res;

    int len = max(s.size(), t.size());
    for (int i = 0; i < len; i++) {
        int digitS = i < s.size() ? s[s.size() - 1 - i] - '0' : 0;
        int digitT = i < t.size() ? t[t.size() - 1 - i] - '0' : 0;

        int sum = digitS + digitT + carry;
        res += (sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        res += (carry + '0');

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        cout << solve(s, t) << endl;
    }

    return 0;
}
