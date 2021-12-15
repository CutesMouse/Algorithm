#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int N,Q,T[100005],X[100005],Y[100005],V[100005], dsj[100005];
map<int,long long int> sum;
int k[100005];
void bond(int a, int b);
bool is_bond(int a, int b);

long long int g_sum(int from, int to)
{
    return sum[to] - sum[from-2];
}

int main()
{
    memset(dsj,-1,sizeof(dsj));
    memset(k,0,sizeof(k));
    cin >> N >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        if (T[i]) continue;
        k[X[i]] = V[i];
    }
    long long int es = 0, os = 0;

    for (int i = 0; i < N; i++)
    {
        if (i%2)
        {
            os += k[i];
            sum[i] = os;
        }
        else
        {
            es += k[i];
            sum[i] = es;
        }
    }

    for (int i = 0; i < Q; i++)
    {
        if (!T[i])
        {
            bond(X[i],Y[i]);
            continue;
        }
        if (!is_bond(X[i],Y[i]))
        {
            cout << "Ambiguous\n";
            continue;
        }
        int x = X[i];
        int y = Y[i];
        long long int ans = ((x-y) % 2) ? -V[i] + g_sum(x,y-1) - g_sum(x+1,y-2) :
                            V[i] - g_sum(x,y-2) + g_sum(x+1,y-1);
        cout <<ans << "\n";
    }

}

int get_root(int a)
{
    if (dsj[a] == -1) return a;
    return dsj[a] = get_root(dsj[a]);
}

bool is_bond(int a, int b)
{
    return get_root(a) == get_root(b);
}

void bond(int a, int b)
{
    if (is_bond(a,b)) return;
    dsj[a] = b;
}
