/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define BASE 256
#define MOD 101
// Using KMP and Rabin Karp

/*
BASE = 256 means we treat characters as base-256 digits.
MOD = prime number 101 helps to reduce collisions (two strings might have same hashes) and keep hashes in manageable range.
highBase = BASE^(m-1) % MOD
Why m-1 times? - We want to remove the effect of the first character from the hash while sliding the window.
*/

vector<int> solve2(const string& text, const string& pattern) {
    int n(text.length()), m(pattern.length());
    vector<int>result;
    if (m > n) return result;
    
    int patternHash(0), windowHash(0), highBase(1);

    for (int i = 0; i < m - 1; i++) highBase = (highBase * BASE) % MOD;

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash) {
            if (text.substr(i, m) == pattern) result.push_back(i);
        }

        if (i < n - m) {
            windowHash = (windowHash - text[i] * highBase) * BASE + text[i + m]; // moving the window by subtracting text[i] * highBase -> first element of the window removed
            windowHash = (windowHash % MOD + MOD) % MOD;
        }
    }
    return result;
}

vector<int> buildLPS (const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j(0), i(1);
    
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) j = lps[j-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int solve(string s, string k) {
    int n = s.size(), m = k.size();\
    if (m == 0) return 0;
    vector<int>lps = buildLPS(k);
    int i(0), j(0);
    while (i < n) {
        if (s[i] == k[j]) {
            i++; j++;
        }
        if (j == m) {
            return i-j;    
        } else if (i < n && s[i] != k[j]) {
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, k; cin >> s >> k;
        cout << solve(s, k) << endl;
    }

    return 0;
}
