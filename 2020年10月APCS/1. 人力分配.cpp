#include <iostream>
using namespace std;
int getPaid(int a, int b, int c, int n) {
	return a * n * n + b * n + c;
}
int main() {
	int a1,b1,c1,a2,b2,c2,n;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
	int m_sum = -32767;
	for (int i = 0 ; i <= n ;i++) {
		int sum = getPaid(a1,b1,c1,i) + getPaid(a2,b2,c2,n-i);
		if (sum > m_sum) {
			m_sum = sum;
		}
	}
	cout << m_sum;
}
