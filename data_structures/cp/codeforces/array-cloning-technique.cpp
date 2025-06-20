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
        int n, mx = 0; cin >> n;
        map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
            mp[temp]++;
            mx = max(mx, mp[temp]);
        }

        int ans = n - mx;
        while (mx < n) {
            ans++;
            mx *= 2;
        }

        cout << ans << endl;
    }

    return 0;
}
