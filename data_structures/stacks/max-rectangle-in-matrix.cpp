/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int area(vector<int>& heights, int n) {
    stack<int> st;
    int area(0);
    
    for (int i = 0; i <= n; i++) {
        int curr = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] >= curr) {
            int h = heights[st.top()]; st.pop();
            int w = (st.empty()) ? i : i - st.top() - 1;
            area = max(area, h * w);
        }
        st.push(i);
    }

    return area;
}

int solve(vector<vector<char>>& matrix, int n, int m) {
    vector<int>heights(m, 0);
    int ans(0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        ans = max(ans, area(heights, m));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<char>>v(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        
        cout << solve(v, n, m) << endl;
    }

    return 0;
}
