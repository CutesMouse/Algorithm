#include <iostream>
using namespace std;

int main() {
	int t, m, d;
	cin >> t;
	while (t--) {
		cin >> d >> m;
		int ans = 0;
		int w = 0;
		for (int i = 0; i < m; i++) {
			cin >> d;
			int nw = (w + d) % 7;
			if (d >= 13 && (w + 12) % 7 == 5) ans++;
			w = nw;
		}
		cout << ans << endl;
	}
}
