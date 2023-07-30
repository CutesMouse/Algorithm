#include <iostream>
#include <cmath>

using namespace std;

float x[1000];
float y[1000];
int tour[1000];
bool used[1000] = {false};

float dist(int index1, int index2) {
    float x1 = x[index1];
    float x2 = x[index2];
    float y1 = y[index1];
    float y2 = y[index2];
    return sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n;i ++) {
        cin >> x[i] >> y[i];
    }
    tour[0] = 0;
    used[0] = true;
    for (int i = 1; i < n; i++) {
        int best = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (best == -1 || dist(tour[i-1],j) < dist(tour[i-1], best))) {
                best = j;
            }
        }
        tour[i] = best;
        used[best] = true;
    }
    for (int i = 0; i < n; i++) {
        cout << tour[i] << endl;
    }
}
