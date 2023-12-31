#include <iostream>
#include <vector>
using namespace std;

void loadMatrix(vector<vector<int>> &m, int rows, int cols) {
    int k;
    m.push_back({rows, cols, 0});
    int amt = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> k;
            if (!k) continue;
            amt++;
            m.push_back({r, c, k});
        }
    }
    m[0][2] = amt;
}

void transpose(vector<vector<int>> &m) {
    for (int i = 0; i <= m[0][2]; i++) {
        swap(m[i][0], m[i][1]);
    }
}

void multiplication(vector<vector<int>> &o, vector<vector<int>> &m1, vector<vector<int>> m2) {
    transpose(m2);
    int amt = 0;
    for (int r = 0; r < o[0][0]; r++) {
        for (int c = 0; c < o[0][1]; c++) {
            int val = 0;
            for (vector<int> &i1 : m1) {
                for (vector<int> &i2 : m2) {
                    if (i1[1] != i2[1]) continue;
                    if (i1[0] != r || i2[0] != c) continue;
                    val += i1[2] * i2[2];
                }
            }
            if (!val) continue;
            o.push_back({r, c, val});
            amt++;
        }
    }
    o[0][2] = amt;
}

void print_matrix(vector<vector<int>> &m) {
    int rows = m[0][0];
    int cols = m[0][1];
    vector<vector<int>> normal(rows, vector<int>(cols));
    for (int i = 1; i < m.size(); i++) {
        int r = m[i][0];
        int c = m[i][1];
        int val = m[i][2];
        normal[r][c] = val;
    }
    cout << rows << " " << cols << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << normal[r][c] << " ";
        }
        cout << endl;
    }
}

int main() {
    int frs, fcs;
    int srs, scs;
    vector<vector<int>> m1;
    vector<vector<int>> m2;
    cin >> frs >> fcs;
    loadMatrix(m1, frs, fcs);
    cin >> srs >> scs;
    loadMatrix(m2, srs, scs);
    vector<vector<int>> o;
    o.push_back({frs, scs, 0});
    multiplication(o, m1, m2);
    print_matrix(o);
}
