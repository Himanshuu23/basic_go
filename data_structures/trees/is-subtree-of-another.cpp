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

bool isSameTree(Node* s, Node* t) {
    if (!s && !t) return true;
    if (!s || !t || s->data != t->data) return false;
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if (!root) return false;
    if (!isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    Node* subRoot = new Node(4);
    subRoot->left = new Node(1);
    subRoot->right = new Node(2);

    cout << (isSubtree(root, subRoot) ? "YES" : "NO") << '\n';

    return 0;
}
