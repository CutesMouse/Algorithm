#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string convert[256];
    convert['a'] = "@";
    convert['b'] = "8";
    convert['c'] = "(";
    convert['d'] = "|)";
    convert['e'] = "3";
    convert['f'] = "#";
    convert['g'] = "6";
    convert['h'] = "[-]";
    convert['i'] = "|";
    convert['j'] = "_|";
    convert['k'] = "|<";
    convert['l'] = "1";
    convert['m'] = "[]\\/[]";
    convert['n'] = "[]\\[]";
    convert['o'] = "0";
    convert['p'] = "|D";
    convert['q'] = "(,)";
    convert['r'] = "|Z";
    convert['s'] = "$";
    convert['t'] = "\'][\'";
    convert['u'] = "|_|";
    convert['v'] = "\\/";
    convert['w'] = "\\/\\/";
    convert['x'] = "}{";
    convert['y'] = "`/";
    convert['z'] = "2";

    string line;
    string nline;
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
        char c = line[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if (convert[c].empty()) nline += c;
        else nline += convert[c];
    }
    cout << nline;
}
