#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N, a, b;
    while (cin >> N) {
        priority_queue<int, vector<int>, less<>> pq;
        queue<int> q;
        stack<int> s;
        bool st = true, qu = true, prq = true;
        while (N--) {
            cin >> a >> b;
            if (a == 1) {
                q.push(b);
                pq.emplace(b);
                s.push(b);
            } else {
                st = st && (!s.empty() && s.top() == b);
                qu = qu && (!q.empty() && q.front() == b);
                prq = prq && (!pq.empty() && pq.top() == b);
                if (!s.empty()) s.pop();
                if (!q.empty()) q.pop();
                if (!pq.empty()) pq.pop();
            }
        }
        if (st && !qu && !prq) cout << "stack\n";
        else if (!st && qu && !prq) cout << "queue\n";
        else if (!st && !qu && prq) cout << "priority queue\n";
        else if (st || qu || prq) cout << "not sure\n";
        else cout << "impossible\n";
    }
}
