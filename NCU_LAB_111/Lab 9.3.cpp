#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long int a = 0, b = 0;
string s;
int modifier = 1;
int sign = 1;
long long int cof = 0;
bool cof_set = false;

void push(long long int &k)
{
    k += cof * modifier * sign;
    modifier = 1;
    cof = 0;
    cof_set = false;
}

int main()
{
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') continue;
        if (s[i] == '=')
        {
            modifier *= -1;
            push(b);
            sign = -1;
            continue;
        }
        if (s[i] == '+')
        {
            modifier *= -1;
            push(b);
            continue;
        }
        if (s[i] == '-')
        {
            modifier *= -1;
            push(b);
            modifier *= -1;
            continue;
        }
        if (s[i] == 'x')
        {
            if (!cof && !cof_set) cof = 1;
            push(a);
            continue;
        }
        cof *= 10;
        cof += (s[i] - '0');
        cof_set = true;
    }
    modifier *= -1;
    push(b);
    if (a == 0)
    {
        if (b == 0)
        {
            cout << "Identity";
            return 0;
        }
        cout << "Impossible";
        return 0;
    }
    cout << (b/a);
}
