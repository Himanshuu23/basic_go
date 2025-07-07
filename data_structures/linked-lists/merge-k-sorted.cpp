/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;

class node {
public:
    int data;
    node* next;

    node(int value) {
        data = value;
        next = NULL;
    }
};

struct compare {
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

node* solve(vector<node*> lists) {
    priority_queue<node*, vector<node*>, compare> minHeap;

    for (auto list : lists) {
        if (list) minHeap.push(list);
    }

    node* dummy = new node(0);
    node* tail = dummy;

    while (!minHeap.empty()) {
        node* smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next) minHeap.push(smallest->next);
    }

    return dummy->next;
}

void display(node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<node*> lists;
    int val = 0;
    long t;
    cin >> t;

    while (t--) {
        node* head = new node(val++);
        node* head1 = new node(val++);
        node* curr = head;
        node* curr2 = head1;

        for (int i = 0; i < 2; ++i) {
            curr->next = new node(val++);
            curr2->next = new node(val++);
            curr = curr->next;
            curr2 = curr2->next;
        }

        lists.push_back(head);
        lists.push_back(head1);
    }

    node* sol = solve(lists);
    display(sol);
    return 0;
}
