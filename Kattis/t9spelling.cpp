#include <iostream>
#include <algorithm>

using namespace std;

int main() {
   string table[256];
   int pattern[] = {3,3,3,3,3,4,3,4};
   int ptr = 0;
   string ad;
   for (int i = 0; i < 8; i++) {
       for (int j = 0; j < pattern[i]; j++) {
           ad = "";
           ad.resize(j+1, '2'+i);
           table['a'+(ptr++)] = ad;
       }
   }
   table[' '] = "0";
   int N;
   cin >> N;
   string s;
   getline(cin, s);
   string last;
   for (int i = 0; i < N; i++) {
       last = "";
       getline(cin, s);
       cout << "Case #" << (i+1) <<": ";
       for (int j = 0; j < s.size(); j++) {
           string output = table[s[j]];
           if (!last.empty() && last[last.size()-1] == output[0]) cout << " ";
           cout << output;
           last = output;
       }
       cout << endl;
   }

}
