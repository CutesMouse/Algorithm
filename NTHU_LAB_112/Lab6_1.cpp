#include <iostream>
#include <set>
#include <cstring>
#include <queue>
using namespace std;

int input[7][7] = {0};

struct Element {
    // up&left most
    int r = 0, c = 0;
    int l = 0;
    // 0: row, 1: col
    bool d = 0;
    bool operator<(const Element e) const {
        if (e.r != r) return r < e.r;
        if (e.c != c) return c < e.c;
        if (e.l != l) return l < e.l;
        if (e.d != d) return d < e.d;
        return false;
    }
    bool operator==(const Element e) const {
        return (r == e.r) && (c == e.c) && (l == e.l) && (d == e.d);
    }
    bool operator!=(const Element e) const {
        return !(*this == e);
    }
};

struct Layout {
    Element e[11];
    bool operator<(const Layout layout) const {
        for (int i = 1; i <= 10; i++) {
            if (e[i] != layout.e[i]) return e[i] < layout.e[i];
        }
        return false;
    }
};

Layout cio() {
    Layout layout;
    bool used[11] = {1};
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            int id = input[r][c];
            if (used[id]) continue;
            int lr = 1, lc = 1;
            int tr = r, tc = c;
            while (input[tr+1][c] == id) lr++, tr++;
            while (input[r][tc+1] == id) lc++, tc++;
            if (lr != 1) {
                layout.e[id] = {r, c, lr, 0};
            } else {
                layout.e[id] = {r, c, lc, 1};
            }
            used[id] = true;
        }
    }
    return layout;
}

void plot_col(Layout layout, int col) {
    for (int i = 0; i < 6; i++) input[i][col] = 0;
    for (int i = 1; i <= 10; i++) {
        Element e = layout.e[i];
        if (e.l == 0) continue;
        // up-down, change in rows
        if (e.d == 0) {
            if (e.c != col) continue;
            for (int j = e.r; j < (e.r + e.l); j++) {
                input[j][col] = i;
            }
            continue;
        }
        // left-right, change in cols
        if (e.c > col) continue;
        if (e.c + e.l > col) input[e.r][col] = i;
    }
}
void plot_row(Layout layout, int row) {
    for (int i = 0; i < 6; i++) input[row][i] = 0;
    for (int i = 1; i <= 10; i++) {
        Element e = layout.e[i];
        if (e.l == 0) continue;
        // up-down, change in rows
        if (e.d == 0) {
            if (e.r > row) continue;
            if (e.r + e.l > row) input[row][e.c] = i;
            continue;
        }
        // left-right, change in cols
        if (e.r != row) continue;
        for (int j = e.c; j < (e.c + e.l); j++) {
            input[row][j] = i;
        }
        continue;
    }
}

int main() {
    set<Layout> used;
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            cin >> input[r][c];
        }
    }
    int ans = 11;
    Layout init = cio();
    queue<Layout> q;
    q.emplace(init);
    used.emplace(init);
    for (int level = 0; level <= 10; level++) {
        for (int i = q.size(); i > 0; i--) {
            Layout layout = q.front();
            q.pop();
            if (layout.e[1].c + layout.e[1].l >= 6) {
                ans = min(ans, level + layout.e[1].l);
            }
            for (int j = 1; j <= 10; j++) {
                if (!layout.e[j].l) continue;
                int r = layout.e[j].r;
                int c = layout.e[j].c;
                int l = layout.e[j].l;
                if (layout.e[j].d == 0) {
                    // up-down, change in rows
                    plot_col(layout, c);
                    // move to top
                    if (r - 1 >= 0 && !input[r-1][c]) {
                        layout.e[j].r = r - 1;
                        if (!used.count(layout)) {
                            used.emplace(layout);
                            q.emplace(layout);
                        }
                    }
                    // move to bot
                    if (r + l < 6 && !input[r + l][c]) {
                        layout.e[j].r = r + 1;
                        if (!used.count(layout)) {
                            used.emplace(layout);
                            q.emplace(layout);
                        }
                    }
                    layout.e[j].r = r;
                } else {
                    // left-right, change in cols
                    // move to left
                    plot_row(layout, r);
                    if (c - 1 >= 0 && !input[r][c-1]) {
                        layout.e[j].c = c - 1;
                        if (!used.count(layout)) {
                            used.emplace(layout);
                            q.emplace(layout);
                        }
                    }
                    // move to right
                    if (c + l < 6 && !input[r][c+l]) {
                        layout.e[j].c = c + 1;
                        if (!used.count(layout)) {
                            used.emplace(layout);
                            q.emplace(layout);
                        }
                    }
                    layout.e[j].c = c;
                }
            }
        }
    }
    if (ans == 11) cout << -1;
    else cout << ans;
}
