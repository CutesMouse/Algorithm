#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout << "Please enter n, k, m:\n";
    int n,k,m;
    cin >> n >> k >> m;
    k--;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    while (v.size() > 1) {
        int quit = ((k) + (m-1))%(v.size());
        v.erase(v.begin()+quit,v.begin()+quit+1);
        k = quit;
    }
    cout << v[0]+1;
}
