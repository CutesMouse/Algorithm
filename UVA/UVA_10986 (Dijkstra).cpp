#include <iostream>
#include <cstring>
#include <queue>
#define step first
#define pos second
using namespace std;
int n,m,S,T;
typedef pair<int,int> pp;
typedef priority_queue<pp,vector<pp>,greater<pp> > ppq;
int dis[20000];

int main() {
    int c;
    cin >> c;
    for (int pcase = 1; pcase <= c; pcase++) {
        vector<pp> line[50000];
        cin >> n >> m >> S >> T;
        int u,v,w;
        memset(dis,-1,sizeof(dis));
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            line[u].emplace_back(v,w);
            line[v].emplace_back(u,w);
        }
        ppq pq;
        pq.emplace(0,S);
        dis[S] = 0;
        while(!pq.empty()) {
            auto p = pq.top();
            //printf("%d, %d\n",p.first,p.second);
            pq.pop();
            if (p.step != dis[p.pos]) continue;
            if (p.pos == T) break;
            for (auto iter = line[p.pos].begin(); iter != line[p.pos].end(); iter++) {
                int i = iter->first;
                if (dis[i] == -1 || dis[i] > dis[p.pos] + iter->second) {
                    dis[i] = dis[p.pos] + iter->second;
                    pq.emplace(dis[i],i);
                }
            }
        }
        if (dis[T] == -1) {
            printf("Case #%d: unreachable\n",pcase);
        } else printf("Case #%d: %d\n",pcase,dis[T]);
    }
}
