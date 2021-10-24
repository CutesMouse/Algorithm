#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
short int present(char c) {
    switch(c) {
        case 'N':
            return 2;
        case 'E':
            return 3;
        case 'S':
            return 0;
        case 'W':
            return 1;

        case 'T':
            return 9;
        case 'J':
            return 10;
        case 'Q':
            return 11;
        case 'K':
            return 12;
        case 'A':
            return 13;
        default:
            return (short int) (c - '0' - 1);
    }
}
short int getPosition(char* poker) {
    short int ans = 0;
    switch (poker[0]) {
        case 'C':
            ans += 0;
            break;
        case 'D':
            ans += 13;
            break;
        case 'S':
            ans += 26;
            break;
        case 'H':
            ans += 39;
            break;
    }
    return ans + present(poker[1]);
}
char direction[4] = {'S','W','N','E'};
vector<char*> vc[4];

bool comp(char* a, char* b) {
    return getPosition(a) < getPosition(b);
}

int main() {
    char start;
    while(cin >> start) {
        if (start == '#') return 0;
        short int pos = present(start);
        pos++;
        string line;
        for (int i = 0; i < 2; i++) {
            cin >> line;
            for (int j = 0; j < 52; j += 2) {
                char *data = new char[2];
                data[0] = line.at(j);
                data[1] = line.at(j + 1);
                vc[pos % 4].push_back(data);
                pos++;
            }
        }
        for (int i = 0; i < 4; i++) {
            cout << direction[i] << ":";
            sort(vc[i].begin(), vc[i].end(), comp);
            for (int p = 0; p < vc[i].size(); p++) {
                cout << " " << vc[i][p][0] << vc[i][p][1];
            }
            vc[i].clear();
            cout << endl;
        }
    }
}
