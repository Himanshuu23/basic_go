#include <bits/stdc++.h>
using namespace std;


int main() {
    int rows, cols; cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    if (rows != cols) {
        cout << "matrix need to be a square matrix!" << endl;
        return 0;
    } 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = 0; cin >> temp;
            matrix[i][j] = temp;
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
