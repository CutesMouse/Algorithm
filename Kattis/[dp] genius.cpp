#include <iostream>
#include <iomanip>
using namespace std;


int weight[4];

double winrate(int w1, int w2, int player) {
    double base = 1.0 / (w1 + w2);
    return (player ? w2 * base : w1 * base);
}

double winrate_all(int player) {
    if (player == 0 || player == 1) {
        return winrate(weight[0], weight[1], player) * (winrate(weight[2], weight[3], 0) * winrate(weight[player], weight[2], 0) + winrate(weight[2], weight[3], 1) * winrate(weight[player], weight[3], 0));
    }
    return winrate(weight[2], weight[3], player-2) * (winrate(weight[0], weight[1], 0) * winrate(weight[player], weight[0], 0) + winrate(weight[0], weight[1], 1) * winrate(weight[player], weight[1], 0));

} 

int main() {
    int k, t, p, q, x;
    double rate[100];
    cin >> k >> t >> p >> q >> x;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 4; j++) cin >> weight[j];
        int w = x % 4;
        rate[i] = winrate_all(w);
        x = (x * p) % q;
    }
    //test
    /*rate[0] = 0.2;
    rate[1] = 0.3;
    rate[2] = 0.4;
    t = 3;
    k = 2;*/
    double r[101][101] = {0};
    r[0][0] = 1;
    //r[1][0] = (1 - rate[0]);
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= t; j++) {
            //r[i][j] += r[i-1][j] * (1 - rate[i-1]);
            //r[i][j+1] += r[i-1][j] * rate[i-1];
            if (j == 0) r[i][j] = (1-rate[i-1]) * r[i-1][j];
            else r[i][j] = rate[i-1] * r[i-1][j-1] + (1-rate[i-1]) * r[i-1][j];
        }
    }
    double ans = 0;
    for (int i = k; i <= t; i++) ans += r[t][i];
    cout << fixed << setprecision(8) << ans;
}
