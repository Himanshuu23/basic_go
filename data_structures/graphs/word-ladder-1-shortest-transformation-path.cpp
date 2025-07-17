
/*
    author: Himanshuu23
*/

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0; // End word must be in the list

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> visited;
    visited.insert(beginWord);

    while (!q.empty()) {
        auto [word, level] = q.front(); q.pop();

        for (int i = 0; i < word.length(); i++) {
            string temp = word;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (temp == endWord) return level + 1;
                if (wordSet.count(temp) && !visited.count(temp)) {
                    visited.insert(temp);
                    q.push({temp, level + 1});
                }
            }
        }
    }

    return 0; // No transformation found
}

int main() {
    int t; cin >> t;
    while(t--) {
        string beginWord = "hit", endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        int result = ladderLength(beginWord, endWord, wordList);
        cout << "Shortest transformation length: " << result << "\n";
    }
    return 0;
}

