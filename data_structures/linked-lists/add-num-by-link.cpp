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
    node* dummy = new node(0);
    node* temp = dummy;
    int carry(0);

    while (head1 || head2 || carry) {
        int sum = carry;
        if (head1) sum += head1->data, head1 = head1->next;
        if (head2) sum += head2->data, head2 = head2->next;

        temp->next = new node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
    }

    return dummy->next;
}

void display(node* &head) {
    node* temp = head;
    while (temp) {
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
        node* head1 = new node(9);
        head1->next = new node(9);
        head1->next->next = new node(9);
        node* head2 = new node(1);
        node* sum = solve(head1, head2);
        display(sum);
    }

    return 0;
}
