#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
int n, ans;
int mask;
int barrier[8];

void input() {
    string buffer;
    for (int i = 0; i < 8; i++) {
        cin >> buffer;
        for (int j = 0; j < 8; j++) {
            if (buffer[j] == '*') {
                barrier[i] |= (1 << j);
            }
        }
    }
}

int lowbit(int x) {
    return x & -x;
}

void dfs(int M, int L, int R, int depth) {
    if (M == mask) {
        ans++;
        return;
    }
    int S = mask & ~(L | M | R | barrier[depth]);
    for (int num = 0; S; S ^= num) {
        num = lowbit(S);
        dfs(M | num, (L | num) << 1, (R | num) >> 1, depth+1);
    }
}

int main() {
    ans = 0, n = 8;
    input();
    mask = (1 << n) - 1;
    dfs(0, 0, 0, 0);
    cout <<ans;
}
