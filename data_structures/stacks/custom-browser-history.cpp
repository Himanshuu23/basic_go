/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class BrowserHistory {
private:
    stack<string> backStack, forwardStack;
    string current;

public:
    BrowserHistory(string homepage) {
        current = homepage;
    }

    void visit(string url) {
        backStack.push(current);
        current = url;
        while (!forwardStack.empty()) forwardStack.pop();
    }

    string back(int steps) {
        while (steps-- > 0 && !backStack.empty()) {
            forwardStack.push(current);
            current = backStack.top();
            backStack.pop();
        }
        return current;
    }

    string forward(int steps) {
        while (steps-- > 0 && !forwardStack.empty()) {
            backStack.push(current);
            current = forwardStack.top();
            forwardStack.pop();
        }
        return current;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        BrowserHistory browser("leetcode.com");
        browser.visit("google.com");
        browser.visit("facebook.com");
        browser.visit("youtube.com");
        cout << browser.back(1) << endl;
        cout << browser.back(1) << endl;
        cout << browser.forward(1) << endl;
        browser.visit("linkedin.com");
        cout << browser.forward(2) << endl;
        cout << browser.back(2) << endl;
        cout << browser.back(7) << endl;
    }

    return 0;
}
