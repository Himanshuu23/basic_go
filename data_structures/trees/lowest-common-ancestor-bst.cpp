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

Node* solve(Node* root, Node* p, Node* q) {
    if (root->data > p->data && root->data > q->data) return solve(root->left, p, q);
    if (root->data < p->data && root->data < q->data) return solve(root->right, p, q);
    else return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(2);
        root->left = new Node(1);
        root->right = new Node(3);
        cout << solve(root, root->left, root->right)->data << endl;
    }

    return 0;
}
