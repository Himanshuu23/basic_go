/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int>& prices, int day) {
    stack<int>st;
    vector<int>span(n);
    for (int i = 0; i <= day; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        span[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }
    return span[day];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, day; cin >> n >> day;
        vector<int>days(n), prices(n);
        for (int i = 0; i < n; i++) cin >> days[i];
        for (int i = 0; i < n; i++) cin >> prices[i];
        cout << solve(n, prices, day) << endl;
    }

    return 0;
}
