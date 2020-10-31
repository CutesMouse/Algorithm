#include <iostream>
#include <cstring>
using namespace std;

long long** dpi;
// 查看結尾 如果結尾是1 -> last就儲存為true
// 如果last為false 就把所有含有1的情況都加入進去
// 否之就只加入含有0的情況
long long dp(int pos, bool last, int length) {
    if (pos == length) return 1;
    if (dpi[pos][last]) return dpi[pos][last];
    long long ans = 0;
    if (!last) {
        ans += dp(pos+1,true,length);
    }
    ans += dp(pos+1,false,length);
    dpi[pos][last] = ans;
    return ans;
}
int main() {
    int n;
    int cpn;
    cin >> n;
    cpn = n;
    while (n--) {
        int length;
        cin >> length;
        dpi = new long long*[length];
        for (int i = 0 ; i < length; i++) {
            dpi[i] = new long long[2];
            memset(dpi[i],0,sizeof(long long)*2);
        }
        cout << "Scenario #"<<(cpn-n) << ":" << endl;
        cout << dp(0,false,length) << endl << endl;
    }
}
