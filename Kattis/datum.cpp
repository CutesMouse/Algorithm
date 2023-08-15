#include <iostream>

using namespace std;


int main() {
    int D, M;
    cin >> D >> M;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dL = 2 + D;
    for (int i = 0; i < M - 1; i++) {
        dL += days[i];
    }
    string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout << week[dL%7];
}
