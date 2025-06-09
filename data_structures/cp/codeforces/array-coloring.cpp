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
        int n, sum = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            sum += temp;            
        }

        (sum % 2 == 0) ? cout << "Yes" << endl : cout << "No" << endl;
    }

    return 0;
}
