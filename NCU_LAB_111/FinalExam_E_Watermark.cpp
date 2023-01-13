#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void print_number(int a)
{
    int k = 128;
    while (k > 0)
    {
        if (a >= k)
        {
            cout << 1;
            a -= k;
        } else cout << 0;
        k /= 2;
    }
}

void add_watermark(int &a, int replace_data) {
    if (replace_data == -1) return;
    if (a >= 128) a-= 128;
    a += (128 * replace_data);
}

int main()
{

    int dx, dy;

    int rx, ry;
    ifstream info, crypt;
    string fileName;
    cout << "Please enter the input file name: ";
    while (true)
    {
        cin >> fileName;
        info.open(fileName);
        if (!info)
        {
            cout << "File could not be opened. Please enter the input file name again: ";
            continue;
        }
        break;
    }
    info >> dx >> dy;
    int data[dx][dy];

    for (int i = 0; i < dx; i++) {
        for (int j = 0; j < dy; j++) {
            info >> data[i][j];
        }
    }
    cout << "Please enter the input file name: ";
    while (true)
    {
        cin >> fileName;
        crypt.open(fileName);
        if (!crypt)
        {
            cout << "File could not be opened. Please enter the input file name again: ";
            continue;
        }
        break;
    }
    crypt >> rx >> ry;
    int replace_data[dx*2][dy*2];
    memset(replace_data, -1, sizeof(replace_data));
    cout << "Enter the coordinate of the starting point: ";
    int x, y;
    while (true) {
        cin >> x >> y;
        if (x <= 0 || y <= 0 || x > dx || y > dy) {
            cout << "Invalid input! Please enter another starting point: ";
            continue;
        }
        break;
    }
    x--;
    y--;
    for (int i = 0; i < rx; i++) {
        for (int j = 0; j < ry; j++) {
            crypt >> replace_data[i+x][j+y];
        }
    }
    for (int i = 0; i < dx; i++) {
        for (int j = 0; j < dy; j++) {
            add_watermark(data[i][j], replace_data[i][j]);
            print_number(data[i][j]);
            cout << " ";
        }
        cout <<endl;
    }
    /*
    -1 -10
    1 1
    01111111 01111111 11111111 11111111
    01111111 01111111 11111111 11111111
    11111111 11111111 11111111 11111111
    11111111 11111111 11111111 11111111
    */



}
