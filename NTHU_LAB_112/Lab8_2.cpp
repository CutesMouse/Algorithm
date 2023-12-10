#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> edge[200001];
int n, a, b;
int dis1[200001];
int dis2[200001];

void dfs(int pt, int c, int* dis) {
    dis[pt] = c;
    //cout << pt << " " << c <<endl;
    for (int link : edge[pt]) {
        //cout << dis[link] << "link\n";
        if (dis[link] != 0) continue;
        dfs(link, c+1, dis);
    }
}


int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    memset(dis1, 0, sizeof dis1);
    memset(dis2, 0, sizeof dis2);
    dfs(1, 1, dis1);
    int far = max_element(dis1+1, dis1+n+1) - dis1;
    memset(dis1, 0, sizeof dis1);
    dfs(far, 1, dis1);
    dfs(max_element(dis1+1, dis1+n+1)- dis1, 1, dis2);
    for (int i = 1; i <= n; i++) {
        cout << max(dis1[i], dis2[i])-1 << " ";
    }
}
