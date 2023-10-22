#include <iostream>
using namespace std;

string date(long long int n) {
    if (n >= 10 && n <= 20) return "th";
    switch (n%10) {
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
}

int main() {
    long long int S, D;
    cout << "Please enter the number S: ";
    while (cin >> S && S != -1) {
        cout << "Please enter the number D: ";
        cin >> D;
        long long int pts = 0;
        while (pts < D) {
            pts += S;
            S++;
        }
        S--;
        printf("Andy needs to solve %lli problems on the %lli%s day.\n", S, D, date(D).c_str());
        cout << "Please enter the number S: ";
    }
    cout << "Bye~";
}
