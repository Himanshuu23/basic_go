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

    Node (int val) {
        data = val;
        left = right = nullptr;
    }
};

queue<int> q;

vector<int> solve(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front(); q.pop();
            maxVal = max(maxVal, node->data);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(maxVal);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(1);
        root->left = new Node(3);
        root->right = new Node(2);
        root->left->left = new Node(5);
        root->left->right = new Node(3);
        root->right->right = new Node(9);

        vector<int> ans = solve(root);
        for (auto num : ans) cout << num << " ";
        cout << endl;
    }

    return 0;
}
