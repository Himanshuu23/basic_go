/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    long t; cin >> t;
    while(t--){
        long n, k, x; cin >> n >> k >> x;
        if(x != 1){
            cout << "YES\n" << n << "\n";
            for(long p = 0; p < n; p++){cout << "1 ";}
            cout << "\n";
        }
        else if(k >= 2 && n % 2 == 0){
            cout << "YES\n" << n / 2 << "\n";
            for(long p = 0; p < n / 2; p++){cout << "2 ";}
            cout << "\n";
        }
        else if(k >= 3){
            cout << "YES\n" << (n / 2) << "\n3 ";
            for(long p = 1; p < n / 2; p++){cout << "2 ";}
            cout << "\n";
        }
        else{cout << "NO\n"; continue;}
    }
}
