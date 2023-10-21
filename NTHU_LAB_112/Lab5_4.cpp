#include <iostream>
#include <queue>
using namespace std;

typedef long long int ll;

int main() {
    int Q;
    int a;
    ll x;
    deque<ll> tmp;
    priority_queue<ll, vector<ll>, greater<ll>> ppq;

    cin >> Q;
    while (Q--) {
        cin >> a;
        if (a == 1) {
            cin >> x;
            tmp.emplace_back(x);
        } else if (a == 2) {
            if (ppq.size()) {
                cout << ppq.top() << endl;
                ppq.pop();
            } else {
                cout << tmp.front() << endl;
                tmp.pop_front();
            }
        } else {
            for (ll j : tmp) ppq.emplace(j);
            tmp.clear();
        }
    }
}
