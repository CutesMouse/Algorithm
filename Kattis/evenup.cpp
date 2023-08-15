#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, c;
	cin >> n;
	stack<int> s;
	while (n--) {
		cin >> c;
		if (!s.empty() && ((c + s.top()) % 2 == 0)) s.pop();
		else s.push(c);
	}
	cout << s.size();
}
