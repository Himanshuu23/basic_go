/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, vector<string>>letters = {
    {0, {" "}},
    {1, {"%"}},
    {2, {"a", "b", "c"}},
    {3, {"d", "e", "f"}},
    {4, {"g", "h", "i"}},
    {5, {"j", "k", "l"}},
    {6, {"m", "n", "o"}},
    {7, {"p", "q", "r", "s"}},
    {8, {"t", "u", "v"}},
    {9, {"x", "y", "z"}},
};

void fromPhone(int n, int m, int i) {
    if (i == letters.at(m).size()) return;
    for (auto ch : letters[n]) cout << ch + letters.at(m)[i] << endl;
    return fromPhone(n, m, i + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        fromPhone(n, m, 0);
    }

    return 0;
}
