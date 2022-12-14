#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int s;
    cout << "Please enter the amount of student: ";
    cin >> s;
    cout << "Please enter the Score of each student: \n";
    int data[s];
    for (int i = 0; i < s; i++) cin >> data[i];
    cout << "After modification, the score of each student is: \n";
    int flk = 0;
    for (int i = 0; i < s; i++) {
        double new_sc = sqrt(*(data+i)) * 10;
        cout << fixed << setprecision(3) << new_sc << " ";
        flk += (new_sc < 60);
    }
    cout << endl;
    if (flk == 1) cout << "There is still a student failed.";
    else if (flk) cout << "There are still "<<flk<<" students failed.";
    else cout << "Every student pass!!!";
}
