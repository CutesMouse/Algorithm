#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int parseInt(string &s);
vector<string> split(string s, string spliter);

// assert v.size() != 0
template<class T>
T last(vector<T> &v) {
    return *(v.end()-1);
}
template<class T>
bool same(vector<T> &v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i-1] != v[i]) return false;
    }
    return true;
}

class Problem {
public:
    int bots;
    vector<vector<string>> bottles;
    void print() {
        for (int i = 0; i < bots; i+=5) {
            int from = i;
            int to = min(i+5, bots);
            for (int j = from; j < to; j++) {
                cout << "No." << setw(7) << left << (j+1) << "    ";
            }
            cout << endl;
            for (int k = 3; k >= 0; k--) {
                for (int j = from; j < to; j++) {
                    if (bottles[j].size() <= k) cout << "|        |";
                    else cout << "|--------|";
                    cout << "    ";
                }
                cout << endl;
                for (int j = from; j < to; j++) {
                    string color = (bottles[j].size() <= k ? "" : bottles[j][k]);
                    cout << "|" << setw(8) << left << color << "|" << "    ";
                }
                cout << endl;
            }
            for (int j = from; j < to; j++) {
                cout << "|========|" << "    ";
            }
            cout << endl << endl;
        }
    }

    // 0: valid move
    // 1: invalid due to full "to" bottle
    // 2: invalid due to empty "from" bottle
    // 3: invalid due to not sharing the same top layer color
    int is_invalid_move(int from, int to) {
        if (bottles[from].empty()) return 2;
        if (bottles[to].size() == 4) return 1;
        if (bottles[to].empty()) return 0;
        if (last(bottles[from]) != last(bottles[to])) return 3;
        return 0;
    }

    bool check_legal_sol_exist() {
        for (int f = 0; f < bots; f++) {
            for (int t = 0; t < bots; t++) {
                if (f == t) continue;
                if (!is_invalid_move(f, t)) return true;
            }
        }
        return false;
    }

    bool win() {
        for (int i = 0; i < bots; i++) {
            if (bottles[i].size() != 4 && !bottles[i].empty()) return false;
            if (!same(bottles[i])) return false;
        }
        return true;
    }
    // assert it's a valid move
    void move_bottle(int f, int t) {
        while (!is_invalid_move(f, t)) {
            bottles[t].push_back(last(bottles[f]));
            bottles[f].resize(bottles[f].size() - 1);
        }
    }
};

Problem probs[100];

int num;

bool load_file(string name) {
    ifstream file(name);
    if (!file) return false;
    string line;
    file >> line >> num;
    while (file >> line) {
        int prob, bots;
        file >> prob >> line >> bots;
        probs[prob].bots = bots;
        probs[prob].bottles.resize(bots);
        for (int i = 0; i < bots; i++) {
            file >> line;
            if (line == "-") continue;
            probs[prob].bottles[i] = split(line, "/");
        }
    }
    return true;
}

int main() {
    /*ifstream in("2.in");
    ofstream out("out.txt");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());*/

    string file;
    while (true) {
        cout << "Please enter the input file name: ";
        cin >> file;
        if (load_file(file)) break;
        cout << "File could not be opened.\n";
    }
    int prob;
    while (true) {
        cout << "Which problem do you want? (1~" << num << ") ";
        cin >> prob;
        if (prob > 0 && prob <= num) break;
        cout << "Out of range! Please enter again!\n";
    }
    cout << "\n*** Start the game ***\n";
    Problem problem = probs[prob];
    while (true) {
        problem.print();
        if (problem.win()) {
            cout << "Good Bye!";
            break;
        }
        if (!problem.check_legal_sol_exist()) {
            cout << "There isn't any legal move now!\n";
            string again;
            while(true) {
                cout << "Do you want to try this problem again? (y/n) ";
                cin >> again;
                if (again == "y" || again == "n") break;
                cout << "Input Error! Please enter again!\n";
            }
            if (again == "y") {
                cout << "\n*** Start the game ***\n";
                problem = probs[prob];
                continue;
            }
            cout << "Good Bye!";
            break;
        }
        string a;
        int f, t;
        while (true) {
            cout << "the bottle from/to: ";
            cin >> a;
            if (a == "back") break;
            f = parseInt(a);
            cin >> t;
            f--, t--;
            int ec = problem.is_invalid_move(f, t);
            if (!ec) break;
            switch (ec) {
                case 1:
                    cout << "The bottle No." << t+1 << " is full!\n\n";
                    break;
                case 2:
                    cout << "The bottle No." << f+1 << " is empty!\n\n";
                    break;
                case 3:
                    cout << "Different colors on the top. Fail to move the water!\n\n";
                    break;
            }
        }
        if (a != "back") problem.move_bottle(f, t);
        else {
            cout << "\n*** Start the game ***\n";
            problem = probs[prob];
        }
    }
}

int parseInt(string &s) {
    int val = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') continue;
        val *= 10;
        val += s[i] - '0';
    }
    return val;
}

vector<string> split(string s, string spliter) {
    vector<string> ans;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, spliter.size()) == spliter) {
            ans.push_back(temp);
            temp = "";
            i += (spliter.size() - 1);
            continue;
        }
        temp += s[i];
    }
    ans.push_back(temp);
    return ans;
}
