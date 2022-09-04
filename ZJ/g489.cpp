#include <iostream>
#include <set>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    int st;
    set<int> lis;
    set<int> come;
    for (int i = 0; i < m; i++)
    {
        cin >> st;
        lis.insert(st);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> st;
        come.insert(st);
    }
    int cnt = lis.size() - come.size();
    cout << cnt;
}
