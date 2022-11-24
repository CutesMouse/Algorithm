#include <iostream>
using namespace std;

int fib(int k)
{
    if (k == 1) return 1;
    if (k == 2) return 1;
    return fib(k-1) + fib(k-2);
}

int main()
{
    cout << "Input an integer: ";
    int n;
    cin >> n;
    cout << "The " << n;
    if (n == 11 || n == 12 || n == 13) cout << "th";
    else
    {
        switch (n%10)
        {
        case 1:
            cout << "st";
            break;
        case 2:
            cout << "nd";
            break;
        case 3:
            cout << "rd";
            break;
        default:
            cout << "th";
        }
    }
    cout << " in fisher sequence is " << fib(n);
}
