    #include <iostream>
    #include <queue>
    #define BLANK 0
    #define WALL 1
    #define USED 2
    using namespace std;
    const pair<int, int> mv[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maze[1005][1005];
    int n, m;
    int ans = 0;

    bool bfs(int r, int c) {
        if (maze[r][c] != BLANK) return false;
        queue<pair<int, int> > q;
        maze[r][c] = USED;
        q.emplace(r, c);
        while (q.size()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for (auto [dr, dc] : mv) {
                if (!maze[r + dr][c + dc]) {
                    maze[r + dr][c + dc] = USED;
                    q.emplace(r + dr, c + dc);
                }
            }
        }
        return true;
    }

    int main() {
        cin >> n >> m;
        char ch;
        for (int x = 0; x <= (n+1); x++) {
            maze[x][0] = WALL;
            maze[x][m+1] = WALL;
        }
        for (int x = 0; x <= (m+1); x++) {
            maze[0][x] = WALL;
            maze[n+1][x] = WALL;
        }
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                cin >> ch;
                if (ch == '#') maze[r][c] = WALL;
                else maze[r][c] = BLANK;
            }
        }
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                ans += bfs(r, c);
            }
        }
        cout << ans;
    }
