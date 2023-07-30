#include <iostream>
using namespace std;

int main()
{
    const int TABLE_SIZE = 10000;
    int hashtable[TABLE_SIZE] = {0};
    string word;
    while (cin >> word) {
        int hashcode = 0;
        for (int i = 0; i < word.length(); i++) {
            char c = word.at(i);
            int val = c - 'A'+1;
            hashcode = (hashcode * 26 + val) % TABLE_SIZE;
        }
        //cout << hashcode;
        hashtable[hashcode] ++;
    }
    for (int i = 0; i < TABLE_SIZE ; i++) {
        if (hashtable[i] >= 2) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
}