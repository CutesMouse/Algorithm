#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int C, N;
    int data[1000];
    cin >> C;
    while (C--) {
        cin >> N;
        int s = 0;
        for (int i = 0; i < N; i++) {
            cin >> data[i];
            s += data[i];
        }
        double avg = (double) s / N;
        int above = 0;
        for (int i = 0; i < N; i++) {
            above += (data[i] > avg);
        }
        cout << fixed << setprecision(3) << (double) above*100 / N << "%" << endl;
    }
}
