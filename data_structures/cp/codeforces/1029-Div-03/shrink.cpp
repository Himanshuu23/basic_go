/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            v.push_back(i + 1);
        }

        for (int i = 1; i < n; i += 2) {
            if ((i == (n - 1)) && (n % 2))
                swap(v[n-1], v[n-2]);
            else if (i != (n - 1))
                swap(v[i], v[i+1]);
        }

        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
