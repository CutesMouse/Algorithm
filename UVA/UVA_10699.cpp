#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> needLess;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0) return 0;
		cout << n;
		int amount = 0;
		int search = sqrt(n) + 1;
		for (int i = 2; i <=n; i++) {
			if (n % i == 0) {
				amount++;
				while (n % i == 0) {
					n /= i;
				}
			}
		}
		if (amount == 0) amount++;
		cout << " : " << amount << "\n";
	}
}
