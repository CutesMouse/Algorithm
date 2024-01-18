#include <iostream>
#define maxn 150
#define INF (1<<28)
using namespace std;

int dis[maxn][maxn];
int n, m, q;

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = (i == j ? 0 : INF);
        }
    }
}

void floyd() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (dis[i][k] == INF || dis[k][j] == INF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }


    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; dis[i][j] != -INF && k < n; k++)
                if(dis[i][k] != INF && dis[k][j] != INF && dis[k][k] < 0) dis[i][j] = -INF;

}

int main() {
    //freopen("test.txt","w",stdout);
    int u, v, w;
    while (cin >> n >> m >> q && n) {
        reset();
        while (m--) {
            cin >> u >> v >> w;
            dis[u][v] = min(dis[u][v], w);
        }
        floyd();
        while (q--) {
            cin >> u >> v;
            if (dis[u][v] == INF) cout << "IMPOSSIBLE\n";
            else if (dis[u][v] == -INF) cout << "-Infinity\n";
            else cout << dis[u][v] << "\n";
        }
        cout << "\n";
    }
}
