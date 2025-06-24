/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int lower = count_if(s.begin(), s.end(), ::islower);
    int upper = s.size() - lower;
    transform(s.begin(), s.end(), s.begin(), (lower >= upper) ? ::tolower : ::toupper);
    cout << s << endl;
    return 0;
}
