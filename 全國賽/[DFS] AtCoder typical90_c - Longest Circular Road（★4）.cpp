#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> tree[100000];
vector<int> dfs(int start) {
    vector<int> dis(100000, -1);
    dis[start] = 0;
    stack<int> stack;
    stack.push(start);
    while (!stack.empty()) {
        int n = stack.top();
        stack.pop();
        for (int k : tree[n]) {
            if (dis[k] != -1) continue;
            dis[k] = dis[n] + 1;
            stack.push(k);
        }
    }
    return dis;
}

int main() {
    int N, A, B;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        cin >> A >> B;
        A--, B--;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }
    auto dis1 = dfs(0);
    int mx = -1, x = 0;
    for (int i = 0; i < N; i++) {
        if (dis1[i] > mx) {
            mx = dis1[i];
            x = i;
        }
    }
    auto dis2 = dfs(x);
    mx = -1;
    for (int i = 0; i < N; i++) {
        if (dis2[i] > mx) {
            mx = dis2[i];
        }
    }
    cout << mx+1;
}
