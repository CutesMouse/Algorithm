#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> loc;
int d_x[8000000];
int d_y[8000000];
int d_dir[8000000];
int ptr = 0;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int dis[1000][1000][4];
void flat(loc &l)
{
    l.first --;
    l.second --;
}
int main()
{
    memset(dis,-1,sizeof(dis));
    // 輸入測資
    int H,W;
    cin >>H >> W;
    loc st;
    cin >> st.first >>st.second;
    loc ed;
    cin >>ed.first >> ed.second;
    flat(st);
    flat(ed);
    string maze[1000];
    for (int i = 0 ; i < H; i++)
    {
        cin >> maze[i];
    }
    // Dijkstra
    priority_queue<loc,vector<loc>,greater<loc> > pq;
    d_x[ptr] = st.first;
    d_y[ptr] = st.second;
    d_dir[ptr] = 5;
    pq.emplace(0,ptr);
    ptr++;
    while (pq.size())
    {
        auto now = pq.top();
        pq.pop();
        int x = d_x[now.second];
        int y = d_y[now.second];
        int dir = d_dir[now.second];
        // dir = 5，表示起始，沒有資料
        // dis[x][y][dir] 不等於現在步數，表示此路徑已被之前的運算取代，不用重複運算
        if (dir != 5 && dis[x][y][dir] != now.first) continue;

        for (int r = 0; r < 4; r++)
        {
            int nx = x + dx[r];
            int ny = y + dy[r];
            // 超出地圖範圍
            if (nx >= H || ny >= W || nx < 0 || ny < 0) continue;
            // 該格有屏障，無法前行
            if (maze[nx][ny] == '#') continue;
            // dir = 5，起點操作
            if (dir == 5)
            {
                d_x[ptr] = nx;
                d_y[ptr] = ny;
                d_dir[ptr] = r;
                dis[nx][ny][r] = 1;
                pq.emplace(1,ptr);
                ptr++;
                continue;
            }
            // 當前步數
            int ndis = dis[x][y][dir] + (dir != r);
            // dis = -1 表示沒有被走過
            // dis > ndis 表示有更好的方式
            if (dis[nx][ny][r] == -1 || dis[nx][ny][r] > ndis)
            {
                d_x[ptr] = nx;
                d_y[ptr] = ny;
                d_dir[ptr] = r;
                dis[nx][ny][r] = ndis;
                pq.emplace(ndis,ptr);
                ptr++;
            }
        }
    }
    
    int moves = -1;
    for (int i = 0; i < 4; i++) {
        int m = dis[ed.first][ed.second][i];
        if (m == -1) continue;
        if (moves == -1) moves = m;
        moves = min(moves,m);
    }
    cout << moves - 1 << endl;
}
