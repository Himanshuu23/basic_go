/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node (int val) : data(val), left(nullptr), right(nullptr) {}
};

void solve(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int currLevel = q.size();
        vector<Node*> level;
        for (int i = 0; i < currLevel; i++) {
            Node* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            level.push_back(node->left);
            level.push_back(node->right);
        }

        for (int i = 0; i < level.size() - 1; i++) level[i]->next = level[i+1];
        level[level.size() - 1]->next = nullptr;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {

    }

    return 0;
}
