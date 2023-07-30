#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int permu[25];

int main() {
    string code, newcode_1, newcode_2, newcode_3;
    int n, i, a, start, j;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        for (i = 0; i <= n - 1; i++) {
            cin >> permu[i];
        }
        getline(cin, code);
        getline(cin, code);
        for (i = 0; i < code.size() % n; i++) {
            code += " ";
        }
        newcode_1 = "";
        newcode_2 = "";
        newcode_2 += "'";

        a = code.size() / n;
        for (i = 0; i < a; i++) {
            start = 0 + n * i;
            newcode_1 = code.substr(start, n);
            newcode_3 = newcode_1;
            for (j = 0; j < newcode_1.size(); j++) {
                newcode_1[j] = newcode_3[permu[j]-1];
            }
            newcode_2 += newcode_1;
        }
        newcode_2 += "'";
        cout << newcode_2 << "\n";
    }
    return 0;
}