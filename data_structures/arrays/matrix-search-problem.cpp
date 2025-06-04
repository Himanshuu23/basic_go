#include <bits/stdc++.h>
using namespace std;

// on going down the column or right the row the value of elements would be in ascending order

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

    cout << "Enter the element you want to search for: ";
    
    int target; cin >> target;
    int r = 0, c = cols - 1;
    bool flag = false;
    
    while ( r < rows && c >= 0 && !flag) {
        if (matrix[r][c] ==  target) {
            flag = true;
        } else if (matrix[r][c] > target) {
            c--;
        } else {
            r++;
        }
    }

    if (flag) {
        cout << "Element found!" << endl;
    } else {
        cout << "Couldn't find the element you're looking for" << endl;
    }

    return 0;
}
