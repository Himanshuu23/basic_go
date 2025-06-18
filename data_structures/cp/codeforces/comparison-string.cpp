/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        long n; cin >> n;
        cin.ignore();

        string s; getline(cin, s);

        long ans = 0, curr = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1])
                ++curr;
            else {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        
        ans = max(ans, curr);
        cout << ans + 1 << endl;
    }

    return 0;
}
