#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x;
    cin >> t;

    while(t--) {
        cin >> n >> x;
        vector<int> a;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            a.push_back(temp);
        }

        int minFuel = a[0];
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                minFuel = max(minFuel, 2*(x - a[i-1]));
            } else {
                minFuel = max(minFuel, a[i] - a[i-1]);
            }
        }

        cout << minFuel << endl;
    }

    return 0;
}
