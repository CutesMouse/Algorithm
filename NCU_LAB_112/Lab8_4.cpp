#include <iostream>
using namespace std;

int maze[100][100];
int seq[100];
int ms, l;

enum direction {
    DOWN, UP, LEFT, RIGHT,
    D1, D2, D3, D4
};

int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

bool line(int r, int c, direction dir, int index) {
    if (index == l) return true;
    if (r >= ms || c >= ms) return false;
    if (maze[r][c] != seq[index]) return false;
    return line(r + dx[dir], c + dy[dir], dir, index+1);
}

int main() {
    cout << "Please input the size of the number maze map: \n";
    cin >> ms;

    cout << "Please input the number maze map: \n";
    for (int r = 0; r < ms; r++) {
        for (int c = 0; c <ms; c++) {
            cin >> maze[r][c];
        }
    }
    cout << "Please input the size of the number sequence: \n";
    cin >> l;
    cout << "Please input the number sequence: \n";
    for (int i = 0; i < l; i++) cin >> seq[i];
    int ans = 0;
    for (int r = 0; r < ms; r++) {
        for (int c = 0; c <ms; c++) {
            ans += line(r, c, UP, 0);
            ans += line(r, c, DOWN, 0);
            ans += line(r, c, LEFT, 0);
            ans += line(r, c, RIGHT, 0);
            ans += line(r, c, D1, 0);
            ans += line(r, c, D2, 0);
            ans += line(r, c, D3, 0);
            ans += line(r, c, D4, 0);
        }
    }
    printf("The number of number sequences is %d", ans);
}
