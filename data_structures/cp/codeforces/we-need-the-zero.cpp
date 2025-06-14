/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
 
    long t; cin >> t;
    while(t--){
        long n; cin >> n;
        long cs(0);
        for(long p = 0; p < n; p++){
            long y; cin >> y;
            cs = cs ^ y;
        }
 
        if(n % 2){cout << cs << endl;}
        else{
            if (cs) cout << -1 << endl;
            else cout << 0 << endl;
        }
    }
 
}
