#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int domin_pts[256];
    int normal_pts[256];

    domin_pts['A'] = 11;
    normal_pts['A'] = 11;
    domin_pts['K'] = 4;
    normal_pts['K'] = 4;
    domin_pts['Q'] = 3;
    normal_pts['Q'] = 3;
    domin_pts['J'] = 20;
    normal_pts['J'] = 2;
    domin_pts['T'] = 10;
    normal_pts['T'] = 10;
    domin_pts['9'] = 14;
    normal_pts['9'] = 0;
    domin_pts['8'] = 0;
    normal_pts['8'] = 0;
    domin_pts['7'] = 0;
    normal_pts['7'] = 0;


    int N;
    char domin;
    string card;
    cin >> N;
    cin >> domin;
    N *= 4;
    int pts = 0;
    while (N--) {
        cin >> card;
        if (card[1] == domin) pts += domin_pts[card[0]];
        else pts += normal_pts[card[0]];
    }
    cout << pts;

}
