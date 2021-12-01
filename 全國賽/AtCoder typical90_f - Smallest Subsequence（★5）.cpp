#include <iostream>
#include <queue>
using namespace std;
queue<int> table[26];
int main()
{
    int N,K;
    cin >> N >> K;
    string s;
    cin >> s;
    for (int i = 0; i < N; i ++)
    {
        char c = s[i];
        int pos = c - 'a';
        table[pos].emplace(i);
    }
    int current = 0;
    int last = -1;
    for (int i = 0; i < K; i++)
    {
        if (current == K) break;
        for (int l = 0; l < 26; l++)
        {
            if (table[l].empty()) continue;
            int pos = table[l].front();
            while (pos < last)
            {
                table[l].pop();
                if (table[l].empty())
                {
                    pos = -1;
                    break;
                }
                pos = table[l].front();
            }
            if (pos == -1) continue;
            if (N - pos >= (K-current))
            {
                last = pos;
                current++;
                table[l].pop();
                cout << (char) (l + 'a');
                break;
            }
        }
    }
    cout << endl;
}
