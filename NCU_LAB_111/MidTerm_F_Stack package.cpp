#include <iostream>
using namespace std;

int W[10000], L[10000];

bool is_valid(int from, int to)
{
    int afford = -1;
    for (int k = from; k <= to; k++)
    {
        if (afford == -1) afford = W[k] + L[k];
        afford = min(afford-W[k], L[k]);
    }
    return (afford >= 0);
}

int main()
{
    cout << "The number of packages: ";
    int packages;
    cin >> packages;
    int mx = 1;
    for (int i = 0; i < packages; i++)
    {
        cout << "package "<<i+1<<": ";
        cin >> W[i] >> L[i];
    }

    for (int from = 0; from < packages; from ++)
    {
        for (int to = from; to < packages; to++)
        {
            if (is_valid(from,to))
            {
                mx = max(mx,to-from+1);
            }
        }
    }


    cout << "The maximum stacking number is " << mx;
}
