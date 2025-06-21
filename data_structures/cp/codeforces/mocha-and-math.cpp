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
        int n, ans; cin >> n;
        vector<int> v(n);

        for(int i = 0; i < n; i++) cin >> v[i];
        ans = v[0];
        for(int i = 0; i < n; i++) ans &= v[i];

        cout << ans << endl;
    }

    return 0;
}
