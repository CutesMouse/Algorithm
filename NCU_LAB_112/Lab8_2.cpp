#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please input the size of the Bingo board: \n";
    cin >> n;
    bool bingo[n][n] = {0};
    int table[n][n] = {0};
    cout << "Please input the Bingo board: \n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> table[r][c];
        }
    } 
    cout << "Please input the size of Bingo number: \n";
    int p;
    cin >> p;
    cout << "Please input the Bingo number: \n";
    for (int i = 0; i < p; i++) {
        int k;
        cin >> k;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (table[r][c] == k) bingo[r][c] = true;
            }
        } 
    }
    int ans = 0;
    //row
    for (int r = 0; r < n; r++) {
        bool line = true;
        for (int c = 0; c < n; c++) {
            line &= bingo[r][c];
        }
        ans += line;
    }
    //column
    for (int c = 0; c< n; c++) {
        bool line = true;
        for (int r = 0; r < n; r++) {
            line &= bingo[r][c];
        }
        ans += line;
    }
    //horizon
    bool left_line = true;
    bool right_line = true;
    for (int i = 0; i < n; i++) {
        left_line &= bingo[i][i];
        right_line &= bingo[n-1-i][i];
    }
    ans += left_line;
    ans += right_line;
    printf("The number of connections is %d", ans);
}
