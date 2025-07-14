/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Code {
public:
    
    string encode(vector<string>& v) {
        string encoded("");
        for (const string& s : v) encoded += to_string(s.length()) + "#" + s;
        return encoded;
    }

    vector<string> decode(const string& s) {
        vector<string> res;
        int i(0);
        while (i < s.size()) {
            int j(i);
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j+1, len));
            i = j + 1 + len;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> w(n);
        for (int i = 0; i < n; i++) cin >> w[i];
        Code c;

        string encoded = c.encode(w);
        cout << "Encoded: " << encoded << endl;

        vector<string> dec = c.decode(encoded);
        cout << "Decoded: ";
        for (const string& s : dec) cout << s << " ";
        cout << endl;
    }

    return 0;
}
