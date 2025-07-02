/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int num1, int num2) {
    int target = __builtin_popcount(num2);
    int ans = num1;

    int current = __builtin_popcount(ans);

    // If too many 1s, unset from MSB
    if (current > target) {
        for (int i = 31; i >= 0 && current > target; --i) {
            if (ans & (1 << i)) {
                ans ^= (1 << i);  // unset bit
                --current;
            }
        }
    }
    // If too few 1s, set from LSB
    else if (current < target) {
        for (int i = 0; i < 32 && current < target; ++i) {
            if ((ans & (1 << i)) == 0) {
                ans |= (1 << i);  // set bit
                ++current;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int num1, num2; cin >> num1 >> num2;
        cout << solve(num1, num2) << endl;
    }

    return 0;
}
