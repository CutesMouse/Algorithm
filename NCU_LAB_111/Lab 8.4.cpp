#include <iostream>
#include <vector>
using namespace std;

int W,L;
vector< vector<bool> > ary;

bool is_filled(int r1, int r2, int c1, int c2) {
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            if (!ary[r][c]) return false;
        }
    }
    return true;
}

int main(){
    cout << "Please enter the size of the binary matrix: \n";
    cin >> W >> L;
    cout << "Please input the array: \n";
    ary.resize(W);
    int k;
    for (int row = 0; row < W; row++) {
        for (int col = 0; col < L; col++) {
            cin >> k;
            ary[row].emplace_back(k);
        }
    }

    int mx_area = 0;
    int mc = 0, mr = 0;

    for (int r1 = 0; r1 < W; r1++) {
        for (int r2 = r1; r2 < W; r2++) {
            for (int c1 = 0; c1 < L; c1++) {
                for (int c2 = c1; c2 < L; c2++) {
                    if (is_filled(r1,r2,c1,c2)) {
                        int area = (r2-r1+1) * (c2-c1+1);
                        if (area > mx_area) {
                            mx_area = area;
                            mc = c2 - c1 + 1;
                            mr = r2 - r1 + 1;
                        }
                    }
                }
            }
        }
    }
    cout << "Answer: "<<mx_area<<"\n";
    cout << "Width: "<<min(mr,mc)<<" Length: " << max(mc,mr);
}
