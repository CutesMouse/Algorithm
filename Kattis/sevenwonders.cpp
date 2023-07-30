#include <iostream>

using namespace std;

int main() {
    string t;
    cin >> t;
    int table[256] = {0};
    for (int i = 0; i < t.size(); i++) {
        char c = t[i];
        table[c]++;
    }
    int T = table['T'];
    int C = table['C'];
    int G = table['G'];
    int ptr = T*T + C*C + G*G;
    ptr += 7 * min(T,min(C,G));
    cout << ptr;
}
