/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v(999999 + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int num;
        cin >> num;
        int cnt = 0;
        int i;
        for (i = 1; i <= 999999 ; i++) {
            int n = i;
            int sum = 0;
        
            while(n) {
                if((n % 10) != 0)
                    sum++;
                n /= 10;
            }

            if (sum == 1)
                v[i] = v[i - 1] + 1;
            else
                v[i] = v[i - 1];
        }
        cout << v[num] << '\n';
    }

    return 0;
}
