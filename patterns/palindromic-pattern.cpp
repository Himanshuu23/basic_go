#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        int k = 0;
        for (k = i; k >= 1; k--) {
            cout << k << " ";
        }

        for (int j = k + 2; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
