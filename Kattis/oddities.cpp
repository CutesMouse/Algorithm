#include <iostream> 
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int c;
		cin >> c;
		cout << c << " is "<< ((c % 2) ? "odd" : "even")<< "\n" ;
	}
}