/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        
        ans = min(ans, abs(temp));
    }

    cout << ans << endl;

    return 0;
}
