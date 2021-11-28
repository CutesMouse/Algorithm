#include <iostream>
#include <vector>
#include <cstring>
#define INF 100000000
using namespace std;

int from[2005],to[2005],weight[2005];
int m;
int dis[1005];
bool relax()
{
    bool update = false;
    for (int i = 0; i < m; i++) {
        int f = from[i];
        int t = to[i];
        int w = weight[i];
        if (dis[f] == INF) continue;
        if (dis[t] > dis[f] + w) {
            update = true;
            dis[t] = dis[f] + w;
        }
    }
    return update;
}
int main()
{
    int c;
    cin >>c;
    while (c--)
    {
        dis[0] = 0;
        int n;
        cin >> n >> m;
        for (int i = 1; i < n; i++) dis[i] = INF;
        for (int i = 0; i <m ; i++)
        {
            cin >>from[i] >> to[i]>>weight[i];
        }
        for (int i = 0; i < n-1; i++)
        {
            relax();
        }
        if (relax())
        {
            cout << "possible\n";
        }
        else cout << "not possible\n";
    }
}
