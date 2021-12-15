#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int W,N;
typedef long long ll;
class segtree
{
public:
    ll tree[10005*4];
    int p = 0;
    int q = 10004;
    segtree()
    {
        for (int i = 0; i < 10005*4; i++) tree[i] = -(1LL<<60);
    }
    ll query(int f, int t)
    {
        return _query(1,f,t,p,q);
    }
    ll _query(int id, int f, int t, int p, int q)
    {
        if (p == q) return tree[id];
        if (f <= p && t >= q) return tree[id];
        int mid = (p+q)>>1;
        ll mx = -(1LL<<60);
        if (f <= mid) mx = max(mx,_query(id<<1,f,t,p,mid));
        if (t > mid) mx = max(mx,_query(id<<1|1,f,t,mid+1,q));
        return mx;
    }
    void modify(int k, ll v)
    {
        _modify(1,k,p,q,v);
    }
    void _modify(int id, int k, int p, int q, ll v)
    {
        //printf("id:%d, k:%d, p:%d, q:%d, v:%d\n",id,k,p,q,v);
        if (p == q)
        {
            tree[id] = v;
            return;
        }
        // p---k--mid--q
        int mid = (p+q)>>1;
        if (k <= mid)
        {
            _modify(id<<1,k,p,mid,v);
        }
        else
        {
            _modify(id<<1|1,k,mid+1,q,v);
        }
        tree[id] = max(tree[id<<1],tree[id<<1|1]);
    }
};
int L[500],R[500],V[500];
segtree d[505];
int main()
{
    int A[500];
    cin >> W >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> R[i] >> V[i];
    }
    d[0].modify(0,0);
    map<int,ll> table;
    for (int n = 1; n <= N; n++)
    {
        for (int w = 0; w <= W; w++)
        {
            ll m = d[n-1].query(w,w);
            int qfrom = w - R[n-1];
            int qto = w - L[n-1];
            if (qfrom < 0 && qto <0)
            {
                d[n].modify(w,m);
                continue;
            }
            qfrom = max(0,qfrom);
            m = max(d[n-1].query(qfrom,qto)+V[n-1],m);
            d[n].modify(w,m);
        }
    }
    ll ans = d[N].query(W,W);
    cout << max(ans,-1LL) << endl;
}
