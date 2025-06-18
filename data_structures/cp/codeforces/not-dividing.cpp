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
        int n; cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
     
            if (a[i] == 1)
                a[i]++;
        }
     
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] % a[i] == 0)
                a[i + 1]++;
        }
     
        for (auto itr : a)
            cout << itr << " ";
        cout << "\n";
    }

    return 0;
}
