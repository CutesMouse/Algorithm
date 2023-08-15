#include <iostream>
using namespace std;

int locate(long long int n, long long int x, long long int y) {
    if (n == 1) return 1;
    long long int hn = n / 2;
    if (x >= hn && y >= hn) return -locate(hn, x - hn, y - hn);
    if (x >= hn) return locate(hn, x - hn, y);
    if (y >= hn) return locate(hn, x, y - hn);
    return locate(hn, x, y); 
}

int main() {
    int k;
    cin >> k;
    long long int n, x, y;
    int w, h;
    while (k--) {
        cin >> n >> y >> x >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << locate(n, x + i, y + j) << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}
