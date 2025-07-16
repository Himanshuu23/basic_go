/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
#include <string>
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

    string serialize(Node* root) {
        if (!root) return "null";

        string result;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            if (curr) {
                result += to_string(curr->data) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else result += "null,";
        }

        if (!result.empty()) result.pop_back();
        return result;
    }

    Node* deserialize(string data) {
        if (data == "null") return nullptr;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        Node* root = new Node(stoi(item));
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();

            // left child 
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    Node* left = new Node(stoi(item));
                    curr->left = left;
                    q.push(left);
                }
            }

            // right child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    Node* right = new Node(stoi(item));
                    curr->right = right;
                    q.push(right);
                }
            }
        }

        return root;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = root->deserialize("1,2,3,null,null,4,5");
        string data = root->serialize(root);
        cout << data << endl;
    }

    return 0;
}
