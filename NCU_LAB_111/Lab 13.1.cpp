#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "Please enter the input file name: ";
    string name;
    int f = 0, m = 0;
    getline(cin, name);
    ifstream reader(name, ios::in);
    while (!reader) {
        cout << "File could not be opened.\n";
        cout << "Please enter the input file name again: ";
        getline(cin, name);
        reader.open(name, ios::in);
    }
    getline(reader, name);
    getline(reader, name);
    string ignore, gender;
    while (reader >> ignore >> gender) {
        if (gender == "male") m ++;
        else f++;
    }
    printf("Total: %d\nMale: %d\nFemale: %d", m+f, m, f);
}
