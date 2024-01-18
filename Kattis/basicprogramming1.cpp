#include <iostream>
#include <algorithm>
#define maxn 200000
using namespace std;

int a[maxn];
bool used[maxn] = {0};
int N;

bool iterate(int i = 0) {
    if (i >= N || i < 0) {
        cout << "Out";
        return true;
    }
    if (i == (N-1)) {
        cout << "Done";
        return true;
    }
    if (used[i]) return false;
    used[i] = true;
    return iterate(a[i]);
}

int main() {
    int t;
    cin >> N >> t;
    for (int i = 0; i < N; i++) cin >> a[i];
    long long int s;
    switch (t) {
        case 1:
            cout << 7;
            break;
        case 2:
            if (a[0] > a[1]) cout << "Bigger";
            else if (a[0] == a[1]) cout << "Equal";
            else cout << "Smaller";
            break;
        case 3:
            sort(a, a+3);
            cout << a[1];
            break;
        case 4:
            s = 0;
            for (int i = 0; i < N; i++) s += a[i];
            cout << s;
            break;
        case 5:
            s = 0;
            for (int i = 0; i < N; i++) s += ((a[i]+1) % 2) * a[i];
            cout << s;
            break;
        case 6:
            for (int i = 0; i < N; i++) cout << static_cast<char>('a' + a[i] % 26);
            break;
        case 7:
            if (!iterate()) cout << "Cyclic";
            break;
    }
}
