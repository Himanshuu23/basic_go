/*
    author: Himanshuu23
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(string word, string beginWord, unordered_map<string, vector<string>>& parentMap,
         vector<string>& path, vector<vector<string>>& result) {
    if (word == beginWord) {
        path.push_back(word);
        reverse(path.begin(), path.end());
        result.push_back(path);
        reverse(path.begin(), path.end());
        path.pop_back();
        return;
    }

    path.push_back(word);
    for (string& parent : parentMap[word]) {
        dfs(parent, beginWord, parentMap, path, result);
    }
    path.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> result;

    if (!wordSet.count(endWord)) return result;

    unordered_map<string, vector<string>> parentMap;
    unordered_set<string> visited;
    unordered_set<string> currentLevelVisited;

    queue<string> q;
    q.push(beginWord);
    visited.insert(beginWord);
    bool found = false;

    while (!q.empty() && !found) {
        int size = q.size();
        currentLevelVisited.clear();

        for (int i = 0; i < size; i++) {
            string word = q.front(); q.pop();

            string original = word;
            for (int j = 0; j < word.size(); j++) {
                char old = word[j];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[j] = ch;
                    if (!wordSet.count(word) || visited.count(word)) continue;

                    parentMap[word].push_back(original);

                    if (word == endWord) found = true;

                    if (!currentLevelVisited.count(word)) {
                        q.push(word);
                        currentLevelVisited.insert(word);
                    }
                }
                word[j] = old;
            }
        }

        for (auto& w : currentLevelVisited) visited.insert(w);
    }

    if (!found) return result;

    vector<string> path;
    dfs(endWord, beginWord, parentMap, path, result);
    return result;
}

int main() {
    int t; cin >> t;
    while(t--) {
        string beginWord = "hit", endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

        vector<vector<string>> sequences = findLadders(beginWord, endWord, wordList);

        cout << "All shortest transformation sequences:\n";
        for (auto& seq : sequences) {
            for (auto& word : seq) cout << word << " ";
            cout << endl;
        }
    }

    return 0;
}
