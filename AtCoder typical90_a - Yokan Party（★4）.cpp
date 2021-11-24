#include <iostream>
using namespace std;
int N,L,K;
int A[100005];
bool cont(int min_max) {
	int chance = K+1;
	int seg = 0;
	for (int i = 0; i < N+1; i++) {
		if (chance == 0) return false;
		if (seg + A[i] >= min_max) {
			seg = 0;
			chance--;
			continue;
		}
		seg += A[i];
	}
	if (seg > min_max) chance--;
	return chance > 0;
}

int bs(int n, int m) {
	int ans = -1;
	while (n < m) {
		int mid = (n+m)/2;
		if (cont(mid)) {
			ans = mid;
			m = mid;
		} else {
			n = mid + 1;
		}
	}
	return ans;
}

int main() {
	cin >> N >> L >> K;
	int last = 0,temp;
	int min_dif = last;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A[i] = temp - last;
		min_dif = min(min_dif,A[i]);
		last = temp;
	}
	A[N] = L - last;
	cout << bs(min_dif,L)-1;
}
