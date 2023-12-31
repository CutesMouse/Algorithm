#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int l;
    string output_file;
    ofstream out;
    cout << "Enter the length of the edge: ";
    while (true) {
        cin >> l;
        if (l > 0) break;
        cout << "Out of range!!\nPlease enter again: ";
    }
    cout << endl;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < (l - i - 1); j++) cout << " ";
        for (int j = 0; j < (2*i+1); j++) cout << "*";
        cout << endl;
    }
    for (int i = l-2; i >= 0; i--) {
        for (int j = 0; j < (l - i - 1); j++) cout << " ";
        for (int j = 0; j < (2*i+1); j++) cout << "*";
        cout << endl;
    }
    cout << "Enter the output file name: ";
    cin >> output_file;
    out.open(output_file);
        for (int i = 0; i < l; i++) {
        for (int j = 0; j < (l - i - 1); j++) out << " ";
        for (int j = 0; j < (2*i+1); j++) out << "*";
        out << endl;
    }
    for (int i = l-2; i >= 0; i--) {
        for (int j = 0; j < (l - i - 1); j++) out << " ";
        for (int j = 0; j < (2*i+1); j++) out << "*";
        out << endl;
    }
    out.close();
    cout << "Output the diamond to the " << output_file;
}
