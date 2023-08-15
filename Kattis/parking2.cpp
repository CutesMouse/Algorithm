#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int t,n;
	int d[100];
	float mid;
	float dis;
	cin >> t;
	while (t--) {
		dis = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> d[i];
		sort(d, d+n);
		if (n % 2) mid = d[n/2];
		else mid = (d[n/2-1] + d[n/2])/2.0;
		float current = mid;
		for (int i = 0; i < n; i++) {
			dis += abs(current - d[i]);
			current = d[i];
		}
		dis += abs(current - mid);
		cout << dis << endl;
	}
}
