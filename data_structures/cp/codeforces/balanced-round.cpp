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
        ll n, k; cin >> n >> k;
        ll a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        ll cur = 1, tot = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] <= k)
                cur++;
            else { 
                tot = max(tot, cur);
                cur = 1;
            }
        }

        tot = max(tot, cur);
        cout << n - tot << endl;
    }

    return 0;
}
