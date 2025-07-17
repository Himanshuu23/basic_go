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
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void convertToLL(Node* root, Node*& prev) {
    if (!root) return;

    convertToLL(root->right, prev);
    convertToLL(root->left, prev);

    root->right = prev;
    root->left = nullptr;
    prev = root;
}

Node* flatten(Node* root) {
    Node* prev = nullptr;
    convertToLL(root, prev);
    return root;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(5);
        root->left->left = new Node(3);
        root->left->right = new Node(4);
        root->right->right = new Node(6);

        Node* head = flatten(root);
        print(head);
    }

    return 0;
}
