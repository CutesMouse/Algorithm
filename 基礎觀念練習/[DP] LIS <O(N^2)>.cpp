#include <iostream>
#include <cstring>
using namespace std;
int arr[9] = {10,9,2,5,3,7,101,18,20};
int dp[9];
// DP版LIS，複雜度O(N^2)
int main()
{
    int N = 9;
    memset(dp,0,sizeof(dp));
    // DP[i]: 序列中從0~i中，包含i的最小遞增子序列
    for (int i = 0; i < N; i++)
    {
        int m = 0;
        // 窮舉0~i-1，如果a[j]<a[i]，表示j可以放在i前面(遞增)
        // 要選最大，因此挑選0~i-1中，最大的子序列
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i]) m = max(dp[j],m);
        }
        // 包含自身，因此要+1
        dp[i] = m+1;
    }

    for (int i= 0 ; i < N; i++) cout << dp[i] << " ";
}
