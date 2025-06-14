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
        int n, ct = 0, ans = 0; cin >> n;

        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;

            if (temp == 0)
                ++ct;

            else {
                ct = 0;
            }
            
            ans = max(ans, ct);
        }

        cout << ans << endl;
    }

    return 0;
}
