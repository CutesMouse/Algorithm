#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> eg;
    vector<int> lis;
    int N, a, b;
    cin >> N;
    while (N--) {
        cin >> a >> b;
        eg.emplace_back(a, -b);
    }
    sort(eg.begin(), eg.end());
    for (int i = 0; i < eg.size(); i++) {
        auto iter = lower_bound(lis.begin(), lis.end(), eg[i].second);
        if (iter == lis.end()) lis.emplace_back(eg[i].second);
        else *iter = eg[i].second;
    }
    cout << lis.size();
}
