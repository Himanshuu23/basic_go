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

bool isMirror(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return ((root1->data == root2->data) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
}

bool isSymmetric(Node* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while (t--) {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(2);
        root->left->left = new Node(3);
        root->left->right = new Node(4);
        root->right->left = new Node(4);
        root->right->right = new Node(3);

        cout << (isSymmetric(root) ? "Yes" : "No") << "\n";
    }

    return 0;
}
