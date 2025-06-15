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
        long n;
        cin >> n;
 
        long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
 
        swap(arr[0], arr[1]);
        swap(arr[n - 1], arr[0]);
 
        if (arr[0] == arr[1])
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
