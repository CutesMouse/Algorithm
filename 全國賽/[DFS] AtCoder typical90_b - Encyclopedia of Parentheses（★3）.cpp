#include <iostream>

using namespace std;

string result;
void dfs(int depth, int left, int right) {
    if (depth == result.size()) {
        cout << result << endl;
        return;
    }
    if ((left+1) >= right && (left+1) <= result.size()/2) {
        result[depth] = '(';
        dfs(depth+1, left+1, right);
    }
    if (left >= (right+1) && (right+1) <= result.size()/2) {
        result[depth] = ')';
        dfs(depth+1, left, right+1);
    }

}

int main() {
    int N;
    cin >> N;
    if (N%2) {
        return 0;
    }
    result.resize(N);
    dfs(0, 0, 0);
}
