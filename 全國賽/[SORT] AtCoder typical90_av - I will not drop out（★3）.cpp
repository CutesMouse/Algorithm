#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N,K,a,b;
    vector<int> v;
    cin >>N >> K;
    for (int i=0; i < N;i++) {
            cin >> a >> b;
            a = a-b;
            v.emplace_back(a);
            v.emplace_back(b);
    }
    sort(v.rbegin(),v.rend());
    long long int sum = 0;
    for (int i = 0; i < K; i++) {
            //cout << v[i] <<endl;
            sum += v[i];
    }
    cout << sum << endl;
}
