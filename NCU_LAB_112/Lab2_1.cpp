#include <iostream>
using namespace std;

int main() {
    float h;
    cout << "Please enter your height: ";
    cin >> h;
    h = h / 100;
    float from = h * h * 18.5;
    float to = h * h * 24;
    if (h == 0) printf("The healthy weight range is 0 (kg)");
    else cout << "The healthy weight range is " << from << " ~ " << to << " (kg)";
}
