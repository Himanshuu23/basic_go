/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalindrome(string s) {
    int left(0), right(s.size() - 1);
    bool flag = true;
    
    while (left != right) {
        if (s[left] == s[right]) {
            left++; right--;
        } else {
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        puts(isPalindrome(s) ? "Yes" : "No");
    }

    return 0;
}
