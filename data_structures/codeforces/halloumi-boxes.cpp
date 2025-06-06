#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;

    while(t) {
        cin >> n >> k;
        vector<int> a;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            a.push_back(temp);
        }

        vector<int> b = a;
        sort(b.begin(), b.end());

        if (k == 1 && a != b)
            cout << "NO\n";
        else 
            cout << "YES\n";

        t--;
    }
    return 0;
}
