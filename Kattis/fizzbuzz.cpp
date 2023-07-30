#include <iostream> 
using namespace std;
int main() {
    int a,b,n;
    cin >> a >> b >> n;
    for (int i =1; i <= n; i++) {
        if (i % a == 0) cout << "Fizz";
        if (i % b == 0) cout << "Buzz";
        if (i % a && i % b) cout << i;
        cout << "\n";
    }
}
