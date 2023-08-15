#include <iostream>
using namespace std;
int main() {
	int n;
	char c;
	cin >> n;
	cin.get();
	while (n--) {		
		long long int n = 0;
		int temp = 0;
		while ((c = cin.get()) != '\n') {
			if (c == ',') {
				n += temp;
				n *= 60;
				temp = 0;
			}
			else {
				temp *= 10;
				temp += (c - '0');
			}
		}
		cout << (n + temp) << endl;
	}
}
