#include <iostream>
using namespace std;

int sum_recur(int ans, int n, int d, int term) {
    if (term == n) return ans;
    return sum_recur(ans + 1 + term * d, n, d, term+1);
}

int main() {
    int N, D;
    cout << "Please enter the number of terms N: ";
    cin >> N;
    cout << "Please enter the common difference D: ";
    cin >> D;
    cout << "The summation of the arithmetic sequence S(N): " << sum_recur(0, N, D, 0);
}
