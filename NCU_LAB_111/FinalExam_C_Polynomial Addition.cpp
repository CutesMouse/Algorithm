#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct term {
    int cof;
    int power;
};

void mix_up(vector<term> &poly) {
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i].cof == 0) continue;
        int cof = poly[i].cof;
        for (int j = (i+1) ; j < poly.size(); j++) {
            if (poly[j].power == poly[i].power) {
                cof += poly[j].cof;
                poly[j].cof = 0;
            }
        }
        poly[i].cof = cof;
    }
}

bool comp(term &a, term &b) {
    return a.power > b.power;
}

int main()
{
    vector<term> poly;
    int x1, x2;
    int cof, p;
    cin >> x1;
    for (int i = 0; i < x1; i++) {
        cin >> cof >> p;
        poly.push_back({cof, p});
    }
    cin >> x2;
    for (int i = 0; i < x2; i++) {
        cin >> cof >> p;
        poly.push_back({cof, p});
    }
    mix_up(poly);
    sort(poly.begin(), poly.end(), comp);
    bool print = false;
    for (auto term : poly) {
        if (term.cof == 0) continue;
        print = true;
        cout << term.cof << " " << term.power << " ";
    }
    if (!print) cout << 0;
}
