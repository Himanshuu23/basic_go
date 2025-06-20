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
        ll n, ans = 0; cin >> n;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
            v.push_back(temp);   
        }

        if (v[0]) ans++;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == 0 && v[i+1] != 0)
                ans++;
        }

        if (ans >= 2) cout << 2 << endl;
        else cout << ans << endl;
    }

    return 0;
}
