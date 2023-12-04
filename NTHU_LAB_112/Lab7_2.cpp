#include <iostream>
using namespace std;

int main() {
	int nums[1000001] = {0};
	int n, k;
	cin >> n;
	while (n--) {
		cin >> k;
		nums[k]++;
	}
	for (int i = 1000000; i > 0; i--) {
		int amt = 0;
		for (int k = i; k <= 1000000; k += i) {
			amt += nums[k];
		}
		if (amt >= 2) {
			cout << i;
			return 0;
		}
	}
}
