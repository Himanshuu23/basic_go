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

bool isBST(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if (isBST(root, INT_MIN, INT_MAX)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
