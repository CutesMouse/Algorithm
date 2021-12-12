#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int arr[9] = {10,9,2,5,3,7,101,18,20};
int s[9];
// BS版LIS，複雜度O(NlogN)
int main()
{
    int N = 9;
    int m = 0;
    // 暫存的子序列，裡面保證遞增
    vector<int> lis;
    for (int i = 0; i < N; i++) {
        // 尋找暫存子序列中，最小，比a[i]大的數字的位置指標
        // 舉例: 2、5、7、9，lower_bound(6)
        // 可得到陣列中 5 所在的指標
        // 但若輸入10 則會回傳陣列的end
        auto ptr = lower_bound(lis.begin(),lis.end(),arr[i]);
        // 如果找不到(回傳end)，則在lis最後面添加元素
        if (ptr == lis.end()) lis.emplace_back(arr[i]);
        // 如果找到了 替換掉該元素 讓後面的元素有更多空間
        else *ptr = arr[i];
        s[i] = lis.size();
    }
    // 要注意，lis並不等於實際的最長遞增子序列
    // 而只是一個暫存、計算數量的子序列
    // 回朔請參考以下程式碼
    
    // 回朔
    // 概念: 得到的S如下(遞增)
    // 1 1 1 2 2 3 4 4 5
    // 已知最長為5，則由後往前找
    // 先找到長度為5的位置，得到20
    // 再往前找到長度為4的位置，得到18
    // 再往前找長度為3的位置，得到7
    // 一直往前直到長度為1，可依序得到20、18、7、3、2
    // 逆轉後即可得到答案
    int L = lis.size();
    vector<int> ans;
    for (int i = N-1; i >= 0; i--) {
        if (s[i] == L) {
            ans.emplace_back(arr[i]);
            L--;
        }
    }
    for (auto iter = ans.rbegin(); iter != ans.rend(); iter++) cout << *iter << " ";
}
