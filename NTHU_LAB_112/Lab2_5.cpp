#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// r, c
pair<int, int> ds[2][6] = {{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {0, -1}}, {{-1, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, -1}, {0, -1}}};
int grid[15][10];
int cost[15][10];

int R, C;
long long int min_cost = -1;
pair<int, int> n1;
pair<int, int> n2;
pair<int, int> h1;
pair<int, int> h2;

void dfs(int r, int c, long long int money, int phase, int from) {
    if (phase == 2 && r == h2.first && c == h2.second) {
        if (min_cost == -1) min_cost = money;
        min_cost = min(min_cost, money);
        return;
    }
    if (phase == 1 && r == n2.first && c == n2.second) {
        dfs(h1.first, h1.second, money + cost[h1.first][h1.second], 2, -1);
        return;
    }
    for (int i = 0; i < 6; i++) {
        int nr = r + ds[r % 2][i].first;
        int nc = c + ds[r % 2][i].second;
        if (grid[nr][nc]) continue;
        if (from != -1 && (((from + 2) % 6) == i || ((from + 3) % 6) == i || ((from + 4) % 6) == i)) continue;
        grid[nr][nc] = phase;
        //printf("passing %d, %d, money: %d, cost add: %d, phase: %d\n", nr, nc, money, cost[nr][nc], phase);
        dfs(nr, nc, money + cost[nr][nc], phase, i);
        grid[nr][nc] = 0;
    }
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        min_cost = -1;
        memset(grid, 0, sizeof grid);
        cin >> R >> C;
        cin >> n1.first >> n1.second;
        cin >> n2.first >> n2.second;
        cin >> h1.first >> h1.second;
        cin >> h2.first >> h2.second;
        for (int i = 0; i <= R+1; i++) {
            grid[i][0] = -1;
            grid[i][C+1] = -1;
        }
        for (int i = 0; i <= C+1; i++) {
            grid[0][i] = -1;
            grid[R+1][i] = -1;
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> cost[i][j];
            }
        }
        grid[n1.first][n1.second] = 1;
        grid[h1.first][h1.second] = 2;
        dfs(n1.first, n1.second, cost[n1.first][n1.second], 1, -1);
        cout << min_cost << "\n";
    }
}
