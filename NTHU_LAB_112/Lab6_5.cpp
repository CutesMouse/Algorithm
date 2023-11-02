#include <iostream>
#include <queue>
#include <set>
using namespace std;

// power of ten
int pt(int n) {
    int k = 1;
    for (int i = 0; i < n; i++) k *= 10;
    return k;
}

int swap_digit(int s, int pos1, int pos2) {
    int d1 = (s / pt(8 - pos1)) % 10;
    int d2 = (s / pt(8 - pos2)) % 10;
    return s + (d2 - d1) * pt(8 - pos1) + (d1 - d2) * pt(8 - pos2);
}

int main() {
    int s = 0;
    set<int> used;
    int finish = 123456789;
    int n;
    for (int i = 0; i < 9; i++) {
        cin >> n;
        s *= 10;
        s += n;
    }
    queue<int> q;
    q.emplace(s);
    used.emplace(s);
    int level = 0;
    while (q.size()) {
        for (int i = q.size(); i > 0; i--) {
            s = q.front();
            q.pop();
            if (s == finish) {
                cout << level;
                return 0;
            }
            // horizon
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 2; c++) {
                    int ns = swap_digit(s, 3 * r + c, 3 * r + c + 1);
                    if (used.count(ns)) continue;
                    q.emplace(ns);
                    used.emplace(ns);
                }
            }
            // vertical
            for (int r = 0; r < 2; r++) {
                for (int c = 0; c < 3; c++) {
                    int ns = swap_digit(s, 3 * r + c, 3 * r + c + 3);
                    if (used.count(ns)) continue;
                    q.emplace(ns);
                    used.emplace(ns);
                }
            }
        }
        level++;
    }
}
