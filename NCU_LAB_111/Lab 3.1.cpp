#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int identity;
    vector<int> pass;
    vector<int> fail;
    /*
    Please enter identity (1 for bachelor, 2 for master):
    2
    Please enter three scores:
    50
    60
    70
    */
    cout << "Please enter identity (1 for bachelor, 2 for master): \n";
    cin >> identity;
    int pass_score = (identity == 1 ? 60 : 70);
    int score;
    cout << "Please enter three scores: \n";
    for (int i = 0; i < 3; i++) {
        cin >> score;
        if (score >= pass_score) pass.push_back(score);
        else fail.push_back(score);
    }
    if (fail.size() == 0) {
        cout << "ALL PASS!!\nTotal credits (3 credits for each passed course): 9";
    } else {
        cout << "Fail:\n";
        for (auto iter = fail.begin(); iter != fail.end(); iter++) {
            cout << *iter << endl;
        }
        cout << "Total credits (3 credits for each passed course): " << pass.size() * 3;
    }

}

