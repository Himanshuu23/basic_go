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
        vector<int> v;

        int a = INT_MAX;
        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            v.push_back(temp);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                a = min(__gcd(v[i], v[j]), a);
            }
        }

        if (a > 2)
            cout << "No" << endl;
        else 
            cout << "Yes" << endl;

    }

    return 0;
}
