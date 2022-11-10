#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n,a,b;
    pair<int,int> ds[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ds[i] = {a,b};
    }
    sort(ds,ds+n);
    for (int i = 0; i < n; i++) {
        cout << ds[i].first << " " << ds[i].second << "\n";
    }
}
