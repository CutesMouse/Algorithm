#include <iostream>
using namespace std;

int main() {
		int a, b, c;
		cin >> a >> b >> c;
		int sp = max(b-a, c-b);
		cout << sp-1;	
}
