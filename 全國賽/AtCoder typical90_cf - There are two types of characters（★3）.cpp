#include <iostream>
using namespace std;
int main() {
    int N;
    string s;
    cin >> N >> s;
    int o = -1, x = -1;
    long long int l = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'o') o = i;
        else x = i;
        if (o != -1 && x != -1) l += abs(min(o,x)) +1;
    }
    cout << l <<endl;
}
