#include <iostream>
using namespace std;
int N,K,A[605];
bool ok(int mx_dis)
{
    int tmp = 0;
    int night = K;
    for (int i = 0; i <= N; i++)
    {
        tmp += A[i];
        if (night < 0) break;
        if (tmp > mx_dis)
        {
            tmp = 0;
            night--;
            i--;
        }
    }
    return night >= 0;
}
int bs(int from, int to)
{
    int ans = -1;
    while (to >= from)
    {
        int mid = (from+to) >> 1;
        if (ok(mid))
        {
            ans = mid;
            to = mid-1;
        }
        else
        {
            from = mid+1;
        }
    }
    return ans;
}
int main()
{
    while(cin >>N >>K)
    {
        int sum = 0;
        int mx = 0;
        for (int i = 0; i <=N; i++)
        {
            cin >> A[i];
            sum += A[i];
            mx = max(mx,A[i]);
        }
        cout << bs(mx,sum) << endl;
    }
}
