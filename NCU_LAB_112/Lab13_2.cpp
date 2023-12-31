#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct date {
    int y;
    int m;
    int d;
};

struct user {
    string name;
    string id;
    date birthday;
};

int readNum() {
    char a, b;
    cin >> a >> b;
    return (a - '0') * 10 + (b - '0');
}

date readDate(string s) {
    int y = 0, m = 0, d = 0;
    char c;
    //cout << "read: c = " << c <<endl;
    for (int i = 0; i < 4; i++) {
        c = s.substr(i, 1)[0];
        y *= 10;
        y += c - '0';
    }
    for (int i = 0; i < 2; i++) {
        c = s.substr(i + 5, 1)[0];
        m *= 10;
        m += c - '0';
    }
    for (int i = 0; i < 2; i++) {
        c = s.substr(i + 8, 1)[0];
        d *= 10;
        d += c - '0';
    }
    return {y, m, d};
}

bool cmp(user &a, user &b) {
    if (a.birthday.m != b.birthday.m) return a.birthday.m < b.birthday.m;
    if (a.birthday.d != b.birthday.d) return a.birthday.d < b.birthday.d;
    if (a.id.size() != b.id.size()) return a.id.size() < b.id.size();
    return a.id < b.id;
}

bool nextDay(int &m, int &d) {
    int md = 0;
    switch(m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            md = 31;
            break;
        case 2:
            md = 29;
            break;
        default:
            md = 30;
            break;
    }
    d++;
    if (d > md) {
        m ++;
        d -= md;
    }
    if (m > 12) m -= 12;
    return true;
}

int main() {
    //ofstream out("out.txt");
    //cout.rdbuf(out.rdbuf());

    vector<user> users;
    ifstream in;
    string file, line;
    while (true) {
        cout << "Please enter the input file name: ";
        cin >> file;
        in.open(file);
        if (in) break;
        cout << "File could not be opened.\n";
    }
    cout << "What's the date today? (mm/dd) ";
    int m = readNum();
    cin.get();
    int d = readNum();
    cout << "\nWhose birthday is upcoming and the closest to today?\n";
    getline(in, line);
    while (getline(in, line)) {
        string name, id;
        getline(in, name);
        getline(in, id);
        getline(in, line);
        //printf("line: %s, name: %s, id: %s\n", line.c_str(), name.c_str(), id.c_str());
        date d = readDate(line);
        users.push_back({name, id, d});
    }
    sort(users.begin(), users.end(), cmp);
    do {
        //printf("searching: %02d/%02d\n", m, d);
        bool exit = false;
        for (int i = 0; i < users.size(); i++) {
            user u = users[i];
            date b = u.birthday;
            if (b.m != m || b.d != d) continue;
            printf("%s\n", u.name.c_str());
            printf("%s\n", u.id.c_str());
            printf("%04d/%02d/%02d\n\n", b.y, b.m, b.d);
            exit = true;
        }
        if (exit) break;
    } while (nextDay(m, d));
}
