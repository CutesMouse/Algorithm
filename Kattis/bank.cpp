#include <iostream>

using namespace std;

struct person {
    int money;
    int waiting;
};

int main() {
    int N, T;
    int total = 0;
    cin >> N >> T;
    int m, t;
    person list[N];
    for (int i = 0; i < N; i++) {
        cin >> m >> t;
        list[i] = {m, t};
    }
    for (int i = T; i >= 0; i--) {
        int mx_value = -1;
        int mx_index = -1;
        for (int j = 0; j < N; j++) {
            if (list[j].waiting >= i && list[j].money > mx_value) {
                mx_index = j;
                mx_value = list[j].money;
            }
        }
        if (mx_index == -1) continue;
        total += mx_value;
        list[mx_index].waiting = -1;
    }
    cout << total;
}
