/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    char ch;
    int freq;
    Node* left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string code, unordered_map<char, string>& huffCode) {
    if (!root) return;
    if (!root->left && !root->right) huffCode[root->ch] = code;

    buildCodes(root->left, code + "0", huffCode);
    buildCodes(root->right, code + "1", huffCode);
}

void huffmanEncoding(vector<char>& chars, vector<int>& freqs) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (int i = 0; i < chars.size(); i++) {
        minHeap.push(new Node(chars[i], freqs[i]));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* merged = new Node('#', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }

    unordered_map<char, string> huffCode;
    buildCodes(minHeap.top(), "", huffCode);

    for (auto& pair : huffCode) cout << pair.first << ": " << pair.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<char> chars(n);
        vector<int> freqs(n);

        for (int i = 0; i < n; i++) cin >> chars[i];
        for (int i = 0; i < n; i++) cin >> freqs[i];

        huffmanEncoding(chars, freqs);
        cout << '\n';
    }

    return 0;
}
