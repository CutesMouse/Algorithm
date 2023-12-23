#include <iostream>
#include <vector>
#include <algorithm>
#define illegal(i,j) (b[i].x == b[j].x || b[i].x == b[j].y || b[i].y == b[j].x || b[i].y == b[j].y)
using namespace std;

typedef unsigned long long int ll;

struct Pair {
    ll sum;
    int x, y;
};

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<Pair> b;
    for (int i = 0; i < n; i++) {
        for (int j = (i+1); j < n; j++) {
            b.push_back({a[i]+a[j], i+1, j+1});
        }
    }
    sort(b.begin(), b.end(), [](Pair &a, Pair &b) { return a.sum < b.sum;});
    int j = (b.size()-1);
    for (int i = 0; i < b.size() && i < j; i++) {
        while (b[i].sum + b[j].sum > x && j > 0) j--;
        if (b[i].sum + b[j].sum == x && !illegal(i, j)) {
            cout << b[i].x << " " << b[i].y << " " << b[j].x << " " << b[j].y;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
