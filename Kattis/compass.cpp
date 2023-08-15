#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int deg = b - a;
	if (abs(deg) > abs(deg+360)) deg = deg+360;
	else if (abs(deg) > abs(deg-360)) deg = deg-360;
	if (deg == -180) deg = 180;
	cout << deg;
}
