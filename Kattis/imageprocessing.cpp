#include <iostream>

using namespace std;


int main() {
    int w = 4, h = 4;
    int m = 2, n = 2;
    cin >> h >> w >> n >> m;
    int nw = w - m + 1;
    int nh = h - n + 1;
    int bigger_matrix[20][20];
    int multiply[20][20];
    int n_matrix[nh][nw];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> bigger_matrix[i][j];
        }
    }

    for (int i = n-1; i >=0; i--) {
        for (int j = m-1; j >= 0; j--) {
            cin >> multiply[i][j];
        }
    }

    for (int i = 0; i < nh; i++) {
        for (int j = 0; j < nw; j++) {
            n_matrix[i][j] = 0;
            for (int ph = 0; ph < n; ph++) {
                for (int pw = 0; pw < m; pw++) {
                    n_matrix[i][j] += bigger_matrix[i+ph][j+pw] * multiply[ph][pw];
                }
            }
        }
    }

    for (int i = 0; i < nh; i++) {
        for (int j = 0; j < nw; j++) {
            cout << n_matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
