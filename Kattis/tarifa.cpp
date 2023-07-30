#include <iostream> 
using namespace std;
int main() {
    int x,n,p;
    cin >> x >> n;
    int o = x;
    for (int i = 0; i <n; i++) {
        cin >> p;
        o += (x - p);
    }
    cout << o;
}
