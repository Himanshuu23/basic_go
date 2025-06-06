#include <bits/stdc++.h>
using namespace std;

int updateBit(int n, int pos, int value) {
    n = n & (~(1 << pos));
    
    return n | (value << pos);
}

int main() {
    cout << updateBit(5, 1, 1) << endl;
    return 0;
}
