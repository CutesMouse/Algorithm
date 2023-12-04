#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    // false: stop of the interval
    // true: yes!
    set<long long int> range;
    map<long long int, bool> mp;
    int n, a;
    long long int r;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> r;
            range.emplace(r);
            mp[r] = true;
            cin >> r;
            range.emplace(r);
            mp[r] = false;
            continue;
        }
        cin >> r;
        auto pt = range.lower_bound(r);
        if (pt != range.end() && (mp[*pt] == false || *pt == r)) cout << 0;
        else cout << 1;
        cout << "\n";
    }
}
