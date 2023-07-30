#include <iostream> 
#include <iomanip>
using namespace std;
int main() {
	int n;
	double a,b;
	double s = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		s += a*b;
	}
	cout << fixed << setprecision(3) << s;
}