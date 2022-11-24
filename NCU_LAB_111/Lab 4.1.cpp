#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int dp[100];
int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = (fib(n-1) + fib(n-2));
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cout << "Please enter the number of terms: ";
    int n;
    cin >> n;
    int ptr = 0;
    for (int lines = 0; lines < ceil(n/10.0); lines++)
    {
        int amount = min(n - lines * 10,10);
        for (int i = 0; i < amount; i++)
        {
            cout << fib(ptr) << " ";
            ptr++;
        }
        cout << endl;
    }
}

