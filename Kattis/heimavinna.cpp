#include <iostream>

using namespace std;

int main() {
    string prob;
    cin >> prob;
    int number = 0;
    int from = 0;
    int to = 0;
    int* modifying = &from;
    for (int i = 0; i < prob.size(); i++) {
        char c = prob[i];
        if (c == '-') {
            modifying = &to;
            continue;
        }
        if (c == ';') {
            modifying = &from;
            if (to) number += (to - from + 1);
            else number++;
            from = to = 0;
            continue;
        }
        (*modifying) *= 10;
        (*modifying) += c-'0';
    }

    if (to) number += (to - from + 1);
    else number++;

    cout << number;
}
