#include <iostream>
using namespace std;

int A, B, C, D, E;

int gb(int box, int pos) {
    int base = 1;
    for (int i = 0; i < pos; i++) base *= 10;
    return (box / base) % 10;
}

void ib(int &box, int pos) {
    int nb = 0;
    for (int i = 3; i >= 0; i--) {
        int b = gb(box, i);
        if (i == pos) b = !b;
        nb *= 10;
        nb += b;
    }
    box = nb;
}

void input_box(int &box, char id) {
    while (true) {
        cout << "Please enter the type of the black box " << id << ": ";
        cin >> box;
        bool valid = (box >= 0 && box <= 1111);
        for (int i = 0; i < 4; i++) valid = valid && (gb(box, i) <= 1);
        if (valid) break;
        cout << "Wrong input!!! Please enter again!!!\n";
    }
}

bool cancel_bubble() {
    bool cancelled = false;

    if (gb(A, 0) && gb(E, 2)) {
        ib(A, 0);
        ib(E, 2);
        cancelled = true;
    }
    if (gb(B, 0) && gb(C, 2)) {
        ib(B, 0);
        ib(C, 2);
        cancelled = true;
    }
    if (gb(C, 0) && gb(D, 1)) {
        ib(C, 0);
        ib(D, 1);
        cancelled = true;
    }
    if (gb(D, 0) && gb(E, 1)) {
        ib(D, 0);
        ib(E, 1);
        cancelled = true;
    }
    return cancelled;
}

int main() {
    input_box(A, 'A');
    input_box(B, 'B');
    input_box(C, 'C');
    input_box(D, 'D');
    input_box(E, 'E');
    if (cancel_bubble()) {
        cout << "Wire has two bubbles!\nCanceling out the bubbles...\n";
    } else cout << "There isn't any wire has two bubbles!\n";
    int aly;
    char op;
    cout << "How many black box do you want to implement the De Morgan's laws? ";
    cin >> aly;
    for (int i = 0; i < aly; i++) {
        while (true) {
            cout << "Please enter the black box you want to modify: ";
            cin >> op;
            if (op == 'A' || op == 'B' || op == 'C' || op == 'D' || op == 'E') break;
            cout << "The black box doesn't exist!!!\n";
        }
        int* change = 0;
        switch (op) {
            case 'A':
                change = &A;
                break;
            case 'B':
                change = &B;
                break;
            case 'C':
                change = &C;
                break;
            case 'D':
                change = &D;
                break;
            case 'E':
                change = &E;
                break;
        }

        for (int i = 0; i < 4; i++) {
            ib(*change, i);
        }
        cancel_bubble();
        cout << "After the De Morgan's laws: \n";
        printf("A: %04d\n", A);
        printf("B: %04d\n", B);
        printf("C: %04d\n", C);
        printf("D: %04d\n", D);
        printf("E: %04d\n", E);
    }
}
