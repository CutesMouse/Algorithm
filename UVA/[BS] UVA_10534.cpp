#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,A[10000];
void lis(int *d, int st, int dx)
{
    vector<int> tmp;
    for (int i = st; i < N && i >= 0; i += dx)
    {
        auto ptr = lower_bound(tmp.begin(),tmp.end(),A[i]);
        if (ptr == tmp.end()) tmp.emplace_back(A[i]);
        else *ptr = A[i];
        d[i] = tmp.size();
    }
}
int main()
{
    int lt[10000],rt[10000];
    while(cin >>N)
    {
        for (int i = 0; i <N; i++) cin >> A[i];
        lis(lt,0,1);
        lis(rt,N-1,-1);
        int mx = 1;
        for (int i = 0; i < N; i++)
        {
            if (lt[i] == rt[i]) mx = max(mx,lt[i]*2-1);
        }
        cout <<mx << endl;
    }
}
