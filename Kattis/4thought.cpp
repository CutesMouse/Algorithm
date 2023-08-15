#include <iostream>
#include <algorithm>

using namespace std;

int drink = 0;
const char oper[4] = {'*', '+', '-', '/'};

int calc(int a, int b, int c) {
    int tmp = 4;
    int sol = 0;
    char op[3] = {oper[a], oper[b], oper[c]};
    for (int i = 0; i < 3; i++) {
        switch (op[i]) {
            case '+':
                sol += tmp;
                tmp = 4;
                break;
            case '-':
                sol += tmp;
                tmp = -4;
                break;
            case '*':
                tmp *= 4;
                break;
            case '/':
                tmp /= 4;
                break;
        }
    }
    return sol + tmp;
}

void print(int a, int b, int c, int d) {
    int numbers[5] = {4, 4, 4, 4, d};
    char operations[4] = {oper[a], oper[b], oper[c], '='};
    for (int i = 0; i < 4; i++) {
        cout << numbers[i] << " " << operations[i] << " ";
    }
    cout << numbers[4] << endl;
}

int main() {
    int n, k;
    cin >> n;
    while (n--) {
        cin >> k;
        bool found = false;
        for (int i = 0; i < 4; i++) {
            if (found) break;
            for (int j = 0; j < 4; j++) {
                if (found) break;
                for (int p = 0; p < 4; p++) {
                    if (calc(i, j, p) == k) {
                        found = true;
                        print(i, j, p, k);
                        break;
                    }
                }
            }
        }
        if (!found) cout << "no solution\n";
    }
}
