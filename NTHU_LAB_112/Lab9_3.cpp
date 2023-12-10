#include <iostream>
#define INF (1L<<60)
using namespace std;

int main() {
    typedef long long int ll;
    ll n, m, q, a, b, c;
    cin >> n >> m >> q;
    ll d[501][501];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = (i != j) * INF;
        }
    }
    while (m--) {
        cin >>a >> b>> c;
        c = min(c, d[a][b]);
        d[a][b] = d[b][a] = c;
    }

    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    while (q--) {
        cin >> a >> b;
        if (d[a][b] == INF) cout << -1 << endl;
        else cout << d[a][b] << endl;
    }
}
