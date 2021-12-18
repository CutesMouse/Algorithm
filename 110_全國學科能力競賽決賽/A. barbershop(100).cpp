#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,t;
    int T[200];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
    sort(T,T+n);
    int sum = 0;
    for (int p = 0; p < n; p++) {
        sum += T[p] * (n-p);
    }
    cout << sum << endl;
}
