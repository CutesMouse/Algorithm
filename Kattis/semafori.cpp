#include <iostream>
using namespace std;

int main() {
	int N, L;
	int D, R, G;
	cin >> N >> L;
	int t = 0;
	int pos = 0;
	while (N--) {
		cin >> D >> R >> G;
		t += (D - pos);
		pos = D;
		int period = t % (R + G);
		if (period < R) t += R - period;
	}
	cout << t + (L - pos);
}
