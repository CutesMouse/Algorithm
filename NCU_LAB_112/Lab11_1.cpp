#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double mass[100];
    const double C = 3E8;
    int iter = 0;
    cout << "Please enter the mass of materials(kg): \n";
    for (iter = 0; iter < 5; iter++) {
        cin >> *(mass + iter);
    }
    cout << "After calculation, the energy of each material is: \n";
    for (int i = 0; i < iter; i++) {
        cout << scientific << setprecision(3) << *(mass+i) * C * C << " ";
    }
}
