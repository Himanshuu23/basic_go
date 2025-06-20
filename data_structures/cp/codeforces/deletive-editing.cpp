/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, w, ans = "";
        cin >> s >> w;

        int a[26] = {0};

        for (char c : w) a[c - 'A']++;

        for (int i = s.size() - 1; i >= 0; i--) {
            int x = s[i] - 'A';
            if (a[x]) {
                ans += s[i];
                a[x]--;
            }
        }

        reverse(ans.begin(), ans.end());
        if (ans == w) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
