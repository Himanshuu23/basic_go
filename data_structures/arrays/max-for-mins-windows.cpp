/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(const vector<int>& v, int n) {
    vector<int> res(n+2, 0);
    
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> st;

    // filling all elements of left
    for (int i = 0; i < n; i++) {
        while(!st.empty() && v[st.top()] >= v[i]) st.pop();
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop(); // clearing the stack

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && v[st.top()] >= v[i]) st.pop();
        if (!st.empty()) right[i] = st.top();
        st.push(i);
    }

    // creating the res array using max of mins for each window
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        res[len] = max(res[len], v[i]);
    }

    // fill unfilled entries
    for (int i = n - 1; i >= 1; i--) 
        res[i] = max(res[i], res[i+1]);
    
    // ⚠️ FIX: ensure exactly n elements are returned
    vector<int> ans(res.begin() + 1, res.begin() + n + 1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) 
            cin >> v[i];
        vector<int> ans = solve(v, n);
        for (auto num : ans) 
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}
