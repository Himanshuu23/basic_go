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

void solve(node* &head, int k) {
    node* fast = head;
    node* slow = head;
    
    for (int i = 0; i < k; i++) fast = fast->next;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = NULL;
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
        int k; cin >> k;
        node* head = new node(1);
        head->next = new node(2);
        head->next->next = new node(3);
        head->next->next->next = new node(4);
        head->next->next->next->next = new node(5);
        display(head);
        solve(head, k);
        display(head);
    }

    return 0;
}
