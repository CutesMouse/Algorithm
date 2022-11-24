#include <iostream>
#include <cmath>
using namespace std;
int A,B,C,D;

void modify(int &num, int pos, int after)
{
    pos = 3 - pos;
    int nw = 0;
    int num_copy = num;
    for (int i = 0; i < 4; i++)
    {
        if (pos == i) nw += after;
        else nw += (num_copy/((int) pow(10,3-i)))%10;
        nw *= 10;
    }
    num = nw/10;
}

bool is_valid(int k)
{
    if (k < 0 || k >= 1112) return false;
    for (int i = 0; i < 4; i++)
    {
        int n = k%10;
        if (n != 0 && n != 1) return false;
    }
    return true;
}

int get_status(int num, int pos)
{
    switch (pos)
    {
    case 3:
        return (num/1000);
    case 2:
        return (num/100)%10;
    case 1:
        return (num/10)%10;
    }
    return num%10;
}

void demorgan(int &num)
{
    for (int i = 0; i < 4; i++)
    {
        modify(num,i,!get_status(num,i));
    }
}

int cancel_bubble()
{
    int cnt = 0;
    if (!get_status(B,0) && !get_status(C,1))
    {
        cnt ++;
        modify(B,0,1);
        modify(C,1,1);
    }
    if (!get_status(C,0) && !get_status(D,1))
    {
        cnt ++;
        modify(C,0,1);
        modify(D,1,1);
    }
    if (!get_status(A,0) && !get_status(D,2))
    {
        cnt ++;
        modify(A,0,1);
        modify(D,2,1);
    }
    return cnt;
}

int main()
{
    while (true)
    {
        cout << "Please enter the type of the black box A: ";
        cin >> A;
        if (is_valid(A))
        {
            break;
        }
        else cout << "Wrong input!!! Please enter again!!!\n";
    }
    while (true)
    {
        cout << "Please enter the type of the black box B: ";
        cin >> B;
        if (is_valid(B))
        {
            break;
        }
        else cout << "Wrong input!!! Please enter again!!!\n";
    }
    while (true)
    {
        cout << "Please enter the type of the black box C: ";
        cin >> C;
        if (is_valid(C))
        {
            break;
        }
        else cout << "Wrong input!!! Please enter again!!!\n";
    }
    while (true)
    {
        cout << "Please enter the type of the black box D: ";
        cin >> D;
        if (is_valid(D))
        {
            break;
        }
        else cout << "Wrong input!!! Please enter again!!!\n";
    }
    int b = cancel_bubble();
    if (b)
    {
        cout << "Wire has two bubbles!\nCanceling out the bubbles...\n";
    }
    else cout << "There isn't any wire has two bubbles!\n";

    int blocks;
    while (true)
    {
        cout << "How many black box do you want to implement the De Morgan's laws? ";
        cin >> blocks;
        if (blocks >= 1 && blocks <= 50)
        {
            break;
        }
        else cout << "Wrong input!!! Please enter again!!!\n";
    }
    for (int i = 0; i < blocks; i++)
    {
        char modify;
        while (true)
        {
            bool ed = true;
            cout << "Please enter the black box you want to modify: ";
            cin >> modify;
            switch(modify)
            {
            case 'A':
                demorgan(A);
                break;
            case 'B':
                demorgan(B);
                break;
            case 'C':
                demorgan(C);
                break;
            case 'D':
                demorgan(D);
                break;
            default:
                cout << "The black box doesn't exist!!!\n";
                ed = false;
            }
            if (ed) break;
        }
        cancel_bubble();
        cout << "After the De Morgan's laws:\n";
        printf("A: %04d\nB: %04d\nC: %04d\nD: %04d\n",A,B,C,D);
    }
}

