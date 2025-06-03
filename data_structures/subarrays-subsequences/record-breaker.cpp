#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> visitors;

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        visitors.push_back(temp);
    }

    int ans = 0, max = visitors[0];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (visitors[1] < visitors[0]) {
                ans++;
                max = visitors[1];
            } else {
                continue;
            }
        }

        if (i == n - 1) {
            if (visitors[n-1] > max) {
                ans++;
            } else {
                continue;
            }
        }

        if (visitors[i] > max) {
            ans++;
            max = visitors[i];
        } else {
            continue;
        }
    }

        cout << ans << endl;
        return 0;
}
