#include <iostream>
#include <vector>

using namespace std;

int W, L;
vector<vector<bool> > ary;

int main() {
    //cout << "Please enter the size of the binary matrix: \n";
    while(cin >> W >> L) {
        //cout << "Please input the array: \n";
        ary.resize(0);
        int k;
        for (int row = 0; row < W; row++) {
            vector<bool> vr;
            for (int col = 0; col < L; col++) {
                cin >> k;
                vr.push_back(k);
            }
            ary.push_back(vr);
        }

        vector<vector<int> > res(W);
        for (int i = 0; i < W; i++) res[i].resize(L, 0);


        for (int row = 0; row < W; row++) {
            for (int col = 0; col < L; col++) {
                if (row == 0) res[row][col] = ary[row][col];
                else if (ary[row][col] != 0) {
                    res[row][col] = res[row - 1][col] + ary[row][col];
                }
            }
        }

        int mx_area = 0;
        int w = 0, l = 0;

        /*for (int row = 0; row < W; row++) {
            for (int col = 0; col < L; col ++) {
                cout << res[row][col] << " ";
            }
            cout << endl;
        }*/

        for (int row = 0; row < W; row++) {
            for (int col = 0; col < L; col++) {
                int mn = 1000;
                for (int i = col; i < L; i++) {
                    mn = min(res[row][i], mn);
                    int area = mn * (i - col + 1);
                    if (area > mx_area) {
                        //if (area == 18) cout << row << ", " << col << ", " << i << endl;
                        mx_area = area;
                        w = mn;
                        l = i - col + 1;
                    }
                }
            }
        }
        cout << mx_area << "\n";
    }
}
