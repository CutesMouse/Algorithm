#include <iostream>
#include <vector>
using namespace std;
int N;
int A[300000];
int ft[300000];
int bt[300000];
void lis(int *ary, int st, int dn)
{
    vector<int> l;
    for (int i = st; i >= 0 && i < N; i += dn)
    {
        auto iter = lower_bound(l.begin(),l.end(),A[i]);
        if (iter == l.end())
        {
            l.emplace_back(A[i]);
        }
        else *iter = A[i];
        ary[i] = l.size();
    }
}

int main()
{
    cin >>N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    lis(ft,0,1);
    lis(bt,N-1,-1);
    int m = 0;
    for (int i = 0; i < N; i++)
    {
        m = max(ft[i]+bt[i],m);
    }
    cout <<m-1;
}
