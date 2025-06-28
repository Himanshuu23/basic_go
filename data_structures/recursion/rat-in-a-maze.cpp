/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int i, int j, vector<vector<int>> &maze, vector<vector<bool>> &visited, int rows, int cols, vector<pair<int, int>> &path) {
    if (i < 0 || j < 0 || i >= rows || j >= cols || maze[i][j] == 0 || visited[i][j])
        return;

    if (i == rows - 1 && j == cols - 1) {
        path.push_back({i, j});
        for (auto [x, y] : path) cout << "(" << x << "," << y << ") ";
        cout << "\n";
        path.pop_back();
        return;
    }

    visited[i][j] = true;
    path.push_back({i, j});

    dfs(i + 1, j, maze, visited, rows, cols, path);
    dfs(i, j + 1, maze, visited, rows, cols, path);
    dfs(i - 1, j, maze, visited, rows, cols, path);
    dfs(i, j - 1, maze, visited, rows, cols, path);

    visited[i][j] = false;
    path.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> maze(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> maze[i][j];

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> path;
        dfs(0, 0, maze, visited, rows, cols, path);
    }

    return 0;
}
