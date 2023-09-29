#include <iostream>
#include <cstring>
using namespace std;

int grid[9][9];

int row_check[9];
int col_check[9];
int blk_check[3][3];

void update(int r, int c, int num) {
    row_check[r] ^= num;
    col_check[c] ^= num;
    blk_check[r/3][c/3] ^= num;
}

void print() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            // __lg(int) 輸出第一個1的位元數(最右邊為第0位元), 即log2(int)的整數部分
            cout << __lg(grid[r][c]);
        }
    }
    cout << '\n';
}

bool ok() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (!grid[r][c]) return false;
        }
    }
    return true;
}

bool input(string buffer) {
    for (int idx = 0; idx < 81; idx++) {
        int r = idx / 9, c = idx % 9;
        if (buffer[idx] == '.') grid[r][c] = 0;
        else {
            // 假如數字是1, grid會存 0000000010
            // 假如數字是5, grid會存 0000100000
            grid[r][c] = (1 << (buffer[idx] - '0'));
            if ((row_check[r] | col_check[c] | blk_check[r/3][c/3]) & grid[r][c]) return false;
            update(r, c, grid[r][c]);
        }
    }
    return true;
}

// 取得一個只有最右邊bit的新整數
// 若x為0001111000, 則會回傳 0000001000
int lowbit(int x) {
    return x & -x;
}

// 產生一個 000011111111110 的INT
// 前面的0用來消除 NOT 運算後多餘的位元
// 後面的0用來解決最後一個BIT沒用到的問題
const int MASK = (1<<10) - 2;
bool dfs(int idx) {
    if (idx == 81) {
        return true;
    }
    int r = idx / 9, c = idx % 9;
    if (grid[r][c]) return dfs(idx+1);
    int S = MASK & ~(row_check[r] | col_check[c] | blk_check[r / 3][c / 3]);
    for (int num = 0; S; S ^= num) {
        num = lowbit(S);
        grid[r][c] = num;
        update(r, c, num);
        if (dfs(idx+1)) return true;
        update(r, c, num);
    }
    grid[r][c] = 0;
    return false;
}

int main() {
    string io;
    while (getline(cin, io) && io[0] != 'e') {
        memset(row_check, 0, sizeof(row_check));
        memset(col_check, 0, sizeof(col_check));
        memset(blk_check, 0, sizeof(blk_check));
        if (input(io) && dfs(0)) print();
        else cout << "No solution.\n";
    }
}
