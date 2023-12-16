#include <iostream>
#define INF (1LL<<32)
#define int long long int
using namespace std;

int N, M, K;

//�ba�����Rb���~�ɪ���O
int b[101][1001] = {0};
//�ba������b���~�ɪ��ұo
int s[101][1001] = {0};
//�{��x�}
int w[101][101] = {0};
//�b����a�R�J�B�b����b�汼���̰���Q
int profit[101][101] = {0};

void floyd(int d[101][101]) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

bool is_legal(int profit_ratio) {
    int check[101][101] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            check[i][j] = profit_ratio * min(w[i][j], INF / profit_ratio) - profit[i][j];
        }
    }
    floyd(check);
    for (int i = 0; i < N; i++) {
        if (check[i][i] <= 0) return true;
    }
    return false;
}

template<class Ty, class FuncTy>
pair<Ty, Ty> bs(Ty L, Ty R, FuncTy check) {
    if (check(L) == false) return {L-1, L};
    if (check(R) == true) return {R, R+1};
    while (L + 1 < R) {
        Ty mid = L + (R - L) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    return {L, R};
}

signed main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) cin >> b[i][j] >> s[i][j];
    }
    int from, to, weight;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            w[i][j] = INF;
            //profit[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> weight;
        w[from-1][to-1] = weight;
    }
    floyd(w);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < K; k++) {
                if (b[i][k] == -1 || s[j][k] == -1) continue;
                profit[i][j] = max(profit[i][j], s[j][k] - b[i][k]);
            }
        }
    }
    cout << bs(1LL, INF, is_legal).first;
}
