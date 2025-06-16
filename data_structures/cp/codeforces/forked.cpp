/*
    author: Himanshuu23
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
 
	long t; cin >> t;
	while(t--){
        long a, b; cin >> a >> b;
        long xk, yk; cin >> xk >> yk;
        long xq, yq; cin >> xq >> yq;

        set<std::pair<long, long> > s,t;
        s.insert(make_pair(xk + a, yk + b));
        s.insert(make_pair(xk - a, yk + b));
        s.insert(make_pair(xk + a, yk - b));
        s.insert(make_pair(xk - a, yk - b));
        s.insert(make_pair(xk + b, yk + a));
        s.insert(make_pair(xk - b, yk + a));
        s.insert(make_pair(xk + b, yk - a));
        s.insert(make_pair(xk - b, yk - a));

        t.insert(make_pair(xq + a, yq + b));
        t.insert(make_pair(xq - a, yq + b));
        t.insert(make_pair(xq + a, yq - b));
        t.insert(make_pair(xq - a, yq - b));
        t.insert(make_pair(xq + b, yq + a));
        t.insert(make_pair(xq - b, yq + a));
        t.insert(make_pair(xq + b, yq - a));
        t.insert(make_pair(xq - b, yq - a));


        long cnt(0);
        for(set<pair<long, long> >::iterator it = s.begin(); it != s.end(); it++){cnt += t.count(*it);}
        cout << cnt << endl;
	}
 
}
