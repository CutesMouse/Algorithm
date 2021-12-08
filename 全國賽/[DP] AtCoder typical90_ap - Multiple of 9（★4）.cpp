#include <iostream>
#include <cstring>
#define M 1000000007
using namespace std;
long long int d[100000];
long long int dp(int K)
{
    if (K == 0) return 1;
    if (d[K] != -1) return d[K];
    long long int s = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (K-i < 0) break;
        s += dp(K-i) % M;
    }
    d[K] = s % M;
    return s % M;
}
int main()
{
    int K;
    cin >> K;
    if (K %9)
    {
        cout << "0";
        return 0;
    }
    memset(d,-1,sizeof(d));
    cout << dp(K) << endl;
}
