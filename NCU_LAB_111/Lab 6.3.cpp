#include <iostream>
#include <cmath>
using namespace std;

int input_p;
int input_chars = 0;

char p1 = '0', p2 = '0', p3 = '0', p4 = '0', p5 = '0',
     p6 = '0', p7 = '0', p8 = '0', p9 = '0', p10 = '0',
     p11 = '0', p12 = '0', p13 = '0', p14 = '0', p15 = '0',
     p16 = '0', p17 = '0', p18 = '0', p19 = '0', p20 = '0';

long long int num;

int n_dec;

int char_to_value(char c)
{
    if (c >= '0' && c <= '9') return (c - '0');
    return (c - 'A')+10;
}

char value_to_char(int v)
{
    if (v >= 0 && v <= 9) return static_cast<char>('0' + v);
    return static_cast<char>('A' + v - 10);
}

bool is_valid_char(char c)
{
    if (input_p == 16) return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
    int n = char_to_value(c);
    return n < input_p;
}


void binary()
{
    int dec = n_dec;
    cout << "binary: ";
    int ptr = 524288;
    bool print = false;
    while (ptr)
    {
        if (dec >= ptr)
        {
            print = true;
            cout << 1;
            dec -= ptr;
        }
        else
        {
            if (print) cout << 0;
        }
        ptr /= 2;
    }
    cout << endl;
}

void octal()
{
    int dec = n_dec;
    cout << "octal: ";
    int ptr = 2097152;
    bool print = false;
    while (ptr)
    {
        if (dec >= ptr)
        {
            print = true;
            int k = (dec / ptr);
            cout << k;
            dec -= ptr * k;
        }
        else
        {
            if (print) cout << 0;
        }
        ptr /= 8;
    }
    cout << endl;
}

void hex()
{
    int dec = n_dec;
    cout << "hexadecimal: ";
    int ptr = 1048576;
    bool print = false;
    while (ptr)
    {
        if (dec >= ptr)
        {
            print = true;
            int k = (dec / ptr);
            cout << value_to_char(k);
            dec -= ptr * k;
        }
        else
        {
            if (print) cout << 0;
        }
        ptr /= 16;
    }
    cout << endl;
}


int main()
{
    while (true)
    {
        cout << "Please enter the number base: ";
        cin >> input_p;
        if (input_p == 2 || input_p == 8 || input_p == 10 || input_p == 16) break;
    }

    char ignore;
    cin.get(ignore);

    while (true)
    {
        cout << "Please enter the number: ";
        p1 = '0', p2 = '0', p3 = '0', p4 = '0', p5 = '0',
        p6 = '0', p7 = '0', p8 = '0', p9 = '0', p10 = '0',
        p11 = '0', p12 = '0', p13 = '0', p14 = '0', p15 = '0',
        p16 = '0', p17 = '0', p18 = '0', p19 = '0', p20 = '0';
        char c;
        int ptr = 0;
        while (cin.get(c))
        {
            if (ptr >= 20) break;
            if (c == '\n') break;
            switch (ptr)
            {
            case 0:
                p1 = c;
                break;
            case 1:
                p2 = c;
                break;
            case 2:
                p3 = c;
                break;
            case 3:
                p4 = c;
                break;
            case 4:
                p5 = c;
                break;
            case 5:
                p6 = c;
                break;
            case 6:
                p7 = c;
                break;
            case 7:
                p8 = c;
                break;
            case 8:
                p9 = c;
                break;
            case 9:
                p10 = c;
                break;
            case 10:
                p11 = c;
                break;
            case 11:
                p12 = c;
                break;
            case 12:
                p13 = c;
                break;
            case 13:
                p14 = c;
                break;
            case 14:
                p15 = c;
                break;
            case 15:
                p16 = c;
                break;
            case 16:
                p17 = c;
                break;
            case 17:
                p18 = c;
                break;
            case 18:
                p19 = c;
                break;
            case 19:
                p20 = c;
                break;
            }
            ptr++;
        }
        input_chars = ptr;
        if (is_valid_char(p1) && is_valid_char(p2) && is_valid_char(p3) && is_valid_char(p4) && is_valid_char(p5) &&
                is_valid_char(p6) && is_valid_char(p7) && is_valid_char(p8) && is_valid_char(p9) && is_valid_char(p10) &&
                is_valid_char(p11) && is_valid_char(p12) && is_valid_char(p13) && is_valid_char(p14) && is_valid_char(p15) &&
                is_valid_char(p16) && is_valid_char(p17) && is_valid_char(p18) && is_valid_char(p19) && is_valid_char(p20)) break;
    }
    n_dec = char_to_value(p1) * static_cast<int>(pow(input_p,input_chars-1)) +
            char_to_value(p2) * static_cast<int>(pow(input_p,input_chars-2)) +
            char_to_value(p3) * static_cast<int>(pow(input_p, input_chars-3)) +
            char_to_value(p4) * static_cast<int>(pow(input_p, input_chars-4)) +
            char_to_value(p5) * static_cast<int>(pow(input_p, input_chars-5)) +
            char_to_value(p6) * static_cast<int>(pow(input_p,input_chars-6)) +
            char_to_value(p7) * static_cast<int>(pow(input_p,input_chars-7)) +
            char_to_value(p8) * static_cast<int>(pow(input_p, input_chars-8)) +
            char_to_value(p9) * static_cast<int>(pow(input_p, input_chars-9)) +
            char_to_value(p10) * static_cast<int>(pow(input_p, input_chars-10)) +
            char_to_value(p11) * static_cast<int>(pow(input_p,input_chars-11)) +
            char_to_value(p12) * static_cast<int>(pow(input_p,input_chars-12)) +
            char_to_value(p13) * static_cast<int>(pow(input_p, input_chars-13)) +
            char_to_value(p14) * static_cast<int>(pow(input_p, input_chars-14)) +
            char_to_value(p15) * static_cast<int>(pow(input_p, input_chars-15)) +
            char_to_value(p16) * static_cast<int>(pow(input_p,input_chars-16)) +
            char_to_value(p17) * static_cast<int>(pow(input_p,input_chars-17)) +
            char_to_value(p18) * static_cast<int>(pow(input_p, input_chars-18)) +
            char_to_value(p19) * static_cast<int>(pow(input_p, input_chars-19)) +
            char_to_value(p20) * static_cast<int>(pow(input_p, input_chars-20));

    binary();
    cout << "decimal: " << n_dec << endl;
    octal();
    hex();
}
