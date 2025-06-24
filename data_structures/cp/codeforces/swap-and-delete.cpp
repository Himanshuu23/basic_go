/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int z = count(s.begin(), s.end(), '0');
        int o = s.size() - z;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (o) o--;
                else break;
            } else {
                if (z) z--;
                else break;
            }
        }
        cout << o + z << endl;
    }

    return 0;
}
