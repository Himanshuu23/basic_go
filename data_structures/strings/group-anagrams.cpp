/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<string>> solve(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& [key, group] : mp) {
        result.push_back(group);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++) cin >> words[i];
        vector<vector<string>> res = solve(words);
        for (int i = 0; i < res.size(); i++) { 
            for (auto& word : res[i]) {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
