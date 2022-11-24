#include <iostream>
using namespace std;
int main()
{
    double mass;
    int s1, s2;
    float mu;
    cout << "Please enter the mass of the substance (kg) (enter -1 to exit): \n";
    while (cin >> mass)
    {
        if (mass == -1) break;
        cout << "Please select the material of the substance: \n1. Steel\n2. Aluminum\n";
        cin >> s1;
        cout << "Please select the material of the contact surface: \n1. Steel\n2. Aluminum\n";
        cin >> s2;
        if (s1 == 1 && s2 == 1) mu = 0.74;
        if (s1 == 1 && s2 == 2) mu = 0.61;
        if (s1 == 2 && s2 == 1) mu = 0.61;
        if (s1 == 2 && s2 == 2) mu = 1.05;
        float F = mu * mass * 9.8;
        cout << "F=" << F << endl;
        cout << "Please enter the mass of the substance (kg) (enter -1 to exit): \n";
    }
}

