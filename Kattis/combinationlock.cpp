#include <iostream>
using namespace std;
const int t = 9;

// 0: counterclock
// 1: clockwise
int dis(int a, int b, int direction) {
	if (direction) {
		if (a < b) a += 40;
		return t * (a - b);
	}
	if (b < a) b += 40;
	return t * (b - a);
}

int main() {
	int a, b, c, d;
	while (cin >> a >> b >> c >> d && (a || b || c || d)) {
		int deg = 1080;
		deg += dis(a,b,1);
		deg += dis(b, c, 0);
		deg += dis(c,d,1);
		cout << deg << endl;
	}
}
