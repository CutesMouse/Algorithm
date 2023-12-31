#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int equation;
int digit;


unsigned long long int power_of_ten(int p) {
    if (p == 0) return 1;
    return power_of_ten(p-1) * 10;
}

void print_equation(bool first, int digit) {
    if (digit < 0) return;
    int cof = (equation % (power_of_ten(digit+1))) / (power_of_ten(digit));
    if (cof == 0) {
        print_equation(first,digit-1);
        return;
    }
    if (!first) cout << "+";
    first = false;
    if (cof && digit == 0) {
        cout << cof;
        return;
    }
    if (cof == 1) cout << "X^" << digit;
    else cout << cof << "X^" << digit;
    print_equation(first,digit-1);
}

void integrate_and_print(bool first, int digit) {
    if (digit < 0) return;
    double cof = (equation % (power_of_ten(digit+1))) / (power_of_ten(digit));
    cof /= (digit+1);
    digit -= 1;
    if (cof == 0) {
        integrate_and_print(first,digit);
        return;
    }
    if (!first) cout << "+";
    first = false;
    if (cof == 1) cout << "X^" << digit+2;
    else cout << cof << "X^" << digit+2;
    integrate_and_print(first,digit);
}

int main()
{
    cout << "Please input an integer N: ";
    cin >>equation;
    if (!equation) {
        cout << "The equation is 0\nThe equation after indefinite integration is C";
        return 0;
    }
    digit = ceil(log10(equation));
    cout << "The equation is ";
    print_equation(true, digit);
    cout << endl;
    cout << "The equation after indefinite integration is ";
    integrate_and_print(true,digit);
    cout << "+C";
}

