#include<iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
class vec {
public:
    double x,y;
    vec(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double dot(vec &c) {
        return c.x * x + c.y * y;
    }
    double length_square() {
        return (x*x+y*y);
    }
    vec add(vec &c) {
        vec n(x+c.x,y+c.y);
        return n;
    }
    vec add(double x, double y) {
        vec n(this->x+x,this->y+y);
        return n;
    }
    bool between(int x1, int y1, int x2, int y2) {
        int mx = max(x1,x2);
        int nx = min(x1,x2);
        int my = max(y1,y2);
        int ny = min(y1,y2);
        return (x >= nx && x <= mx && y >= ny && y <= my);
    }
    vec multiply(double n) {
        vec nv(x*n,y*n);
        return nv;
    }
};
double dis(double a, double b, double c, double d)
{
    double dx = a-c;
    double dy = b-d;
    return sqrt(dx*dx + dy*dy);
}
vec antipo(int x1, int y1, int x2, int y2, int x, int y) {
    vec v(x2-x1,y2-y1);
    vec k(x-x1,y-y1);
    vec am = v.multiply(v.dot(k)/v.length_square());
    return am.add(x1,y1);
}
int main()
{
    int px,py,n;
    cin >> px >> py >> n;
    vector<double> v;
    int rfx[105],rfy[105],rtx[105],rty[105];
    cin >> rfx[0] >> rfy[0];
    v.emplace_back(dis(px,py,rfx[0],rfy[0]));
    for (int i = 0; i < n; i++)
    {
        cin >> rtx[i] >> rty[i];
        rfx[i+1] = rtx[i];
        rfy[i+1] = rty[i];
        v.emplace_back(dis(px,py,rtx[i],rty[i]));
        vec anti = antipo(rfx[i],rfy[i],rtx[i],rty[i],px,py);
        if (anti.between(rfx[i],rfy[i],rtx[i],rty[i])) {
            v.emplace_back(dis(anti.x,anti.y,px,py));
        }
    }
    double mx = -1;
    for (auto iter = v.begin() ; iter != v.end() ;iter++) {
        if (mx == -1) mx = *iter;
        mx = min(*iter,mx);
    }
    cout << fixed << setprecision(15) << mx << endl;
}
