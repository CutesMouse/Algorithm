#include <iostream>
#include <fstream>
using namespace std;

bool checkraw(int (*sudoku)[9], int r, int c, int num) {
    for (int nc = 0; nc < 9; nc++) {
        if (nc == c) continue;
        if (sudoku[r][nc] == num) return false;
    }
    return true;
}

bool checkcol(int (*sudoku)[9], int r, int c, int num) {
    for (int nr = 0; nr < 9; nr++) {
        if (nr == r) continue;
        if (sudoku[nr][c] == num) return false;
    }
    return true;
}

bool checkblock(int (*sudoku)[9], int r, int c, int num) {
    int br = r / 3;
    int bc = c / 3;
    for (int dr = 0; dr < 3; dr++) {
        for (int dc = 0; dc < 3; dc++) {
            if (br*3+dr == r && bc*3+dc == c) continue;
            if (sudoku[br*3+dr][bc*3+dc] == num) return false;
        }
    }
    return true;
}

bool isFinish(int (*sudoku)[9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (!sudoku[r][c]) return false;
        }
    }
    return true;
}

//dfs
bool solve_sudoku(int (*sudoku)[9]) {
    if (isFinish(sudoku)) return true;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (sudoku[r][c]) continue;
            //printf("solve: %d, %d\n", r, c);
            for (int i = 0; i < 9; i++) {
                if (checkraw(sudoku, r, c, i+1) && checkcol(sudoku, r, c, i+1) && checkblock(sudoku, r, c, i+1)) {
                    sudoku[r][c] = i+1;
                    if (solve_sudoku(sudoku)) return true;
                    sudoku[r][c] = 0;
                }
            }
            return false;
        }
    }
    return false;
}

void print_sudoku(int (*sudoku)[9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (sudoku[r][c]) cout << sudoku[r][c];
            else cout << ".";
        }
        cout << endl;
    }
}

string getOutputFile(string input) {
    string ins = "_out";
    int index = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '.') index = i;
    }
    return input.substr(0, index) + ins + input.substr(index);
}

int main() {
    int sudoku[9][9];
    ifstream in;
    ofstream out;
    string file;
    while (true) {
        cout << "Please enter the input file name: ";
        cin >> file;
        in.open(file);
        if (in) break;
        cout << "File could not be opened.\n";
    }
    out.open(getOutputFile(file));
    char c;
    int iter = 0;
    while (in >> c) {
        if (c >= '0' && c <= '9' || c == '.') {
            sudoku[iter/9][iter%9] = (c == '.' ? 0 : c - '0');
            iter++;
        }
    }
    print_sudoku(sudoku);
    solve_sudoku(sudoku);
    cout << endl;
    print_sudoku(sudoku);
    for (int r = 0; r < 9; r++) {
        if (r == 3 || r == 6) out << "---------+----------+---------\n";
        for (int c = 0; c < 9; c++) {
            if (c == 3 || c == 6) out << "| ";
            out << sudoku[r][c];
            if (c != 8) out << "  ";
        }
        out << endl;
    }
    out.close();
}
