#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct runner {
    string name;
    double t1;
    double t2;
};
runner d[505];

bool cmp(runner &r1, runner &r2) {
    return r1.t2 < r2.t2;
}

int main() {
    cout << fixed << setprecision(10);
    int n;
    string name;
    double t1, t2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> t1 >> t2;
        d[i] = {name, t1, t2};
    }
    sort(d, d + n, cmp);
    runner top[4];
    double shortest_time = 10000;
    for (int i = 0; i < n; i++) {
        runner tmp[4];
        double time = d[i].t1;
        tmp[0] = d[i];
        for (int j = 0, k = 1; j < n && k < 4; j++) {
            if (i == j) continue;
            tmp[k++] = d[j];
            time += d[j].t2;
        }
        if (time < shortest_time) {
            shortest_time = time;
            for (int q = 0; q < 4; q++) top[q] = tmp[q];
        }
    }
    cout << shortest_time << endl;
    for (int i = 0; i < 4; i++) cout << top[i].name << endl;

}
