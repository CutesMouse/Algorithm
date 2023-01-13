#include <iostream>
#include <cstring>
using namespace std;

void print_board(bool link[][50], int x, int y, char box_list[50])
{
    for (int l = 0; l < 2*y-1; l++)
    {
        if (l) cout << endl;
        if (!(l%2))
        {
            for (int i = 0; i < x; i++)
            {
                if (i)
                {
                    if (link[i+ (l/2) * x][i + (l/2)*x - 1]) cout << "-";
                    else cout << " ";
                }
                cout << "*";
            }
            continue;
        }
        for (int i = 0; i < x; i++)
        {
            if (link[i + (l/2) * x][i + (l/2 + 1) * x]) cout << "|";
            else cout << " ";
            if (box_list[i + (l/2) * x]) cout << box_list[i + (l/2) * x];
            else cout << " ";
        }
    }
    cout << endl;
}

int get_box_amount(bool link[50][50], int x, int y, char boxlist[50], bool turn)
{
    int sum = 0;
    for (int i = 0; i < x-1; i++)
    {
        for (int j = 0; j < y-1; j++)
        {
            int order = i + x * j;
            if (boxlist[order]) continue;
            if (link[order][order+1] && link[order][order+x] && link[order + x + 1][order + 1] && link[order + x][order + x + 1]) {
                sum ++;
                boxlist[order] = (turn ? 'B' : 'A');
            }
        }
    }
    return sum;
}

int main()
{
    int times = 0;
    bool link[50][50] = {};
    char box_list[50] = {0};
    int x, y;
    cout << "Size of board: ";
    cin >> y >> x;
    print_board(link, x, y, box_list);
    cout << endl;
    int a, b;
    bool turn = false; // false = a, true = b
    int pa = 0, pb = 0;
    int mx = y*(x-1) + x*(y-1);
    while (true) {
        if (times == mx) {
            if (pa == pb) cout << "~~Tie~~";
            else if (pa > pb) {
                cout << "A win!!!!";
            } else cout << "B win!!!!";
            return 0;
        }
        if (turn) cout << "B";
        else cout << "A";
        cout << ": ";
        cin >> a >> b;
        link[a-1][b-1] = true;
        link[b-1][a-1] = true;
        int box = get_box_amount(link, x, y, box_list, turn);
        if (box) {
            if (turn) pb+= box;
            else pa+= box;
            turn = !turn;
        }
        print_board(link, x, y, box_list);
        turn = !turn;
        printf("A= %d, B= %d\n\n", pa, pb);
        times++;
    }
}
