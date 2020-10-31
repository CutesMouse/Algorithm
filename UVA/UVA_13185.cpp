#include <iostream>
using namespace std;
//計算所有因數相加的合
int getSum(int n) {
    int sum = 0;
    for (int i = n-1; i >0; i--) {
        if (n % i == 0) sum += i;
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        int c;
        cin >> c;
        int sum = getSum(c);
        if (c == sum) {
            cout << "perfect" << endl;
        } else if (c < sum) {
            cout << "abundant" << endl;
        } else {
            cout << "deficient" << endl;
        }
    }
}
