/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string bin1, string bin2) {
    int i = bin1.size() - 1, j = bin2.size() - 1, carry = 0;
    string ans;

    while (i >= 0 || j >= 0 || carry) {
        int bit1 = (i >= 0 ? bin1[i--] - '0' : 0);
        int bit2 = (j >= 0 ? bin2[j--] - '0' : 0);
        int sum = bit1 + bit2 + carry;
        ans += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string bin1, bin2; cin >> bin1 >> bin2;
        cout << solve(bin1, bin2) << endl;
    }

    return 0;
}
