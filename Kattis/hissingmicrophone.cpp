#include <iostream>
#include <regex>
using namespace std;
int main() {
	regex r(".*?ss.*");
	string input;
	cin >> input;
	if (!regex_match(input,r)) {
		cout << "no ";
	}
		cout << "hiss";
} 