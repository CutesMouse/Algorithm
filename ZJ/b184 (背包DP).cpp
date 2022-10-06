#include <iostream>
#include <cstring>
using namespace std;

int dp[100][105];

int weight[100];
int price[100];

int main()
{
    int number, volume, profit;
    while (cin >> number)
    {
        for (int i = 0; i < number; i++)
        {
            cin >> weight[i] >> price[i];
        }
        for (int j = 0; j < 105; j++) {
            if (j - weight[0] < 0) {
                dp[0][j] = 0;
            } else dp[0][j] = price[0];
        }
        for (int j = 0; j < 105; j++)
        {
            for (int i = 1; i < number; i++)
            {
                if (j - weight[i] < 0)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+price[i]);
            }
        }
        cout << dp[number-1][100] << endl;
    }
}
