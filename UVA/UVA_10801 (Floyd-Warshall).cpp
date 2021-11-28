#include <iostream>
#include <vector>
#include <sstream>
#define INF 1000000
using namespace std;
int n,k;
int vert[5];
int table[500][500];
int main()
{
    while (cin >> n >> k)
    {
        vector<int> lift[5];
        vector<int> level[100];
        for (int i = 0; i < n; i++) cin >> vert[i];
        string s;
        getline(cin,s);
        for (int i = 0; i < 500; i++)
        {
            for (int k = 0; k < 500; k++)
            {
                if (i == k) table[i][k] = 0;
                else table[i][k] = INF;
            }
        }
        for (int i = 0; i < n; i++)
        {
            getline(cin,s);
            stringstream ss;
            ss << s;
            int slevel;
            while (ss >> slevel)
            {
                lift[i].emplace_back(slevel);
                level[slevel].emplace_back(i);
            }
        }
        for (int elev = 0; elev < n; elev++)
        {
            auto vec = lift[elev];
            for (int a = 0; a < lift[elev].size(); a++)
            {
                int from = vec[a];
                for (int b = 0; b < lift[elev].size(); b++)
                {
                    int to = vec[b];
                    table[elev*100 + from][elev*100 + to] = abs(from-to) * vert[elev];
                    table[elev*100 + to][elev*100 + from] = abs(from-to) * vert[elev];
                }
            }
        }
        for (int floor = 0; floor < 100; floor++)
        {
            auto vec = level[floor];
            for (int a = 0; a < vec.size(); a++)
            {
                int from = vec[a];
                for (int b = 0; b < vec.size(); b++)
                {
                    int to = vec[b];
                    if (a == b)
                    {
                        table[from * 100 + floor][from * 100 + floor] = 0;
                        table[to * 100 + floor][to * 100 + floor] = 0;
                        continue;
                    }
                    table[from * 100 + floor][to * 100 + floor] = 60;
                    table[to * 100 + floor][from * 100 + floor] = 60;
                }
            }
        }
        for (int k = 0; k < n*100; k++)
        {
            for (int a = 0; a < n*100; a++)
            {
                for (int b = 0; b< n*100; b++)
                {
                    table[a][b] = min(table[a][b],table[k][a]+table[b][k]);
                }
            }
        }
        int min_dis = INF;
        for (int from = 0; from < n; from++)
        {
            for (int to = 0; to <n; to++)
            {
                min_dis = min(table[from*100][to*100+k],min_dis);
            }
        }
        if (min_dis == INF) {
            cout << "IMPOSSIBLE\n";
        } else cout << min_dis << endl;

    }
}
