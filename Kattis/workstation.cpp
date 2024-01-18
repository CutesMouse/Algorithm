#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> ppq;
    vector<pair<int, int>> emp;
    int n, m, a, b;
    int wc = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        emp.emplace_back(a, a + b);
    }
    sort(emp.begin(), emp.end());
    for (auto [st, ed] : emp) {
        while (ppq.size() && st - ppq.top() > m) {
            ppq.pop();
        }
        if (ppq.size() && ppq.top() <= st) {
            //cout << st << " " << ppq.top() << endl;
            ppq.pop();
            wc++;
        }
        ppq.emplace(ed);
    }
    cout << wc;
}
