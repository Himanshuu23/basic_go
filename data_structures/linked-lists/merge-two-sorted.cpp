/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

node* solve(node* head1, node* head2) {
    node dummy(-1);
    node* tail = &dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = head1 ? head1 : head2;

    return dummy.next;
}

void display(node* head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while (t--) {
        node* head1 = new node(0);
        head1->next = new node(1);
        head1->next->next = new node(2);

        node* head2 = new node(1);
        head2->next = new node(3);
        head2->next->next = new node(4);

        display(head1);
        display(head2);

        node* combined = solve(head1, head2);
        display(combined);
    }

    return 0;
}
