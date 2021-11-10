#include <iostream>
#include <cstring>
using namespace std;
int N,K;
int p[10009];
bool d[10009][105];
bool dp(int index) {
    d[0][p[0]%K] = true;
    d[0][(-1*p[0])%K] = true;
    
    for (int i = 1 ; i <= index; i++) {
        for (int q = 0; q < K; q++) {
            if (d[i-1][q]) {
                int nl = (p[i] + q) %K;
                int nr = (-1*p[i] + q) %K;
                d[i][nl] = true;
                d[i][nr] = true;
            }
        }
    }
    return d[index][0];
}

int main() {
    int r;
    cin >> r;
    for (int o = 0; o < r ; o++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) cin >> p[i];
        memset(d,0,sizeof(d));
        if (dp(N-1)) {
            cout << "Divisible\n";
        } else cout << "Not divisible\n";
    }
    return 0;
}
