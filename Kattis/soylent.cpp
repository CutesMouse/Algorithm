#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, k;
	cin >> n;
	while (n--) {
		cin >> k;
		cout << ceil(k / 400.0) << endl;
	}
}
