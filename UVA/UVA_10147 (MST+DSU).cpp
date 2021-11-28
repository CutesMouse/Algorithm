#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int x[750],y[750];
int roots[750];
vector<pair<double,pair<int,int> > > edges;
int find_root(int a)
{
    if (roots[a] != -1)
    {
        roots[a] = find_root(roots[a]);
        return roots[a];
    }
    return a;
}
void bond(int a, int b)
{
    int ra = find_root(a);
    int rb = find_root(b);
    if (ra == rb) return;
    roots[ra] = rb;
}
bool is_bond(int a, int b)
{
    return find_root(a) == find_root(b);
}
double weight(int dx, int dy)
{
    return sqrt(dx*dx + dy*dy);
}
int main()
{
    int n;
    cin >>n;
    bool first = true;
    while (n--)
    {
        if (!first) cout << endl;
        first = false;
        edges.clear();
        memset(roots,-1,sizeof(roots));
        int N;
        cin >> N;
        for (int i =0; i < N; i++) cin >> x[i] >> y[i];
        for (int from = 0; from < N; from++)
        {
            for (int to = from+1; to < N; to++)
            {
                pair<int,int> dest = {from,to};
                edges.emplace_back(weight(x[from] - x[to],y[from] - y[to]),dest);
            }
        }
        int M;
        cin >>M;
        for (int i = 0; i <M; i++)
        {
            int a,b;
            cin >> a >> b;
            bond(a-1,b-1);
        }
        sort(edges.begin(),edges.end());
        bool build = false;
        for (auto iter = edges.begin(); iter != edges.end(); iter ++)
        {
            double w = iter->first;
            int from = iter->second.first;
            int to = iter->second.second;
            if (is_bond(from,to)) continue;
            bond(from,to);
            build = true;
            cout << from+1 <<" "<< to+1 <<endl;
        }
        if (!build) printf("No new highways need\n");
    }
}
