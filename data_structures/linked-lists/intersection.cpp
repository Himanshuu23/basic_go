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

node* solve(node* head1, node* head2) {
    node* a = head1;
    node* b = head2;
    
    while (a != b) {
        a = a ? a->next : head2;
        b = b ? b->next : head1;
    }

    return a;
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
        node* head1 = new node(1);
        head1->next = new node(2);
        head1->next->next = new node(3);
        node* head2 = new node(6);
        head2->next = head1->next->next;
        display(head1);
        display(head2);
        node* ans = solve(head1, head2);
        if (ans) cout << ans->data << endl;
        else cout << "No Intersection Found" << endl;
    }

    return 0;
}
