#include <iostream>
#define int long long int
#define MOD (1000000007)
using namespace std;

int n, M, k;

int m(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int* m(int* a, int* b) {
    int* q = new int[n*n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int flat = r * n + c;
            q[flat] = 0;
            for (int i = 0; i < n; i++) {
                q[flat] = add(q[flat], m(a[r * n + i], b[i * n + c]));
            }
        }
    }
    return q;
}

int* fast_pow(int* a, int b) {
    int* ans = new int[n*n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            ans[r * n + c] = (r == c);
        }
    }
    while (b > 0) {
        if (b & 1) {
            //tmp = m(ans, sqr);
            //delete ans;
            //ans = tmp;
            ans = m(ans, a);
        }
        b >>= 1;
        a = m(a, a);
        /*int* tmp = m(sqr, sqr);
        //delete sqr;
        sqr = tmp;
        tmp = m(ans, sqr);
        //delete ans;
        ans = tmp;*/
    }
    return ans;
}

signed main() {
    cin >> n >> M >> k;
    int matrix[n*n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c <n; c++) {
            matrix[r * n + c] = 0;
        }
    }
    int a, b;
    while (M--) {
        cin >> a >> b;
        matrix[(a-1) * n + (b-1)] += 1;
    }
    int *ans = fast_pow(matrix, k);
    cout << ans[n - 1];
    /*for (int r = 0;; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << ans[r * n + c] << " ";
        }
        cout << endl;
    }*/
}
