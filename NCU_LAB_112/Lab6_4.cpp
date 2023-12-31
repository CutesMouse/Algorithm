#include <iostream>
#include <cmath>
#define PI 3.14159265

using namespace std;

struct point {
    double x;
    double y;
};

struct equSol {
    point p;
    bool exist;
};

// ax + by = c
struct equation {
    double a;
    double b;
    double c;
};

equation lineTo(point &p1, point &p2) {
    if (p1.x == p2.x) {
        return {1, 0, p1.x};
    }
    double a = (p2.y - p1.y) / (p2.x - p1.x);
    double b = p2.y - a * p2.x;
    return {a,-1, -b};
}

equSol intersection(equation &e1, equation &e2) {
    double d = (e1.a * e2.b) - (e1.b * e2.a);
    if (d == 0) return {{0, 0}, false};
    double dx = (e1.c * e2.b) - (e1.b * e2.c);
    double dy = (e1.a * e2.c) - (e1.c * e2.a);
    double x = dx / d;
    double y = dy / d;
    return {{x, y}, true};
}

bool between(point &target, point &pa, point &pb) {
    double min_x = min(pa.x, pb.x);
    double min_y = min(pa.y, pb.y);
    double max_x = max(pa.x, pb.x);
    double max_y = max(pa.x, pb.x);
    return target.x > min_x && target.x < max_x && target.y > min_y && target.y < max_y;
}

point shift_point(point &p, double distance, double angle) {
    double x = p.x + distance * cos(angle * PI / 180);
    double y = p.y + distance * sin(angle * PI / 180);
    return {x, y};
}

bool is_bt(point &a, point &b, point &c, point &d) {
    equation q1 = lineTo(a, b);
    equation q2 = lineTo(c, d);
    equSol s = intersection(q1, q2);
    if (!s.exist) return false;
    return between(s.p, a, b) && between(s.p, c, d);
}

bool is_bt(point &p, equation q1, equation q2) {
    if (q1.a < 0) {
        q1.a *= -1;
        q1.b *= -1;
        q1.c *= -1;
    }
    if (q2.a < 0) {
        q2.a *= -1;
        q2.b *= -1;
        q2.c *= -1;
    }
    return ((q1.a * p.x + q1.b * p.y - q1.c) * (q2.a * p.x + q2.b * p.y - q2.c)) < 0;
}

int main() {
    point p1, p2;
    double w1, h1, w2, h2, a1, a2;
    cout << "** 1st RECTANGLE **\n";
    cout << "(x, y) coordinate: ";
    cin >> p1.x >> p1.y;
    cout << "width: ";
    cin >> w1;
    cout << "height: ";
    cin >> h1;
    cout << "angle: ";
    cin >> a1;
    cout << "\n** 2nd RECTANGLE **\n";
    cout << "(x, y) coordinate: ";
    cin >> p2.x >> p2.y;
    cout << "width: ";
    cin >> w2;
    cout << "height: ";
    cin >> h2;
    cout << "angle: ";
    cin >> a2;
    point e1, e2, e3, e4;
    point e5, e6, e7, e8;
    e1 = p1;
    e2 = shift_point(p1, w1, a1);
    e3 = shift_point(e2, h1, a1 + 90);
    e4 = shift_point(p1, h1, a1 + 90);
    e5 = p2;
    e6 = shift_point(p2, w2, a2);
    e7 = shift_point(e6, h2, a2 + 90);
    e8 = shift_point(p2, h2, a2 + 90);
    bool overlap = false;
    overlap |= is_bt(e1, e2, e5, e6);
    overlap |= is_bt(e1, e2, e6, e7);
    overlap |= is_bt(e1, e2, e7, e8);
    overlap |= is_bt(e1, e2, e8, e5);
    overlap |= is_bt(e2, e3, e5, e6);
    overlap |= is_bt(e2, e3, e6, e7);
    overlap |= is_bt(e2, e3, e7, e8);
    overlap |= is_bt(e2, e3, e8, e5);
    overlap |= is_bt(e3, e4, e5, e6);
    overlap |= is_bt(e3, e4, e6, e7);
    overlap |= is_bt(e3, e4, e7, e8);
    overlap |= is_bt(e3, e4, e8, e5);
    overlap |= is_bt(e1, e4, e5, e6);
    overlap |= is_bt(e1, e4, e6, e7);
    overlap |= is_bt(e1, e4, e7, e8);
    overlap |= is_bt(e1, e4, e8, e5);
    overlap |= is_bt(e1, lineTo(e5, e6), lineTo(e7, e8)) && is_bt(e1, lineTo(e6, e7), lineTo(e5, e8));
    overlap |= is_bt(e5, lineTo(e1, e2), lineTo(e3, e4)) && is_bt(e5, lineTo(e2, e3), lineTo(e1, e4));
    if (overlap) cout << "Two rectangles have overlap!";
    else cout << "Two rectangles don't have overlap!";

}
