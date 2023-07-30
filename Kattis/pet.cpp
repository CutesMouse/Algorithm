#include <iostream>
#include <regex>
using namespace std;
int main() {
	int current_max_pos = 0;
	int current_max = 0;
	int current = 0;
	for (int pos = 1; pos <= 5; pos++) {
		current = 0;
		int n;
		for (int i = 0; i <4; i++) {
			cin >> n;
			current += n;
		}
		if (current > current_max) {
			current_max = current;
			current_max_pos = pos;
		}
	}
	cout << current_max_pos << " " << current_max;
} 