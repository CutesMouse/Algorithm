#include <iostream>
using namespace std;
int main() {
    // 最大區間和
    int ary[10] = {2,-3,4,-1,-2,1,5,-3,1,1};
    // 最大和(可選0個元素，因此最少為0)
    int mx = 0;
    
    // 以第i個數為結尾時，總和為 dp[i]
    // ex. 以上ary例而言，dp[1] = 2, dp[2] = -1
    int dp[11];
    
    // 以第0個元素為結尾時，總和為0
    dp[0] = 0;
    
    for (int i = 1;i <= 10; i++) {
        // 第i個數為結尾的最大值為: max(前i-1個數的最大值+第i個數, 第i個數)
        // 原理: 如果前項比當前項還要小，就重新開始陣列，重新開始計算
        dp[i] = max(dp[i-1]+ary[i-1],ary[i-1]);
        // 最大連續和為dp陣列中最大的元素
        mx = max(dp[i],mx);
    }
    
    cout <<mx;
}
