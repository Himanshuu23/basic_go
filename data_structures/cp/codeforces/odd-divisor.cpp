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
        ll n, div; cin >> n; div = n / 2;
        if (n & 1) cout << "Yes" << endl;
        else {
            bool ans = false;
            while (div > 2) {
                div /= 2;
                if (div & 1) {
                    if (n % div == 0) {
                        ans = true;
                        break;
                    }
                }
            }
            puts(ans ? "Yes" : "No");
        }
    }

    return 0;
}
