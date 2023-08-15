#include <iostream>
using namespace std;

int main() {
	int sweet, sour;
	while(cin >> sweet >> sour && (sweet || sour)) {
		if (sweet + sour == 13) cout << "Never speak again.";
		else if (sour > sweet) cout << "Left beehind.";
		else if (sweet > sour) cout << "To the convention.";
		else if (sweet == sour) cout << "Undecided.";
		cout << endl;
	}
}

