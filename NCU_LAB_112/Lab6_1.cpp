#include <iostream>
#include <cmath>
using namespace std;

int sum_digits( long long int number )
{
    int total = 0;
    long long int base = pow(10, (int) log10(number));
    while (number > 0) {
        total += (number / base);
        number = number - (number / base) * base;
        base /= 10;
    }
    return total;
}

bool p_9(long long int number) {
    int sdig = sum_digits(number);
    if (sdig < 10) {
        return (sdig == 9 || sdig == 0);
    }
    return p_9(sdig);
}

int main() {
    long long int n;
    cout << "Please enter an integer: ";
    cin >> n;
    if (p_9(n)) {
        cout << n << " is a multiple of 9!";
    } else cout << n << " is not a multiple of 9!";
}
