#include <iostream>
using namespace std;


int table[25][25];
bool bomb[25][25] = {0};

pair<int, int> mk[9] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

int r, c;
int ans = 0;

void defuse_bomb(int pr, int pc) {
    bomb[pr][pc] = 0;
    for (auto &[dr, dc] : mk) {
        int nr = pr + dr;
        int nc = pc + dc;
        if (nr >= r || nr < 0 || nc >= c || nc < 0) continue;
        table[nr][nc]++;
    }
}

bool place_bomb(int pr, int pc) {
    bomb[pr][pc] = 1;
    bool ok = true;
    for (auto &[dr, dc] : mk) {
        int nr = pr + dr;
        int nc = pc + dc;
        if (nr >= r || nr < 0 || nc >= c || nc < 0) continue;
        ok = ok && table[nr][nc] > 0;
        table[nr][nc]--;
    }
    return ok;
}

//從左上角格子推斷右下角格子
bool legal_plot_row(int nr) {
    for (int nc = 1; nc < c; nc++) {
        //對[nr-1][nc-1]而言，未定的格子只剩一格
        //因此若大於2，表示為不可能的組合
        if (table[nr-1][nc-1] >= 2) return false;
        if (table[nr-1][nc-1]) place_bomb(nr, nc);
    }
    return true;
}

void reset_row(int nr) {
    for (int nc = 1; nc < c; nc++) {
        if (bomb[nr][nc]) defuse_bomb(nr, nc);
    }
}

void dfs2(int depth) {
    if (depth == r) {
        bool ok = true;
        for (int nr = 0; nr < r; nr++) {
            for (int nc = 0; nc < c; nc++) {
                ok = ok && (!table[nr][nc]);
            }
        }
        ans += ok;
        return;
    }
    if (depth >= 2) {
        for (int i = 0; i < c; i++) {
            if (table[depth-2][i]) return;
        }
    }
    // place no bomb
    if (legal_plot_row(depth)) dfs2(depth+1);
    reset_row(depth);
    // place bomb
    place_bomb(depth, 0);
    if (legal_plot_row(depth)) dfs2(depth+1);
    reset_row(depth);
    defuse_bomb(depth, 0);
}

// 窮舉r=0
void dfs1(int depth) {
    if (depth == c) {
        dfs2(1);
        //if (legal_plot()) cout << depth<<"!" << endl;
        return;
    }
    dfs1(depth+1);
    if (place_bomb(0, depth)) dfs1(depth+1);
    defuse_bomb(0, depth);
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> table[i][j];
        }
    }
    dfs1(0);
    cout << ans;
}
