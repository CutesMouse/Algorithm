#include <iostream>
#include <queue>
using namespace std;

void generateBombs(char (*board)[8], int num) {
    if(num % 5 == 0) {
        board[0][0] = 'B';
        board[0][2] = 'B';
        board[0][7] = 'B';
        board[1][4] = 'B';
        board[2][2] = 'B';
        board[2][4] = 'B';
        board[3][0] = 'B';
        board[6][1] = 'B';
        board[6][6] = 'B';
        board[7][3] = 'B';
    } else if(num % 5 == 1) {
        board[0][2] = 'B';
        board[2][1] = 'B';
        board[2][6] = 'B';
        board[3][1] = 'B';
        board[3][2] = 'B';
        board[4][6] = 'B';
        board[5][0] = 'B';
        board[6][3] = 'B';
        board[6][5] = 'B';
        board[6][7] = 'B';
    } else if(num % 5 == 2) {
        board[0][2] = 'B';
        board[0][6] = 'B';
        board[1][2] = 'B';
        board[2][4] = 'B';
        board[4][3] = 'B';
        board[4][4] = 'B';
        board[4][6] = 'B';
        board[5][6] = 'B';
        board[6][6] = 'B';
        board[7][6] = 'B';
    } else if(num % 5 == 3) {
        board[0][1] = 'B';
        board[0][4] = 'B';
        board[1][5] = 'B';
        board[1][7] = 'B';
        board[2][0] = 'B';
        board[3][7] = 'B';
        board[6][0] = 'B';
        board[6][3] = 'B';
        board[6][4] = 'B';
        board[7][4] = 'B';
    } else {
        board[0][0] = 'B';
        board[0][4] = 'B';
        board[2][3] = 'B';
        board[3][4] = 'B';
        board[4][5] = 'B';
        board[4][7] = 'B';
        board[5][1] = 'B';
        board[5][5] = 'B';
        board[5][6] = 'B';
        board[7][7] = 'B';
    }
}

void analyzeBoard(char (*board)[8]) {
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (board[r][c] == 'B') continue;
            int adj = 0;
            for (int m = 0; m < 8; m++) {
                int nr = r + dx[m];
                int nc = c + dy[m];
                if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8) continue;
                if (board[nr][nc] == 'B') adj++;
            }
            if (adj) board[r][c] = '0' + adj;
            else board[r][c] = ' ';
        }
    }
}

void printBoard(char (*board)[8], bool (*reveal)[8]) {
    cout << "  0 1 2 3 4 5 6 7 \n";
    for (int i = 0; i < 8; i++) {
        cout << i << " ";
        for (int j = 0; j < 8; j++) {
            if (reveal[i][j]) cout << board[i][j] << " ";
            else cout << ". ";
        }
        cout << endl;
    }
}

bool revealBoard(char (*board)[8], bool (*reveal)[8], int r, int c, int &blank) {
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    reveal[r][c] = true;
    if (board[r][c] == 'B') return true;
    reveal[r][c] = false;
    queue<pair<int, int>> q;
    q.emplace(r, c);
    while (!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();
        if (reveal[nr][nc]) continue;
        //printf("reveal: %d %d\n", nr, nc);
        reveal[nr][nc] = true;
        blank--;
        if (board[nr][nc] == ' ') {
            for (int m = 0; m < 8; m++) {
                int nx = nr + dx[m];
                int ny = nc + dy[m];
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
                q.emplace(nx, ny);
            }
        }
    }
    return false;
}

int main() {
    char board[8][8] = {0};
    bool reveal[8][8] = {0};
    int seed;
    int blank = 64;
    cout << "Please enter a number: ";
    cin >> seed;
    generateBombs(board, seed);
    analyzeBoard(board);
    cout << "Welcome to Minesweeper!\n";
    printBoard(board, reveal);
    int r, c;
    while (true) {
        cout << "Enter row and column to reveal: ";
        cin >> r >> c;
        if (r < 0 || c < 0 || r >= 8 || c >= 8) {
            cout << "Invalid input. Try again.\n";
            continue;
        }
        if (revealBoard(board, reveal, r, c, blank)) {
            printBoard(board, reveal);
            cout << "Game Over! You hit a bomb.";
            break;
        }
        printBoard(board, reveal);
        if (blank == 9) {
            cout << "Congratulation!! You won!!";
            break;
        }
    }
}
