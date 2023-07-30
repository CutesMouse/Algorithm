#include <iostream>

using namespace std;
int main() {
	int a,b;
	cin >> a >> b;
	int times = 0;
	while (a > b) {
		if (a & 1) a ++;
		else a /= 2;
		times++;
	}
	times += (b - a);
	cout << times;
} 