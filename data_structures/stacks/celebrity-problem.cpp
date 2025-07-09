/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool knows(const vector<vector<int>>& M, int A, int B) {
    return M[A][B] == 1;
}

int solve (const vector<vector<int>>& M, int n) {
    stack<int> st;

    for (int i = 0; i < n; i++) st.push(i);

    while (st.size() > 1) {
        int A = st.top(); st.pop();
        int B = st.top(); st.pop();

        if (knows(M, A, B)) st.push(B);
        else st.push(A);
    }

    int candidate = st.top();

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(M, candidate, i) || !knows(M, i, candidate)) return -1; 
        }
    }

    return candidate;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>>M(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> M[i][j];

        cout << solve(M, n) << endl;
    }

    return 0;
}
