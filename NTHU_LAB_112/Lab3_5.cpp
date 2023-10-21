#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <map>
using namespace std;

int main() {
    //freopen("output.txt", "w", stdout);
    int t;
    int n, q, a;
    char c;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        // 0: head
        // 1: tail
        // 2: ignore
        map<int, int> prt;
        stack<int> head;
        stack<int> tail;
        while (q--) {
            cin >> c >> a;
            if (c == 'H') {
                prt[a] = 0;
                head.push(a);
            } else {
                prt[a] = 1;
                tail.push(a);
            }
        }
        while (!head.empty()) {
            int p = head.top();
            if (prt.count(p) && prt[p] == 0) {
                cout << p << " ";
                prt[p] = 2;
            }
            head.pop();
        }
        for (int i = 1; i <= n; i++) {
            if (!prt.count(i)) {
                cout << i << " ";
            }
        }
        vector<int> inv;
        while (!tail.empty()) {
            int p = tail.top();
            if (prt.count(p) && prt[p] == 1) {
                inv.push_back(p);
                prt[p] = 2;
            }
            tail.pop();
        }
        for (auto iter = inv.rbegin(); iter != inv.rend(); iter++) {
            cout << *iter << " ";
        }
        cout <<endl;
    }
}
