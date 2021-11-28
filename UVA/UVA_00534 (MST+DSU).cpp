#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> loc;
vector<pair<double,loc> > edges;
// first: max_dis, second: from A to B
double weight(loc a, loc b)
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx*dx + dy*dy);
}
int roots[200];
int find_root(int k)
{
    if (roots[k])
    {
        int r = roots[k];
        roots[k] = find_root(r);
        return roots[k];
    }
    return k;
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


loc v[200];
int main()
{
    int s = 0;
    int N,x,y;
    while(cin >> N)
    {
        s++;
        if (N == 0) return 0;
        memset(roots,0,sizeof(roots));
        edges.clear();
        for (int i = 0; i < N; i++)
        {
            cin >>x >> y;
            loc k = {x,y};
            v[i] = k;
        }
        for (int a = 0; a < N; a++)
        {
            for (int b = a+1; b <N; b++)
            {
                auto loc_a = v[a];
                auto loc_b = v[b];
                double dis = weight(loc_a,loc_b);
                loc p = {a,b};
                edges.emplace_back(dis,p);
            }
        }
        sort(edges.begin(),edges.end());
        double max_dis = 0;
        for (auto iter = edges.begin(); iter != edges.end(); iter++)
        {
            if (is_bond(0,1)) break;
            bond(iter->second.first,iter->second.second);
            max_dis = iter->first;
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",s,max_dis);
    }

}
