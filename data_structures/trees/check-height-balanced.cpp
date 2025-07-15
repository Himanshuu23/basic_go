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

int height(Node* root) {
    if (!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    if (left == -1 || right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}

bool isBalanced(Node* root) {
    if (!root) return true;
    int ht = height(root);
    return (ht == -1) ? false : true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while (t--) {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);

        cout << (isBalanced(root) ? "Yes" : "No") << "\n";
    }

    return 0;
}
