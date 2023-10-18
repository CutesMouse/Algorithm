#include <iostream>
#include <iomanip>
#define double long double
#define pow2(x) (x)*(x)
using namespace std;

int N;
double C;
pair<int, int> pts[200005];
const double EPS = 1E-10;

template<class FuncTy>
pair<double, double> ts(double left, double right, FuncTy f) {
        while (left + EPS < right) {
                        //cout << left << ", " << right << endl;
                double mL = left + (right-left) / 3;
                double mR = right - (right - left) / 3;
                if (f(mL) > f(mR)) left = mL;
                else right = mR;
        }
        return {left, right};
}

double dis(double p) {
        double d = 0;
        //cout << d << "("<<d<<"):" << endl;
        for (int i = 0; i < N; i++) {
                d += (pow2(p - pts[i].first) + pow2(C - pts[i].second));
        }
        return d;
}

int main() {
        int x, y;
        cin >> N >> C;
        for (int i = 0; i < N; i++) {
                cin >> x >> y;
                pts[i] = {x, y};
        }
        double target = ts(-100005.0, 100005.0, dis).first;
        cout << setprecision(10) << fixed << dis(target);
}
