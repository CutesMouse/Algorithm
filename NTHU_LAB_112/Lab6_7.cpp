#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

bool maze[1005][1005];
int from[1005][1005];
int R, C;
pair<int, int> m[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char trans[4] = {'R', 'L', 'D', 'U'};

bool is_edge(int r, int c) {
    return (r == 1) || (c == 1) || (r == R) || (c == C);
}

int main() {
    char buffer;
    cin >> R >> C;
    memset(maze, 0, sizeof maze);
    pair<int, int> player;
    queue<pair<pair<int, int>, char>> Q;
    for (int r = 0; r <= (R+1); r++) {
        maze[r][0] = true;
        maze[r][C+1] = true;
    }
    for (int c = 0; c <= (C+1); c++) {
        maze[0][c] = true;
        maze[R+1][c] = true;
    }
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> buffer;
            maze[r][c] = (buffer != '.');
            from[r][c] = -1;
            if (buffer == 'M') {
                Q.emplace(make_pair(r, c), buffer);
            }
            if (buffer == 'A') {
                player = {r, c};
            }
        }
    }
    Q.emplace(player, 'A');
    int level = 0;
    while (Q.size()) {
        for (int k = Q.size(); k > 0; k--) {
            auto [p, type] = Q.front();
            auto [r, c] = p;
            Q.pop();
            if (type == 'A' && is_edge(r, c)) {
                cout << "YES\n";
                cout << level << "\n";
                //trace
                int f = from[r][c];
                string inv;
                while (f != -1) {
                    inv.push_back(trans[f]);
                    r -= m[f].first;
                    c -= m[f].second;
                    f = from[r][c];
                }
                cout << string(inv.rbegin(), inv.rend());
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + m[i].first;
                int nc = c + m[i].second;
                if (maze[nr][nc]) continue;
                maze[nr][nc] = true;
                from[nr][nc] = i;
                Q.emplace(make_pair(nr, nc), type);
            }
        }
        level++;
    }
    cout << "NO";
}
