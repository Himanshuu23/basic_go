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

    node (int value) {
        data = value;
        next = NULL;
    }
};

void solve(node* &head, int x) {
    node* lessHead = new node(-1);
    node* moreHead = new node(-1);
    node* less = lessHead;
    node* more = moreHead;
    node* curr = head;

    while (curr) {
        if (curr->data < x) {
            less->next = new node(curr->data);
            less = less->next;
        } else {
            more->next = new node(curr->data);
            more = more->next;
        }
        curr = curr->next;
    }

    less->next = moreHead->next; 
    head = lessHead->next;        
}

void display(node* &head) {
    node* temp = head;
    
    while (temp) {
        cout << temp -> data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int x; cin >> x;
        node* head = new node(1);
        head->next = new node(4);
        head->next->next = new node(3);
        head->next->next->next = new node(2);
        display(head);
        solve(head, x);
        display(head);
    }

    return 0;
}
