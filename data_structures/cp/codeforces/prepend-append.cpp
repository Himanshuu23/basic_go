/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin.ignore();

        string s;
        getline(cin, s);

        int left = 0, right = n - 1;
        while((left < right) && (s[left] != s[right])) { ++left; --right; }
        cout << (right - left + 1) << endl;
    }

    return 0;
}
