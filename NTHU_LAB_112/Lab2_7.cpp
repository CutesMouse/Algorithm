#include <iostream>
#include <bitset>
using namespace std;

// M means queens
// N means rocks
int M, N;
int n, ans;
int mask;

int lowbit(int x) {
    return x & -x;
}

void dfs(int C, int QL, int QR, int RL, int RR) {
    if (C == mask) {
        ans++;
        //cout << "VALID, terminate\n";
        return;
    }
    int S = mask & ~(C | QL | QR);
    // placing queens
    if (M) {
        for (int num = 0; S; S ^= num) {
            num = lowbit(S);
            M--;
            dfs(C | num, (QL | num) << 1, (QR | num) >> 1, (RL | num) << 1, (RR | num) >> 1);
            M++;
        }
    }
    S = mask & ~(C | RL | RR);
    // placing rocks
    if (N) {
        for (int num = 0; S; S ^= num) {
            num = lowbit(S);
            N--;
            dfs(C | num, (QL | num) << 1, (QR | num) >> 1, RL << 1, RR >> 1);
            N++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> M >> N;
        if (!M && !N) {
            cout << 0 << "\n";
            continue;
        }
        n = M + N;
        mask = (1 << n) - 1;
        ans = 0;
        dfs(0, 0, 0, 0, 0);
        cout << ans << "\n";
    }
}
