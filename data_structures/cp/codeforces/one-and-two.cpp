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
        int n; cin>>n;
        int a[n];
        long sum = 0;
        for(int i=0; i<n; i++) {
            cin>>a[i];
            sum += a[i] == 2;
        }

        long total = 0;
        for (int i = 0; i < n; i++) {
            total += a[i] == 2;
            if(total == sum - total) {
                cout << i+1 << endl;
                break;
            }
            else if (i == n - 1) {
                cout << -1 << endl;
                break;    
            }
        }
    }

    return 0;
}
