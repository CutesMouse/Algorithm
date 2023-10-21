#include <iostream>
#include <stack>
using namespace std;

typedef long long int ll;

int main() {
    int n;
    ll h;
    while (cin >> n) {
        stack<pair<ll, int>> stk;
        ll mx = 0;
        int idx;
        for (int i = 0; i < n; i++) {
            cin >> h;
            idx = i;
            while (stk.size() && stk.top().first >= h) {
                mx = max(mx, (i - stk.top().second) * stk.top().first);
                idx = stk.top().second;
                //cout << "pop " << stk.top().second << " " << (i - idx) * stk.top().first << endl;
                stk.pop();
            }
            stk.emplace(h, idx);
        }
        while (stk.size()) {
            mx = max(mx, (n - stk.top().second) * stk.top().first);
            //cout << "pop " << stk.top().second << " " << (n - stk.top().second) * stk.top().first << endl;
            stk.pop();

        }
        cout << mx << endl;
    }
}
