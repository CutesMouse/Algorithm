#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int c = 1;
    double v0,v,s;
    while (true)
    {
        cout << "Please enter the initial velocity (cm/s): ";
        cin >> v0;
        cout << "Please enter the final velocity (cm/s): ";
        cin >> v;

        while (true)
        {
            cout << "Please enter the displacement (cm): ";
            cin >> s;
            if (s <= 0)
            {
                cout << "Wrong input!!! Please enter again!!!\n";
                continue;
            }
            break;
        }
        printf("For the Case %d:\n",c);
        c++;
        double a = (v*v - v0*v0)/(2*s);
        cout << "    the constant acceleration is "<<fixed << setprecision(3) << a << " (cm/s^2).\n";

        char c;
        bool ed = false;
        while (true)
        {
            cout << "Do you still want to analyze the experimental result? (y/n) ";
            cin >> c;
            if (c == 'y')
            {
                ed = false;
                break;
            }
            if (c == 'n')
            {
                ed = true;
                break;
            }
            cout << "Wrong input!!! Please enter again!!!\n";
        }
        if (!ed) continue;
        cout << "Bye~~~";
        break;
    }
}

