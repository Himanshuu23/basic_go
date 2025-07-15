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

bool isIdentical(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;

    return ((root1->data == root2->data) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while (t--) {
        Node* root1 = new Node(1);
        root1->left = new Node(2);
        root1->right = new Node(3);

        Node* root2 = new Node(1);
        root2->left = new Node(2);
        root2->right = new Node(3);

        cout << (isIdentical(root1, root2) ? "Yes" : "No") << "\n";
    }

    return 0;
}
