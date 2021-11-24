#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int b[100000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	sort(a,a+N);
	sort(b,b+N);
	long long s = 0;
	for (int i = 0; i < N; i++) {
		s += abs(a[i] - b[i]);
	}
	cout << s;
}
