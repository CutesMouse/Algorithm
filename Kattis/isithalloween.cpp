#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string d;
    int t;
    cin >> d >> t;
    if ((d == "OCT" && t == 31) || (d == "DEC" && t == 25)) cout << "yup";
    else cout << "nope";
}
