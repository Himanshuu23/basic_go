#include <bits/stdc++.h>
using namespace std;

int ToDecimal(int n, int k) { // k = 2 for binary, 8 for octal
    int ans = 0, x = 1, y;

    while (n > 0) {
        y = n % 10;
        ans += x * y;
        x *= k;
        n /= 10;
    }

    return ans;
}

int hexaDecimalToDecimal(string n) {
    int ans = 0, x = 1, s = n.size();

    for (int i = s - 1; i >= 0; i--) {
        if (n[i] >= '0' && n[i] <= '9') {
            ans += x * (n[i] - '0');
        } else if (n[i] >= 'A' && n[i] <= 'F') {
            ans += x * (n[i] - 'A' + 10);
        }

        x *= 16;
    }


    return ans;
}

int main() {

    int n; cin >> n;
    cin.ignore();
    
    string s;
    getline(cin, s);

    cout << ToDecimal(n, 2) << endl;
    cout << ToDecimal(n, 8) << endl;
    cout << hexaDecimalToDecimal(s) << endl;

    return 0;
}
