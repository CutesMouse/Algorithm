#include <iostream> 
#include <cmath>
using namespace std;
int main() {
	long long int a,b;
	while (cin >> a >> b) {
		cout << (long long int)abs(a-b) << "\n";
	}
}