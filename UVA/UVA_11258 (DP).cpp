#include <iostream>
#include <cstring>
using namespace std;
long long *dpi;
//若原字串為 123456789101
//先窮舉所有可能 -> 取最多10個數字
//因為題目限定最大的數字(INT32_MAX)為十位數 如果超出十位數必會大於此數值
//接著窮舉 dp(~1) + 本次計算數據
//找最大值 即可獲得答案
long long dp(int start, string &n) {
    int length = n.length();
    if (dpi[start] != -1) return dpi[start];
    long long grab = 0;
    long long maxV = 0;
    for (int i = 0; i < 10; i++) {
        if (start+i >= length) break;
        grab = grab * 10 + (n.at(start+i) - '0');
        if (grab > 2147483647) break;
        long long current = grab + dp(start+i+1,n);
        maxV = max(current,maxV);
    }
    dpi[start] = maxV;
    return dpi[start];
}
int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        int length = s.length();
        dpi = new long long[length+1];
        memset(dpi,-1,sizeof(long long) * (length+1));
        cout << dp(0,s) << endl;
        delete [] dpi;
    }
}
