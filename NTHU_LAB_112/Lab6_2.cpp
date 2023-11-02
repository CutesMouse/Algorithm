#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N, Q;

int p51(int k) {
    int j = 1;
    for (int i = 0; i < k; i++) j *= 51;
    return j;
}

int get_digit(int n, int pos) {
    return (n / p51(pos)) % 51;
}

int set_digit(int n, int pos, int val) {
    //cout <<"check: " << pos<<endl;
    int p = p51(pos);
    return n - ((n / p) % 51) * p + val * p;
}

void prt(int k) {
    return;
    for (int i = 0; i < N; i++) {
        cout << get_digit(k, i) << " ";
    }
    cout <<endl;
}

int main() {
    set<int> used;
    queue<int> q;
    int mx[5];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> mx[i];
    }
    cin >> Q;
    for (int i = 0; i < N; i++) {
        if (mx[i] == Q) {
            cout << 1;
            return 0;
        }
    }
    q.emplace(0);
    used.emplace(0);
    int level = 0;
    while (q.size()) {
        for (int i = q.size(); i > 0; i--) {
            int s = q.front();
            q.pop();
            // perform step 1
            for (int j = 0; j <N; j++) {
                int ns = set_digit(s, j, mx[j]);
                //cout << ns <<endl;
                if (used.count(ns)) continue;
                used.emplace(ns);
                q.emplace(ns);
            }
            // perform step 2
            for (int j = 0; j <N; j++) {
                int ns = set_digit(s, j, 0);
                if (used.count(ns)) continue;
                used.emplace(ns);
                q.emplace(ns);
            }
            // perform step 3

            for (int j = 0; j <N; j++) {
                for (int k = 0; k < N; k++) {
                    if (j == k) continue;
                    int j_ori = get_digit(s, j);
                    int k_ori = get_digit(s, k);
                    int k_p = min(j_ori + k_ori, mx[k]);
                    int j_p = j_ori + k_ori - k_p;
                    if (k_p == Q || j_p == Q) {
                        cout << level + 1;
                        return 0;
                    }
                    int ns = set_digit(set_digit(s, j, j_p), k, k_p);
                    if (used.count(ns)) continue;
                    used.emplace(ns);
                    q.emplace(ns);
                }

            }
        }
        level++;
    }
    cout << -1;
}
