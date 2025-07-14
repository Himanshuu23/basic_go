/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, string t) {
    int n = s.size(), m = t.size();
    if (s == "0" || t == "0") return "0";

    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        int a = s[i] - '0';
        for (int j = m - 1; j >= 0; j--) {
            int b = t[j] - '0';
            int mul = a * b + result[i+j+1];
            result[i+j+1] = mul % 10;
            result[i+j] += mul / 10;
        }
    }

    string res;
    for (int num : result) {
        if (!(res.empty() && num == 0)) res += (num + '0');
    }

    return res.empty() ? "0" : res;
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
