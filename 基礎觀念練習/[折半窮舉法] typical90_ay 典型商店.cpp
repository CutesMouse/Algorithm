#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
int N,K;
ll P;
ll A[40];
vector<ll> lt[40],rt[40];
void dfs(int picked, int ptr, ll money, int q, vector<ll> *d)
{
    //金錢超過限制
    if (money > P) return;
    //取得的個數超過限制
    if (picked > K) return;
    //窮舉盡頭
    if (ptr == q)
    {
        d[picked].emplace_back(money);
        return;
    }
    //取或不取，往下遞迴
    dfs(picked+1,ptr+1,money+A[ptr],q,d);
    dfs(picked,ptr+1,money,q,d);
}
int main()
{
    cin >> N >> K >> P;
    for (int i = 0; i < N; i++) cin >> A[i];
    dfs(0,0,0,N/2,lt);//左半窮舉
    dfs(0,N/2,0,N,rt);//右半窮舉
    //排序方便二分搜
    for (int i = 0; i < K; i++)
    {
        sort(lt[i].begin(),lt[i].end());
        sort(rt[i].begin(),rt[i].end());
    }
    ll ans = 0;
    //lc: 使用前N/2個元素的個數
    for (int lc = 0; lc <= K; lc++)
    {
        //rc: 使用N/2+1到N裡元素的個數
        int rc = K - lc;
        //從使用lc個的結果去推，這裡是左半邊的資料
        for (auto iter = lt[lc].begin(); iter != lt[lc].end(); iter++)
        {
            // lower_bound 求最大小於n的元素的指標

            // rt[rc] 右半邊使用rc個元素的集合
            // P - (*iter)+1) 左半邊使用lc個元素的其中一種方式所用的花費為 iter
            // 舉隅: 2,3,5,7，使用三種元素的情況可能有 10,15 這兩種(上方第31行可表示已排序)
            // 這樣iter窮舉的就是 10、15 這兩個數值
            // 所以可用的金錢還有 P - (*iter)
            // 現在要求的是，在已排序的陣列rt[rc]中，小於或等於 P - (*iter) 的個數
            // 由於lower_bound求的是「小於」的最大值，為了包含等於的情況，要將數值+1
            // 然後減掉指標的起始點，求得個數
            ll amount = lower_bound(rt[rc].begin(),rt[rc].end(),P - (*iter)+1) - rt[rc].begin();
            ans += amount;
        }
    }
    cout << ans <<endl;
}
