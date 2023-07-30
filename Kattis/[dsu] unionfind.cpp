#include <iostream>
#include <cstring>

using namespace std;
int boss[1000000];

int query(int a) {
    return boss[a] == a ? a : (boss[a] = query(boss[a]));
}

void link(int a, int b) {
    int q1 = query(a);
    int q2 = query(b);
    if (q1 == q2) return;
    boss[q1] = q2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, Q;
    char j;
    int a, b;
    cin >> N >> Q;
    for (int i = 0; i < N;i ++) {
        boss[i] = i;
    }
    for (int i = 0; i < Q; i++) {
        cin >> j >> a >> b;
        if (j == '?') {
            if (query(a) == query(b)) cout << "yes\n";
            else cout << "no\n";
            continue;
        }
        if (j == '=') {
            link(a, b);
        }
    }
}
