#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n,m,input;
    cin >> n >> m;
    vector<vector<int> > vs;
    for (int i = 0; i < n; i++)
    {
        vector<int> child;
        for (int k = 0; k < m; k++)
        {
            cin >> input;
            child.push_back(input);
        }
        vs.push_back(child);
    }
    sort(vs.begin(), vs.end());
    for (int i = 0; i < vs.size(); i++)
    {
        vector<int> child = vs[i];
        for (int k = 0; k < child.size(); k++)
        {
            cout << child[k] << " ";
        }
        cout << endl;
    }
}
