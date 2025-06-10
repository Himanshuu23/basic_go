/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        long n; cin >> n;
        long pos(0), neg(0);
        for(long p = 0; p < n; p++){
            int x; cin >> x;
            pos += (x > 0);
            neg += (x < 0);
        }

        long move(0);
        if(pos < neg){
            move = (neg - pos + 1) / 2; 
            pos += move; neg -= move;
        }
        if(neg % 2){++move;}

        cout << move << endl;

    }

    return 0;
}
