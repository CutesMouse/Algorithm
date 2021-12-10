#include <iostream>
#include <vector>
#include <cstring>
#define gA true
#define gB false
using namespace std;
int A[100],B[100];
bool d[100][100000];
bool used[100][100000];
pair<int,int> to[100][100000];
bool choose[100][100000];
bool dp(int N,int S)
{
    if (N == -1 && S == 0)
    {
        to[N][S] = {-1,-1};
        return true;
    }
    if (N <= -1 ||S < 0)
    {
        return false;
    }
    
    if (used[N][S]) return d[N][S];
    bool getA = dp(N-1,S-A[N]);
    bool getB = dp(N-1,S-B[N]);
    used[N][S] = true;
    if (getA)
    {
        d[N][S] = getA;
        choose[N][S] = gA;
        to[N][S] = {N-1,S-A[N]};
        return getA;
    }
    d[N][S] = getB;
    choose[N][S] = gB;
    to[N][S] = {N-1,S-B[N]};
    return getB;
}
void trace(int N, int S)
{
    auto inf = to[N][S];
    if (inf.first != -1) trace(inf.first,inf.second);
    cout << (choose[N][S] ? "A" : "B");
}
int main()
{
    memset(used,0,sizeof(used));
    int N,S;
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
    bool result = dp(N-1,S);
    if (result)
    {
        trace(N-1,S);
        cout << endl;
    }
    else
    {
        cout << "Impossible\n";
    }
}
