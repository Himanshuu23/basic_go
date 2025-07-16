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

Node* solve(Node* root, Node* p) {
    Node* successor = nullptr;
    while (root) {
        if (p->data < root->data) {
            successor = root;
            root = root->left;
        } else root = root->right;
    }

    return successor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(20);
        root->left = new Node(10);
        root->right = new Node(30);
        root->left->left = new Node(5);
        root->left->right = new Node(15);
        root->left->right->right = new Node(17);

        cout << solve(root, root->left->right)->data << endl;
    }

    return 0;
}
