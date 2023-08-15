#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n,k,val;
	cin >> n >> k;
	double s = 0;
	for (int i = 0; i < k; i++) {
		cin >> val;
		s += val;
	}
	cout << fixed << setprecision(6);
	cout << (s + (n-k)*(-3))/n << " ";
	cout << (s + (n-k)*(3))/n << endl;
}
