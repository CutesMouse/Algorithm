#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,int> pp;
typedef priority_queue<pp,vector<pp>,greater<pp> > ppq;

vector<pp> edges[100005];
int dis_begin[100005],dis_end[100005];

void dij(int* dis, int start, int to)
{
    ppq q;
    q.emplace(0,start);
    dis[start] = 0;
    while (q.size())
    {
        pp pr = q.top();
        q.pop();
        if (pr.first != dis[pr.second]) continue;
        for (auto edge : edges[pr.second])
        {
            if (dis[edge.second] == -1 || dis[edge.second] > pr.first + edge.first)
            {
                dis[edge.second] = pr.first + edge.first;
                q.emplace(dis[edge.second],edge.second);
            }
        }
    }
}

int main()
{
    int N,M;
    cin >> N >> M;
    int from,to,weight;
    for (int i = 0; i <M; i++)
    {
        cin >> from >> to >> weight;
        edges[from].emplace_back(weight,to);
        edges[to].emplace_back(weight,from);
    }
    memset(dis_begin,-1,sizeof(dis_begin));
    memset(dis_end,-1,sizeof(dis_end));
    dij(dis_begin,1,N);
    dij(dis_end,N,1);
    for (int i = 1; i <= N; i++) {
        cout << dis_begin[i] + dis_end[i] << endl;
    }

}
