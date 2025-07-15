/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    int x, y;
};

bool compareX(const Point &a, const Point &b) { 
    return a.x < b.x;
}

bool compareY(const Point &a, const Point &b) {
    return a.y < b.y;
}

double dist(const Point &a, const Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

// brute force approach -> for small inputs
double bruteForce(vector<Point> &points, int left, int right) {
    double minD = numeric_limits<double>::infinity();
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            minD = min(minD, dist(points[i], points[j]));
        }
    }
    return minD;
}

// Find closest distance in strip (sorted by y)
double stripClosest(vector<Point> &strip, double d) {
    double minD = d;
    int size = strip.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minD; ++j) {
            minD = min(minD, dist(strip[i], strip[j]));
        }
    }
    return minD;
}

// Recursive function
double closestUtil(vector<Point> &Px, vector<Point> &Py, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(Px, left, right);
    }

    int mid = (left + right) / 2;
    Point midPoint = Px[mid];

    // Divide Py into two halves
    vector<Point> Pyl, Pyr;
    for (const auto &p : Py) {
        if (p.x < midPoint.x || (p.x == midPoint.x && p.y <= midPoint.y))
            Pyl.push_back(p);
        else
            Pyr.push_back(p);
    }

    double dl = closestUtil(Px, Pyl, left, mid);
    double dr = closestUtil(Px, Pyr, mid, right);
    double d = min(dl, dr);

    // Build the strip
    vector<Point> strip;
    for (const auto &p : Py) {
        if (abs(p.x - midPoint.x) < d)
            strip.push_back(p);
    }

    return min(d, stripClosest(strip, d));
}

// Main function
double closestPair(vector<Point> &points) {
    int n = points.size();
    vector<Point> Px(points), Py(points);
    sort(Px.begin(), Px.end(), compareX);
    sort(Py.begin(), Py.end(), compareY);
    return closestUtil(Px, Py, 0, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }
        cout << fixed << setprecision(6) << closestPair(points) << '\n';
    }

    return 0;
}
