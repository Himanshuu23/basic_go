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
        int a, b, c, d, ans = 0;
        cin >> a >> b >> c >> d;
    
        ans = abs(b - d);
        b += ans;
        a += ans;
        ans += abs((a-c));
        a -= abs(a-c);

        if ((a == c) && (b == d))
            cout << ans << endl;   
        
        else 
            cout << -1 << endl;
    }

    return 0;
}
