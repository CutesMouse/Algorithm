#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> edge[200001];
int n, a, b;
int dis[200001];

void dfs(int pt, int c) {
    dis[pt] = c;
    //cout << pt << " " << c <<endl;
    for (int link : edge[pt]) {
        //cout << dis[link] << "link\n";
        if (dis[link] != 0) continue;
        dfs(link, c+1);
    }
}


int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    memset(dis, 0, sizeof dis);
    dfs(1, 1);
    int far = max_element(dis+1, dis+n+1) - dis;
    memset(dis, 0, sizeof dis);
    dfs(far, 1);
    cout << *max_element(dis+1, dis+n+1)-1;
}
