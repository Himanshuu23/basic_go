/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(const string& s) {
    string t = s + s;
    int n = s.length();
    vector<int> f(2 * n, -1);
    int k = 0;

    for (int j = 1; j < 2 * n; j++) {
        int i = f[j - k - 1]; // similar to the failure map in KMP -> to check how much we matched so far
        while (i != -1 && t[j] != t[k + i + 1]) { // checking if we have rotated and not reached the same char
            if (t[j] < t[k + i + 1]) k = j - i - 1; // if the prev rotation was better (smaller) than the current one then reverted back to that one
            i = f[i]; // then updating failure array
        }

        if (t[j] != t[k + i + 1]) {
            if (t[j] < t[k]) k = j; // single character is smaller - new best rotation
            f[j - k] = -1;
        } else f[j - k] = i + 1; // update failure array
    }

    return t.substr(k, n);
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
