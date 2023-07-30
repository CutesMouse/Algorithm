#include <iostream>
#include <memory.h>
using namespace std;
int main() {
	int n;
	int cha[300] = {0};
	int chb[300] = {0};
	cin >> n;
	string a,b;
	cin >> a >> b;
	int r = 0,s = 0;
	for (int pt = 0; pt < n; pt++) {
		if (a.at(pt) == b.at(pt)) {
			r++;
		}
		else {
			int ac = (int)a[pt];
			int bc = (int)b[pt];
			cha[ac]++;
			chb[bc]++;
		}
	}
	for (int i = (char)'A' ; i <= (char)'Z'; i++) {
		if (cha[i] && chb[i]) {
			s += min(cha[i], chb[i]);
		}
	}
	cout << r << " " << s;
} 