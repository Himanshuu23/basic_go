#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, cols; cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = 0; cin >> temp;
            matrix[i][j] = temp;
        }
        cout << "enter next row now" << endl;
    }

    int row_start = 0, row_end = rows - 1, col_start = 0, col_end = cols - 1;
    
    while ((row_start <= row_end) && (col_start <= col_end)) {
        for (int col = col_start; col <= col_end; col++) {
            cout << matrix[row_start][col] << " ";
        }
        row_start++;
        cout << endl;

        for (int row = row_start; row <= row_end; row++) {
            cout << matrix[row][col_end] << " ";
        }
        col_end--;
        cout << endl;

        for (int col = col_end; col >= col_start; col--) {
            cout << matrix[row_end][col] << " ";
        }
        row_end--;
        cout << endl;

        for (int row = row_end; row >= row_start; row--) {
            cout << matrix[row][col_start] << " ";
        }
        col_start++;
        cout << endl;
    }

    return 0;
}
