#include <iostream>
#include <fstream>
using namespace std;

int x[3] = {0};
int y[3] = {0};
int z[3] = {0};
int k[3] = {0};

int modifier = 1;
int sign = 1;
int cof = 0;
bool cof_set = false;

void push(int &k)
{
    k += cof * modifier * sign;
    modifier = 1;
    cof = 0;
    cof_set = false;
}

void load_equation(string s, int &x, int &y, int &z, int &k)
{
    modifier = 1;
    sign = 1;
    cof = 0;
    cof_set = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') continue;
        if (s[i] == '=')
        {
            modifier *= -1;
            push(k);
            sign = -1;
            continue;
        }
        if (s[i] == '+')
        {
            modifier *= -1;
            push(k);
            continue;
        }
        if (s[i] == '-')
        {
            modifier *= -1;
            push(k);
            modifier *= -1;
            continue;
        }
        if (s[i] == 'x')
        {
            if (!cof && !cof_set) cof = 1;
            push(x);
            continue;
        }
        if (s[i] == 'y')
        {
            if (!cof && !cof_set) cof = 1;
            push(y);
            continue;
        }
        if (s[i] == 'z')
        {
            if (!cof && !cof_set) cof = 1;
            push(z);
            continue;
        }
        cof *= 10;
        cof += (s[i] - '0');
        cof_set = true;
    }
    modifier *= -1;
    push(k);
}

int get_det() {
    int a1 = x[0];
    int b1 = y[0];
    int c1 = z[0];
    int a2 = x[1];
    int b2 = y[1];
    int c2 = z[1];
    int a3 = x[2];
    int b3 = y[2];
    int c3 = z[2];
    return a1*(b2*c3 - b3*c2) - a2*(b1*c3 - b3*c1) + a3*(b1*c2-b2*c1);
}
int get_detx() {
    int a1 = k[0];
    int b1 = y[0];
    int c1 = z[0];
    int a2 = k[1];
    int b2 = y[1];
    int c2 = z[1];
    int a3 = k[2];
    int b3 = y[2];
    int c3 = z[2];
    return a1*(b2*c3 - b3*c2) - a2*(b1*c3 - b3*c1) + a3*(b1*c2-b2*c1);
}
int get_dety() {
    int a1 = x[0];
    int b1 = k[0];
    int c1 = z[0];
    int a2 = x[1];
    int b2 = k[1];
    int c2 = z[1];
    int a3 = x[2];
    int b3 = k[2];
    int c3 = z[2];
    return a1*(b2*c3 - b3*c2) - a2*(b1*c3 - b3*c1) + a3*(b1*c2-b2*c1);
}
int get_detz() {
    int a1 = x[0];
    int b1 = y[0];
    int c1 = k[0];
    int a2 = x[1];
    int b2 = y[1];
    int c2 = k[1];
    int a3 = x[2];
    int b3 = y[2];
    int c3 = k[2];
    return a1*(b2*c3 - b3*c2) - a2*(b1*c3 - b3*c1) + a3*(b1*c2-b2*c1);
}

int main()
{
    string file_name;
    ifstream file;
    cout << "Please enter the input file name: ";
    while (true)
    {
        cin >> file_name;
        file.open(file_name);
        if (!file)
        {
            cout << "File could not be opened, please enter again: ";
            continue;
        }
        break;
    }

    string s;
    for (int i = 0; i < 3; i++)
    {
        getline(file, s);
        load_equation(s, x[i], y[i], z[i], k[i]);
    }

    double d = get_det();
    double dx = get_detx();
    double dy = get_dety();
    double dz = get_detz();

    if (d == 0) {
        if (dx == 0 && dy == 0 && dz == 0) {
            cout << "Nontrivial solution, infinitely solutions or no solution";
            return 0;
        }
        cout << "Nontrivial solution, no solution";
    } else {
        double x = dx / d;
        double y = dy / d;
        double z = dz / d;
        cout << "Trivial solution, x = "<<x<<", y = "<<y<<", z = "<<z;
    }

}
