#include <iostream>
#include <cmath>
using namespace std;
int area;

int attempt(int L)
{
    if (!(area % L)) return L;
    return attempt(L+1);
}

void calc()
{
    cout << "Please input an area: ";
    cin >> area;
    if (area < 0)
    {
        cout << "Thanks for using :)";
        return;
    }
    if (area == 0)
    {
        cout << "0 * 0\n";
    }
    else
    {
        int mid = ceil(sqrt(area));
        int L = attempt(mid);
        cout << L << " * " << (area/L) << endl;
    }
    calc();
}

int main()
{
    cout << "Welcome to Area Calculator :)\n";
    calc();
}
