#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double v0 = 0, a = 60, t = 1;
    string s;
    char c;
    bool calc_velocity;
    cout << "\"Calculation mode\"\n";
    cout << "Initial velocity: 0\n";
    cout << "Acceleration: 60\n";
    cout << "Moving time: 1\n";
    cout << "Whether to calculate the velocity? (y/n) ";
    bool enter_yet = false;
    double v;
    do
    {
        cin >> s;
        char c= s[0];
        switch(c)
        {
        case 'y':
        case 'Y':
            enter_yet = true;
            calc_velocity = true;
            v = v0 + a * t;
            cout << "The velocity of the plane is "<<round(v)<<" km/hr.";
            return 0;

        case 'n':
        case 'N':
            enter_yet = true;
            calc_velocity = false;
            break;
        default:
            cout << "Invalid input! Please enter the choice again: (y/n) ";
        }
    }
    while (!enter_yet);
    do
    {
        cout << "\"Setting mode\"\n";
        cout << "Please enter the initial velocity: ";
        cin >> v0;
        cout << "Please enter the acceleration: ";
        cin >> a;
        cout << "Please enter the moving time: ";
        cin >> t;
        cout << "Whether to calculate the velocity? (y/n) ";
        enter_yet = false;
        do
        {
            cin >> c;
            switch(c)
            {
            case 'y':
            case 'Y':
                enter_yet = true;
                calc_velocity = true;
                v = v0 + a * t;
                cout << "The velocity of the plane is "<<round(v)<<" km/hr.";
                return 0;
            case 'n':
            case 'N':
                enter_yet = true;
                calc_velocity = false;
                break;
            default:
                cout << "Invalid input! Please enter the choice again: (y/n) ";
            }
        }
        while (!enter_yet);
    }
    while (!calc_velocity);
}

