/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long N = 10;

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<string> target;

        for (int i = 0; i < N; i++) {
            string temp; getline(cin, temp);
            target.push_back(temp);
        }

        long total = 0;
        for (long row = 0; row < N; row++) {
            for (long col = 0; col < N; col++) {
                if (target[row][col] == '.') continue;
            
                long xrow = min(row, N - row - 1);
                long xcol = min(col, N - col - 1);
                long score = min(xrow, xcol) + 1;

                total += score;
            }
        }

        cout << total << endl;

    }

    return 0;
}
