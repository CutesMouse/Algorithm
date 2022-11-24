#include <iostream>
#include <cmath>
using namespace std;

char c0,c1,c2,c3;
char k0,k1,k2,k3;
int k0_, k1_, k2_, k3_;
int n;
int KEY1, KEY2;

bool get_bit(int num, int n)
{
    return (num >> n) % 2;
}

int swap_bit(int num, int a, int b)
{
    int copy_num = num;
    int na = get_bit(num,b);
    int nb = get_bit(num,a);
    num = 0;
    for (int i = 7 ; i >= 0; i--)
    {
        bool current = get_bit(copy_num,i);
        if (i == a) current = na;
        if (i == b) current = nb;
        if (current) num = num | 1;
        num = (num << 1);
    }
    return (num >> 1);
}

void genk_()
{
    k0_ = k0;
    k1_ = k1;
    k2_ = k2;
    k3_ = k3;
    if (get_bit(k1,3)) k0_ = swap_bit(k0_,0,2);
    if (get_bit(k1,4)) k0_ = swap_bit(k0_,5,7);
    if (get_bit(k2,3)) k1_ = swap_bit(k1_,0,2);
    if (get_bit(k2,4)) k1_ = swap_bit(k1_,5,7);
    if (get_bit(k3,3)) k2_ = swap_bit(k2_,0,2);
    if (get_bit(k3,4)) k2_ = swap_bit(k2_,5,7);
    if (get_bit(k0,3)) k3_ = swap_bit(k3_,0,2);
    if (get_bit(k0,4)) k3_ = swap_bit(k3_,5,7);
}

int main()
{
    int mode;
    cout << "Enter 1 to encrypt the text, or enter 0 to decrypt the number sequence: ";
    cin >> mode;
    if (mode)
    {
        cout << "Enter 4 chars: ";
        cin >> c0;
        cin >> c1;
        cin >> c2;
        cin >> c3;
        cout <<"Enter 4 keys(char): ";
        cin >> k0;
        cin >> k1;
        cin >> k2;
        cin >> k3;
        genk_();
        KEY1 = (k0_<<8) + k1_;
        KEY2 = (k2_<<8) + k3_;
        n = (KEY1^KEY2)%128;
        int L = (((int) c0) << 8) + ((int) c1);
        int R = (((int) c2) << 8) + ((int) c3);
        for (int i = 0; i <= n; i++)
        {
            int NL, NR;
            int KEY = (i%2) ? KEY2 : KEY1;
            int MODE;
            switch (i % 4)
            {
            case 0:
                MODE = k0_%4;
                break;
            case 1:
                MODE = k1_%4;
                break;
            case 2:
                MODE = k2_%4;
                break;
            case 3:
                MODE = k3_%4;
                break;
            }
            NL = R;
            switch (MODE)
            {
            case 0:
                NR = KEY ^ R;
                break;
            case 1:
                NR = KEY | R;
                break;
            case 2:
                NR = KEY & R;
                break;
            case 3:
                NR = (((R>>8)%(KEY>>8))<<8) + ((R%256) % (KEY%256));
                break;
            }
            R = NR ^ L;
            L = NL;
        }

        cout << "Encrypted numbers: ";
        cout << (L>>8) << " " << (L % 256) << " ";
        cout << (R>>8) <<" " << (R % 256);
    }
    else
    {
        cout << "Enter 4 encrypted numbers: ";
        int i0, i1, i2, i3;
        cin >> i0 >> i1 >> i2 >> i3;
        cout <<"Enter 4 keys(char): ";
        cin >> k0;
        cin >> k1;
        cin >> k2;
        cin >> k3;
        genk_();
        KEY1 = (k0_<<8) + k1_;
        KEY2 = (k2_<<8) + k3_;
        n = (KEY1^KEY2)%128;
        int L = (((int) i0) << 8) + ((int) i1);
        int R = (((int) i2) << 8) + ((int) i3);
        for (int i = n; i >= 0; i--)
        {
            int NL, NR;
            int KEY = (i%2) ? KEY2 : KEY1;
            int MODE;
            switch (i % 4)
            {
            case 0:
                MODE = k0_%4;
                break;
            case 1:
                MODE = k1_%4;
                break;
            case 2:
                MODE = k2_%4;
                break;
            case 3:
                MODE = k3_%4;
                break;
            }
            NR = L;
            switch (MODE)
            {
            case 0:
                NL = KEY ^ NR;
                break;
            case 1:
                NL = KEY | NR;
                break;
            case 2:
                NL = KEY & NR;
                break;
            case 3:
                NL = (((NR>>8)%(KEY>>8))<<8) + ((NR%256) % (KEY%256));
                break;
            }
            L = R ^ NL;
            R = NR;
        }
        cout << "Text: ";
        cout << static_cast<char>(L>>8);
        cout << static_cast<char>(L % 256);
        cout << static_cast<char>(R>>8);
        cout << static_cast<char>(R % 256);

    }
}
