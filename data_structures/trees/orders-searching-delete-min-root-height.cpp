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

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

bool search(Node* root, int val) {
    if (root == nullptr) return false;
    if (root->data == val) return true;

    return val < root->data ? search(root->left, val) : search(root->right, val);
}

int height(Node* root) {
    if (root == nullptr) return -1;
    return 1 + max(height(root->left), height(root->right));
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return nullptr;

    if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else {
        // found the node to be deleted
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with 2 children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        Node* root = nullptr;
        int n; cin >> n;

        while (n--) {
            int val; cin >> val;
            root = insert(root, val);
        }

        cout << "Preorder: ";
        preorder(root); cout << "\n";

        cout << "Postorder: ";
        postorder(root); cout << "\n";

        cout << "Height: " << height(root) << "\n";

        int x; cin >> x;
        cout << "Search " << x << ": " << (search(root, x) ? "Found" : "Not Found") << "\n";

        int del; cin >> del;
        root = deleteNode(root, del);
        cout << "Inorder after deletion: ";
        preorder(root); cout << "\n";
    }

    return 0;
}
