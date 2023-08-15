#include <iostream>

using namespace std;


int main() {
    string list = "A23456789TJQK";
    int s[20] = {0};
    string card;
    while (cin >> card && card != "0") {
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == card[0]) s[i]++;
        }
    }
    int mx = 0;
    for (int i = 0; i < list.size(); i++) {
        mx = max(mx, s[i]);
    }
    cout << mx;

}
