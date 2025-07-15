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

int ans(0);
int height(Node* root) {
    if (!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    ans = max(ans, right + left);
    return 1 + max(left, right);
}

int diameter(Node* root) {
    ans = 0;
    height(root);
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
        root->left->left = new Node(4);
        root->left->right = new Node(5);

        cout << diameter(root) << "\n";
    }

    return 0;
}
