#include <iostream>
using namespace std;

int main() {
    string l;
    getline(cin, l);
    int cnt = 0;
    for (char c : l) {
        c = c | (1 << 5);
        cnt += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    cout <<cnt;
}
