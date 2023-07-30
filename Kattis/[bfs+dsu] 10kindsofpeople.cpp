#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int r = 0, c = 0;
bool map[1000 * 1000];
bool used[1000 * 1000] = {false};
int boss[1000 * 1000];
typedef pair<int, int> p;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int flat(int x, int y) {
    return c * x + y;
}

void bond(int x, int y) {
    int b1 = boss[x];
    int b2 = boss[y];
    if (b1 == b2) return;
    boss[b2] = b1;
}

int query(int x) {
    return (boss[x] == x ? x : boss[x] = query(boss[x]));
}

void bonding(int r1, int c1) {
    bool move = map[flat(r1, c1)];
    queue<p> q;
    q.emplace(r1, c1);
    used[flat(r1, c1)] = true;
    while (!q.empty()) {
        p info = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = info.first + dx[i];
            int nc = info.second + dy[i];
            if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
            if (used[flat(nr, nc)]) continue;
            if (map[flat(nr, nc)] != move) continue;
            used[flat(nr, nc)] = true;
            bond(flat(r1, c1), flat(nr, nc));
            q.emplace(nr, nc);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    char k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> k;
            map[flat(i, j)] = (k - '0');
            boss[flat(i, j)] = flat(i, j);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (used[flat(i, j)]) continue;
            bonding(i, j);
        }
    }

    int q;
    cin >> q;
    int r1, c1, r2, c2;
    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        if (query(flat(r1, c1)) == query(flat(r2, c2))) {
            if (map[flat(r1, c1)]) cout << "decimal\n";
            else cout << "binary\n";
        } else cout << "neither\n";
    }

}
