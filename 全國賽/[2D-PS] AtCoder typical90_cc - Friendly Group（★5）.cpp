#include <iostream>
#include <cstring>
#define SIZE 5000
using namespace std;
int px_sum[5005][5005];
int val[5005][5005];
int main()
{
    int N,K,A,B;
    memset(px_sum,0,sizeof(px_sum));
    memset(val,0,sizeof(val));
    cin >> N >> K;
    K++;
    for (int i =0; i <N; i++)
    {
        cin >> A >> B;
        val[A][B]++;
    }
    for (int x = 1; x <= SIZE; x++)
    {
        for (int y = 1; y <= SIZE; y++)
        {
            px_sum[x][y] = px_sum[x-1][y] + px_sum[x][y-1] - px_sum[x-1][y-1] + val[x][y];
        }
    }
    int mx = 0;
    for (int x = 0; x <= SIZE-K; x++)
    {
        for (int y = 0; y <= SIZE-K; y++)
        {
            int total = px_sum[x+K][y+K] - px_sum[x+K][y]
                        - px_sum[x][y+K] + px_sum[x][y];
            mx = max(mx,total);
        }

    }
    cout << mx << endl;
}
