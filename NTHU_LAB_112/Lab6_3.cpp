#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool maze[1005][1005];
int from[1005][1005];
int sr, sc;
int fr, fc;
int R, C;
const pair<int,int> m[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char trans[4] = {'R', 'L', 'D', 'U'};

int main() {
    cin >> R >> C;
    memset(from, 0, sizeof(from));
    for (int i = 0; i <= (R+1); i++) {
        maze[i][0] = -1;
        maze[i][C+1] = -1;
    }
    for (int i = 0; i <= (C+1); i++) {
        maze[0][i] = -1;
        maze[R+1][i] = -1;
    }
    char ch;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> ch;
            maze[r][c] = (ch == '#');
            if (ch == 'A') {
                sr = r;
                sc = c;
            }
            if (ch == 'B') {
                fr = r;
                fc = c;
            }
        }
    }
    from[sr][sc] = -1;
    maze[sr][sc] = 1;
    queue<pair<int,int>> q;
    q.emplace(sr, sc);
    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();
        if (r == fr && c == fc) break;
        for (int i = 0; i < 4; i++) {
            auto [dr, dc] = m[i];
            int nr = r + dr;
            int nc = c + dc;
            if (!maze[nr][nc]) {
                maze[nr][nc] = 1;
                from[nr][nc] = i+1;
                q.emplace(nr, nc);
            }
        }
    }
    if (!from[fr][fc]) cout << "NO";
    else {
        cout << "YES\n";
        string path;
        while (from[fr][fc] != -1) {
            path.push_back(trans[from[fr][fc]-1]);
            auto [dr, dc] = m[from[fr][fc]-1];
            fr = fr - dr;
            fc = fc - dc;
        }
        cout << path.size() << "\n";
        for (auto iter = path.rbegin(); iter != path.rend(); iter++) cout << *iter;
    }
}
