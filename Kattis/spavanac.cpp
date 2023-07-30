#include <iostream> 
#include <cmath>
using namespace std;
int main() {
	int m,n;
	cin >> m >> n;
	
	n = 60 * m + n;
	n -= 45;
	if (n < 0) n += 60 * 24;
	cout << n/60 << " " << n%60;
	
}