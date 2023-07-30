#include <iostream> 
using namespace std;
int main() {
	int maxWidth;
	while (cin >> maxWidth) {
		if (maxWidth == 0) return 0;
		int x,y;
		int maxX = 0;
		int ly = 0;
		int cx = 0, cy = 0;
		while (cin >> x>>y) {
			if (x == -1 && y == -1) break;
			if (cx + x > maxWidth) { // switch line
				cy += ly;
				ly = y;
				maxX = max(maxX,cx);
				cx = x;
			} else {
				cx += x;
				ly = max(ly,y);
			}
		}
		maxX = max(maxX,cx);
		cout << maxX << " x " << cy+ly << endl; 
	}
}