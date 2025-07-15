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

Node* convert(const vector<int>& v, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    Node* root = new Node(v[mid]);

    root->left = convert(v, start, mid - 1);
    root->right = convert(v, mid + 1, end);

    return root;
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
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        Node* root = convert(v, 0, n - 1);
        inorder(root);
        cout << endl;
    }

    return 0;
}
