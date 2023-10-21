#include <iostream>
#include <stack>
using namespace std;

typedef long long int ll;

int main() {
    stack<pair<ll, int>> stk;
    int n;
    ll k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        while (stk.size() && k <= stk.top().first) stk.pop();
        cout << (stk.size() ? (stk.top().second+1) : 0) << " ";
        stk.emplace(k, i);
    }
}
