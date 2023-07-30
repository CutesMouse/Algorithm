#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int h,m;
	cin >> h >> m;
	cout << ceil(1/sin(m*3.141592653/180)*h);
}