#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int map[4][4];
int D;

void left() {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            int nv = map[r][c];
            for (int ptr = (c + 1); ptr < 4; ptr++) {
                if (map[r][ptr] == nv || map[r][ptr] == 0 || nv == 0) {
                    bool combined = (nv == map[r][ptr] && nv != 0);
                    nv += map[r][ptr];
                    map[r][ptr] = 0;
                    if (combined) break;
                } else break;
            }
            map[r][c] = nv;
        }
    }
}

void right() {
    for (int r = 0; r < 4; r++) {
        for (int c = 3; c >= 0; c--) {
            int nv = map[r][c];
            for (int ptr = (c - 1); ptr >= 0; ptr--) {
                if (map[r][ptr] == nv || map[r][ptr] == 0 || nv == 0) {
                    bool combined = (nv == map[r][ptr] && nv != 0);
                    nv += map[r][ptr];
                    map[r][ptr] = 0;
                    if (combined) break;
                } else break;
            }
            map[r][c] = nv;
        }
    }
}

void up() {
    for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            int nv = map[r][c];
            for (int ptr = (r + 1); ptr < 4; ptr++) {
                if (map[ptr][c] == nv || map[ptr][c] == 0 || nv == 0) {
                    bool combined = (nv == map[ptr][c] && nv != 0);
                    nv += map[ptr][c];
                    map[ptr][c] = 0;
                    if (combined) break;
                } else break;
            }
            map[r][c] = nv;
        }
    }
}

void down() {
    for (int c = 0; c < 4; c++) {
        for (int r = 3; r >= 0; r--) {
            int nv = map[r][c];
            for (int ptr = (r - 1); ptr >= 0; ptr--) {
                if (map[ptr][c] == nv || map[ptr][c] == 0 || nv == 0) {
                    bool combined = (nv == map[ptr][c] && nv != 0);
                    nv += map[ptr][c];
                    map[ptr][c] = 0;
                    if (combined) break;
                } else break;
            }
            map[r][c] = nv;
        }
    }
}

int main() {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cin >> map[r][c];
        }
    }
    cin >> D;
    switch (D) {
        case 0:
            left();
            break;
        case 1:
            up();
            break;
        case 2:
            right();
            break;
        case 3:
            down();
            break;
    }

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cout << map[r][c] << " ";
        }
        cout << endl;
    }
}
