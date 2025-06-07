/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

bool check(string s, string x) {
    if (x.size() < s.size())
        return false;

    for (int i = 0; i < x.size() - s.size() + 1; i++) {
        if (x.substr(i, s.size()) == s) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        cin.ignore();
        
        string s1, s2;

        getline(cin, s1);
        getline(cin, s2);

        string x1 = s1 + s1;
        string x2 = x1 + x1;
        string x3 = x2 + x2;
        string x4 = x3 + x3;
        string x5 = x4 + x4;

        long long ans = -1;

        if (check(s2, s1))
            ans = 0;

        else if (check(s2, x1))
            ans = 1;

        else if (check(s2, x2))
            ans = 2;

        else if (check(s2, x3))
            ans = 3;

        else if (check(s2, x4))
            ans = 4;

        else if (check(s2, x5))
            ans = 5;

        cout << ans << endl;
    }

    return 0;
}
