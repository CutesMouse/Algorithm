#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int d[1005][1005];
map<int,int> cnt;
int main()
{
    int N;
    cin >> N;
    int rx,ry,lx,ly;
    memset(d,0,sizeof(d));
    for (int i = 0; i < N; i++)
    {
        cin >> rx >> ry >> lx >> ly;
        d[rx][ry] ++;
        d[rx][ly] --;
        d[lx][ry] --;
        d[lx][ly] ++;
    }
    for (int y = 0; y < 1000; y++)
    {
        int slide = 0;
        for (int x = 0; x < 1000; x++)
        {
            slide += d[x][y];
            d[x][y] = slide;
        }
    }
    for (int x = 0; x < 1000; x++)
    {
        int slide = 0;
        for (int y = 0; y < 1000; y++)
        {
            slide += d[x][y];
            if (slide) cnt[slide]++;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << cnt[i] << endl;
    }
}
