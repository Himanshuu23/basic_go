/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* fail = nullptr;
    vector<string> output;
};

class AhoCorasick {
private:
    TrieNode* root;

public:
    AhoCorasick(const vector<string>& patterns) {
        root = new TrieNode();
        buildTrie(patterns);
        buildFailureLinks();
    }

    void buildTrie(const vector<string>& patterns) {
        for (const string& pattern : patterns) {
            TrieNode* node = root;
            for (char ch : pattern) {
                if (!node->children[ch])
                    node->children[ch] = new TrieNode();
                node = node->children[ch];
            }
            node->output.push_back(pattern);
        }
    }

    void buildFailureLinks() {
        queue<TrieNode*> q;
        root->fail = root;

        for (auto& pair : root->children) {
            pair.second->fail = root;
            q.push(pair.second);
        }

        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

            for (auto& pair : current->children) {
                char ch = pair.first;
                TrieNode* child = pair.second;

                TrieNode* fallback = current->fail;
                while (fallback != root && !fallback->children.count(ch)) {
                    fallback = fallback->fail;
                }

                if (fallback->children.count(ch))
                    child->fail = fallback->children[ch];
                else
                    child->fail = root;

                for (const string& out : child->fail->output)
                    child->output.push_back(out);

                q.push(child);
            }
        }
    }

    void search(const string& text) {
        TrieNode* node = root;
        for (int i = 0; i < text.size(); i++) {
            char ch = text[i];

            while (node != root && !node->children.count(ch))
                node = node->fail;

            if (node->children.count(ch))
                node = node->children[ch];

            for (const string& pattern : node->output)
                cout << "Pattern '" << pattern << "' found at index: " << (i - pattern.size() + 1) << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t;
    cin >> t;
    while (t--) {
        string text = "abccababcabca";
        vector<string> patterns = {"abc", "ab", "bca", "cab"};
        AhoCorasick ac(patterns);
        ac.search(text);
    }

    return 0;
}
