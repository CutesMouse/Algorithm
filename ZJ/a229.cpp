#include <iostream>
#include <vector>
using namespace std;

int par = 0;
int mx;
string data;
void dfs(int depth, int l, int r)
{
    if (depth == mx)
    {
        printf("%s\n",data.c_str());
        return;
    }
    if (l < par)
    {
        data[depth] = '(';
        dfs(depth+1,l+1,r);
    }
    if (l > r)
    {
        data[depth] = ')';
        dfs(depth+1,l,r+1);
    }
}

int main()
{
    while (cin >> par)
    {
        mx = par*2;
        data.resize(mx);
        dfs(0,0,0);
        cout <<endl;
    }

}
