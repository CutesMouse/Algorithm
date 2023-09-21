#include <iostream>
#include <cmath>
using namespace std;

long long int minx = -1;
int n;
long long p[20];

void dfs(int depth, long long int left, long long int right) {
    if (depth == n) {
        if (minx == -1) minx = abs(left-right);
        minx = min(minx, abs(left-right));
        return;
    }
    dfs(depth+1, left + p[depth], right);
    dfs(depth+1, left, right + p[depth]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    dfs(0, 0, 0);
    cout << minx;
}
