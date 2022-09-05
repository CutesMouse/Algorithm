#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int sum = 0;
    long long int nxt;
    while (n--)
    {
        cin >> nxt;
        sum += nxt;
        cout << sum << " ";
    }
}
