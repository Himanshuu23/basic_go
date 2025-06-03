#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "[";
            for (int k = i; k <= j; k++) {
                cout << v[k] << " ";
            }
            cout << "]";
            cout << endl;
        }
    }
    
    return 0;
}
