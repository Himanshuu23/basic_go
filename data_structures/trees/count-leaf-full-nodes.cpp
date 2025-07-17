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

int leaf(0), full(0);

void solve(Node* root) {
    if (!root) return;

    if (!root->left && !root->right) leaf++;
    if (root->left && root->right) full++;
    solve(root->left);
    solve(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);

        solve(root);
        cout << leaf << " " << full << endl;
    }

    return 0;
}
