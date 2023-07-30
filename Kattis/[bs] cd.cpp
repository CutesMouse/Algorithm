#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == M && N == 0) return 0;
        vector<int> cds;
        int tot = 0;
        int j;
        for (int i = 0; i < N; i++) {
            cin >> j;
            cds.push_back(j);
        }
        int cd;
        for (int i = 0; i < M; i++) {
            cin >> cd;
            int target = *lower_bound(cds.begin(), cds.end(), cd);
            tot += (target == cd);
        }
        cout << tot << endl;
    }
}
