#include <iostream>
#include <cmath>
using namespace std;

int like = 0;
int dislike = 0;
int petals = 0;
void plucking(int times, bool status) {
    if (times < 0) return;
    if (times == 0) {
        if (status) like++;
        else dislike++;
        return;
    }
    plucking(times-1,!status);
    plucking(times-2,!status);

}

int main() {
    cout << "Please enter the number of petals: \n";
    cin >> petals;

    if (petals) plucking(petals,0);

    int times = like+dislike;

    if (times == 1 || times == 0) cout << "There is "<<times<<" way to pluck petals.\n";
    else cout << "There are "<<times<<" ways to pluck petals.\n";

    if (like == 1 || like == 0) cout << "And "<<like<<" of them is \"like\".\n";
    else cout << "And "<<like<<" of them are \"like\".\n";

    double pos = ((double) like) / (times);
    pos = round(pos * 100) / 100;
    if ((like) == 0) cout << "The probability of \"like\" is 0.";
    else cout << "The probability of \"like\" is "<<pos<<".";
}

