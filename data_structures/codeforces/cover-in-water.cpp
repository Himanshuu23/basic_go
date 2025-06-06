#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cin.ignore();

        string s;
        getline(cin, s);
        
        int ans = 0, count = 0;
        bool flag = false;
        
        for (int i = 0; i < n; i++) {
            if ((i > 0 && i < n - 1) && (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.')) {
                flag = true;
                break;
            }

            if (s[i] == '.') {
                count++;
            }
        }

        if (flag) {
            cout << 2 << endl;
        } else {
            cout << count << endl;
        }
    }

    return 0;
}
