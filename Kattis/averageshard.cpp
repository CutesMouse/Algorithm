#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int T, CS, E;
    int iCS[200000], iE[200000];
    cin >> T;
    while (T--) {
        cin >> CS >> E;
        double cs_avg = 0, e_avg = 0;
        for (int i = 0; i < CS; i++) {
            cin >> iCS[i];
            cs_avg += iCS[i] / (double) CS;
        }
        for (int i = 0; i < E; i++) { 
            cin >> iE[i];
            e_avg += iE[i] / (double) E;
        }
        sort(iCS, iCS+CS);
        int ans = 0;
        for (int i = 0; i < CS; i++) {
            ans += (iCS[i] < cs_avg && iCS[i] > e_avg);
        }
        cout << ans << endl;
    }
}
