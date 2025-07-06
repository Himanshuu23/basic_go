/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class node {
    public:
    int data;
    node* next;

    node (int val) {
        data = val;
        next = NULL;
    }
};

node* solve(node* &head) {
    if (head->next == NULL) return head;
    node* temp = head;

    while(temp && temp->next) {
        if (temp->data == temp->next->data) {
            node* dup = temp->next;
            temp->next = dup->next;
            delete dup;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

void display(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        node* head = new node(1);
        head->next = new node(2);
        head->next->next = new node(2);
        head->next->next->next = new node(3);
        display(head);
        solve(head);
        display(head);
    }

    return 0;
}
