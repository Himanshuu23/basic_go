/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 26;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        cin.ignore();
        string s; getline(cin, s);

        long cnt(0);
        int chars[N] = {0};

        for (int i = 0; i < n; i++) {
            ++chars[s[i] - 'a'];
        }

        for (int i = 0; i < N; i++) {
            cnt += chars[i] % 2;
        }

        cnt <= k + 1 ? cout << "Yes" << endl : cout << "No" << endl;
    }

    return 0;
}
