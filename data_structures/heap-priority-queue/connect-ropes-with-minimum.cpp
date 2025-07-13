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
        int n, res(0); cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        make_heap(v.begin(), v.end(), greater<int>());
        while (v.size() > 1) {
            int ct(2), ans(0);
            while (ct--) {
                pop_heap(v.begin(), v.end(), greater<int>());
                res += v.back();
                ans += v.back();
                v.pop_back();
            }
            v.push_back(ans);
            pop_heap(v.begin(), v.end(), greater<int>());
        }

        cout << res << endl;
    }

    return 0;
}
