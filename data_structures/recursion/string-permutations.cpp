/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printPermutations(string prefix, string remaining) {
    if (remaining.empty()) {
        cout << prefix << endl;
        return;
    }

    for (int i = 0; i < remaining.size(); ++i) {
        char ch = remaining[i];
        string rest = remaining.substr(0, i) + remaining.substr(i+1);
        printPermutations(prefix+ch, rest);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        printPermutations("", s);
    }

    return 0;
}
