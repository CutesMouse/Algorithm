#include <iostream>
#include <vector>

using namespace std;

int N;

vector<vector<int> > sudoku;

bool find_empty_blank(int &col, int &row) {
    for (int c = 0; c < N; c++) {
        for (int r = 0; r < N; r++) {
            if (!sudoku[c][r]) {
                col = c;
                row = r;
                return true;
            }
        }
    }
    return false;
}

bool valid_input(int col, int row, int num) {
    for (int r = 0; r < N; r++) {
        if (sudoku[col][r] == num) return false;
        if (sudoku[r][row] == num) return false;
    }
    int bc = (col / 3) * 3;
    int br = (row / 3) * 3;
    for (int dr = 0; dr < 3; dr++) {
        for (int dc = 0; dc < 3; dc++) {
            if (sudoku[bc + dc][br + dr] == num) return false;
        }
    }
    return true;
}

bool solve() {
    int col, row;
    if (!find_empty_blank(col, row)) return true;
    for (int i = 1; i <= N; i++) {
        if (!valid_input(col, row, i)) continue;
        sudoku[col][row] = i;
        if (solve()) return true;
        sudoku[col][row] = 0;
    }
    return false;
}


void print_sudoku() {
    for (int c = 0; c < N; c++) {
        /*if (c == 3 || c == 6) {
            cout << "--------------------\n";
        }*/
        for (int r = 0; r < N; r++) {
            //if (r == 3 || r == 6) cout << "| ";
            cout << sudoku[c][r] << " ";
        }
        cout << endl;
    }
}

int main() {
    while (cin >> N) {
        N *= 3;
        sudoku.resize(N);
        for (int i = 0; i < N; i++) {
            sudoku[i].resize(N);
        }
        for (int c = 0; c < N; c++) {
            for (int r = 0; r < N; r++) {
                cin >> sudoku[c][r];
            }
        }
        if (solve()) print_sudoku();
        else cout << "NO SOLUTION";
    }
}
