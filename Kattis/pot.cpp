#include <iostream> 
#include <cmath>
using namespace std;
int main() {
	int n,s = 0;
	cin >> n;
	while (n--) {
		int o;
		cin >> o;
		s+=pow(o/10,o%10);
	}
	cout << s;
}