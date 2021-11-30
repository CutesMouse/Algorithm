#include <iostream>
#define MOD 1000000007
using namespace std;
long long int mul(long long int a, long long int b)
{
    return (a%MOD) * (b %MOD) % MOD;
}
long long int mul_pow(long long int i, long long int k)
{
    if (i <= 1) return k;
    //cout << "i: " << i << endl;
    long long int half = mul_pow(i/2,k);
    if (i%2)
    {
        return mul(mul(half,half),k);
    }
    return mul(half,half);
}
int main()
{
    // K * (k-1) * (k-2)...
    long long int N;
    long long int K;
    cin >> N >> K;
    if (N == 1)
    {
        cout << K %MOD << endl;
        return 0;
    }
    if (N == 2)
    {
        cout << mul(K,(K-1)) << endl;
        return 0;
    }
    long long int r = mul(K,(K-1));
    cout <<mul(mul_pow(N-2,K-2),r)<< endl;
}
