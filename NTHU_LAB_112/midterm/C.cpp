#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, q, a;
    long long int k, tmp;
    cin >> n;
    cin >> k;
    multiset<long long int> que;
    while (n--) {
        cin >> tmp;
        que.emplace(tmp);
    }
    cin >> q;
    while (q--) {
        cin >> a >> tmp;
        if (a == 1) {
            que.erase(que.find(tmp));
            //cout << que.size() << endl;
            //cout << "OuOb\n";
            //continue;
        }
        else que.emplace(tmp);
        tmp = -1;
        bool safe = true;
        for (auto iter = que.begin(); iter != que.end(); iter++) {
                //cout << *iter << " ";
            if (tmp == -1 || *iter - tmp >= k) {
                tmp = *iter;
                continue;
            }
            safe = false;
            break;
        }
        if (safe) cout << "OuOb\n";
        else cout << "QQ\n";
        /*auto beg = que.lower_bound(tmp);
        auto ed = beg;
        if (beg != que.begin()) beg--;
        if (a == 1) {
            if (ed != que.end() && abs(*ed - *beg) <= k) cout << "QQ\n";
            else cout << "OuOb\n";
            continue;
        }
        //cout << *beg << ", "<<*ed << endl;
        if (que.size() && abs(*(beg) - tmp) <= k) cout << "QQ\n";
        else if (ed != que.end() && abs(*ed - tmp) <= k) cout << "QQ\n";
        else cout << "OuOb\n";
        if (a == 2) que.emplace(tmp);*/
    }
}
