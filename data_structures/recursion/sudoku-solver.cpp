/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board(9, vector<char>(9));
unordered_set<char> row[9], col[9], box[9];

int getBox(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

bool isValid(int i, int j, char d) {
    return !row[i].count(d) && !col[j].count(d) && !box[getBox(i, j)].count(d);
}

bool solve() {
    int minOptions = 10, r = -1, c = -1;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                int options = 0;
                for (char d = '1'; d <= '9'; ++d)
                    if (isValid(i, j, d)) options++;

                if (options < minOptions) {
                    minOptions = options;
                    r = i;
                    c = j;
                }
            }
        }
    }

    if (r == -1) return true;

    for (char d = '1'; d <= '9'; ++d) {
        if (isValid(r, c, d)) {
            board[r][c] = d;
            row[r].insert(d);
            col[c].insert(d);
            box[getBox(r, c)].insert(d);

            if (solve()) return true;

            board[r][c] = '.';
            row[r].erase(d);
            col[c].erase(d);
            box[getBox(r, c)].erase(d);
        }
    }

    return false;
}

void initConstraints() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] != '.') {
                char d = board[i][j];
                row[i].insert(d);
                col[j].insert(d);
                box[getBox(i, j)].insert(d);
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> board[i][j];

        for (int i = 0; i < 9; i++) {
            row[i].clear();
            col[i].clear();
            box[i].clear();
        }

        initConstraints();

        if (solve()) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++)
                    cout << board[i][j] << " ";
                cout << '\n';
            }
        } else {
            cout << "No solution exists\n";
        }
    }

    return 0;
}
