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

    Node (int val) : data(val), left(nullptr), right(nullptr) {}
};

unordered_map<int, int> mp;
int preOrderIndex(0);

Node* build(const vector<int>& preorder, int left, int right) {
    if (left > right) return nullptr;
    int rootVal = preorder[preOrderIndex++];
    Node* root = new Node(rootVal);
    int index = mp[rootVal];

    root->left = build(preorder, left, index - 1);
    root->right = build(preorder, index + 1, right);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    return build(preorder, 0, inorder.size() - 1);
}

void print_inorder(Node* root) {
    if (!root) return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        Node* root = buildTree(preorder, inorder);
        print_inorder(root);
        cout << endl;
    }

    return 0;
}
