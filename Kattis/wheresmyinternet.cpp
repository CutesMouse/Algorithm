#include <iostream>

using namespace std;

int boss[200000] = {0};

int query(int a) {
    return boss[a] == a ? a : (boss[a] = query(boss[a]));
}

void link(int a, int b) {
    int qa = query(a);
    int qb = query(b);
    if (qa == qb) return;
    boss[qb] = qa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        boss[i] = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        link(a - 1, b - 1);
    }
    bool connected = true;
    for (int i = 0; i < N; i++) {
        if (query(0) != query(i)) {
            cout << (i+1) << endl;
            connected = false;
        }
    }
    if (connected) cout << "Connected";
}
