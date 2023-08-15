#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	int time = h * 60 + m;
	time = (time + 60*24) - 45;
	time = time % (60*24);
	cout << time / 60 << " " << time % 60;
}
