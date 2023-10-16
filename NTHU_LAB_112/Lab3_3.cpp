#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct gp {
    vector<long long int> member;
    long long int mx;
    long long int s;
};

bool cmp(const gp &g1, const gp &g2) {
    if (g1.s != g2.s) return g1.s > g2.s;
    if (g1.mx != g2.mx) return g1.mx > g2.mx;
    return g1.member.size() > g2.member.size();
}

int main() {
    long long int t, g, n, k;
    cin >> t;
    while (t--) {
        vector<gp> groups;
        cin >> g;
        for (int i = 0 ; i < g; i++) {
            cin >> n;
            gp group;
            group.mx = -1;
            group.s = 0;
            for (int j = 0; j < n; j++) {
                cin >> k;
                group.s += k;
                group.mx = max(group.mx, k);
                group.member.emplace_back(k);
            }
            groups.push_back(group);
        }
        stable_sort(groups.begin(), groups.end(), cmp);
        for (int i = 0; i < groups.size(); i++) {
            for (int j = 0; j < groups[i].member.size(); j++) {
                cout << groups[i].member[j] << " ";
            }
            cout << endl;
        }
    }
}
