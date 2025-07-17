/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    int n = grid.size(), m = grid[0].size();
    visited[i][j] = true;

    vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    for (auto [dx, dy] : dirs) {
        int ni = i + dx, nj = j + dy;
        if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '1' && !visited[ni][nj]) {
            dfs(ni, nj, grid, visited);
        }
    }
}

int countIslandsDFS(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }

    return count;
}

int countIslandsBFS(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;

    vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (auto [dx, dy] : dirs) {
                        int ni = x + dx, nj = y + dy;
                        if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '1' && !visited[ni][nj]) {
                            visited[ni][nj] = true;
                            q.push({ni, nj});
                        }
                    }
                }

                count++;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        vector<vector<char>> grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        };

        int result_dfs = countIslandsDFS(grid);
        cout << "DFS: Number of islands: " << result_dfs << endl;

        int result_bfs = countIslandsBFS(grid);
        cout << "BFS: Number of islands: " << result_bfs << endl;
    }

    return 0;
}
