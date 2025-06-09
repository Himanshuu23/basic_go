/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    
    while(t--){
        long n; cin >> n;
        bool sorted(true); long minnum(1e9 + 7);
        long prev; cin >> prev;

        for(long p = 1; p < n; p++){
            long x; cin >> x;
            if(prev <= x){
                long num = 1 + (x - prev) / 2 ;
                minnum = (num < minnum) ? num : minnum;
            }
            else{sorted = false;}
            prev = x;
        }

        sorted ? cout << minnum << endl : cout << 0 << endl;
    }

    return 0;
}
