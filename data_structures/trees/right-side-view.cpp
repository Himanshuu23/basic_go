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

    Node (int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> solve(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        Node* node = nullptr;

        for (int i = 0; i < levelSize; i++) {
            node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(node->data);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->right = new Node(5);
        root->right->right = new Node(4);

        vector<int> ans = solve(root);
        for (auto num : ans) cout << num << " ";
        cout << endl;
    }

    return 0;
}
