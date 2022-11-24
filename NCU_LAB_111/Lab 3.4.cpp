#include <iostream>
#include <cmath>
using namespace std;

double capital, price;
double f, c;
double interval;

int calc(double r) {
    double A = price;
    double P = capital;
    double n = (1 / interval);
    double t = (log10(A) - log10(P)) / ( log10(1 + (r / 100)));
    return ceil(t);
}
int main() {
    cout << "Please enter your capital: \n";
    cin >> capital;
    cout << "Please enter the annual interest rate floor: \n";
    cin >> f;
    cout << "Please enter the annual interest rate ceiling: \n";
    cin >> c;
    cout << "Please enter the annual interest rate interval: \n";
    cin >> interval;
    cout << "Please enter the target price: \n";
    cin >> price;

    for (double start = f ; start <= (c); start += interval) {
        int years = calc(start);
        cout << start << " interest rate required time (year): " << years << endl;

        if (years > 10)
            cout << "Too long\n";
        else
            cout << "Goal achieved\n";
    }
}

