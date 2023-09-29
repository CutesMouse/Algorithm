#include <iostream>
#include <cstring>
using namespace std;

int ans;
bool used[7][7];
string io;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int depth, int x, int y) {
    //�W�L���
    if (x < 0 || y < 0 || x >= 7 || y >= 7) return;
    //�w�Q�M���L
    if (used[x][y]) return;
    //���e��F���U��
    if (x == 0 && y == 6 && depth < 48) return;
    //���� (x��V)
    if ((x == 0 || x == 6) && y != 0 && y != 6 && !used[x][y-1] && !used[x][y+1]) return;
    //���� (y��V)
    if ((y == 0 || y == 6) && x != 0 && x != 6 && !used[x-1][y] && !used[x+1][y]) return;
    //����ۤv���L���� (x��V)
    if ((x != 0 && x != 6 && y != 0 && y != 6) &&
        (used[x+1][y] && used[x-1][y] && !used[x][y-1] && !used[x][y+1] ||
        used[x][y+1] && used[x][y-1] && !used[x+1][y] && !used[x-1][y])) return;

    if (depth == 48) {
        if (x != 0 || y != 6) return;
        ans++;
        return;
    }
    //cout <<x << ", " << y << endl;
    used[x][y] = true;
    int nx, ny;
    if (io[depth] == '?') {
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (used[nx][ny]) continue;
            dfs(depth+1, nx, ny);
        }
    } else {
        switch (io[depth]) {
        case 'D':
            nx = x;
            ny = y + 1;
            break;
        case 'U':
            nx = x;
            ny = y - 1;
            break;
        case 'L':
            nx = x - 1;
            ny = y;
            break;
        case 'R':
            nx = x + 1;
            ny = y;
            break;
        }
        dfs(depth+1, nx, ny);
    }
    used[x][y] = false;
}

int main() {
    cin >> io;
    ans = 0;
    memset(used, 0, sizeof(used));
    dfs(0, 0, 0);
    cout << ans;
}
