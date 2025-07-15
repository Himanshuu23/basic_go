/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        data = val;
        left = right = nullptr;
    }
};

void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while (t--) {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);

        mirror(root);
        inorder(root);
        cout << "\n";
    }

    return 0;
}
