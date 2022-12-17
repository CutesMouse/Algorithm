#include <iostream>
using namespace std;

int who_win(int *sets)
{
    if (*(sets) == *(sets+4) && *(sets+4) == *(sets+8)) return *sets;
    if (*(sets+2) == *(sets+4) && *(sets+4) == *(sets+6)) return *(sets+2);


    if (*sets == *(sets+1) && *(sets+1) == *(sets+2)) return *sets;
    if (*(sets+3) == *(sets+4) && *(sets+4) == *(sets+5)) return *(sets+3);
    if (*(sets+6) == *(sets+7) && *(sets+7) == *(sets+8)) return *(sets+6);


    if (*(sets+0) == *(sets+3) && *(sets+3) == *(sets+6)) return *(sets+0);
    if (*(sets+1) == *(sets+4) && *(sets+4) == *(sets+7)) return *(sets+1);
    if (*(sets+2) == *(sets+5) && *(sets+5) == *(sets+8)) return *(sets+2);
    return -1;
}

int main()
{
    int sets[9] = {0};
    char inp = 0;
    do
    {
        if (inp) cout <<endl;
        for (int i = 0 ; i < 9 ; i ++)
        {
            *(sets+i) = (-1000 + i);
        }
        cout << "*** Welcome to Tic-tac-toe game ^o^ ***\n";
        // 0 = A, 1 = B
        bool turn = 0;
        int times = 0;
        while (who_win(sets) == -1 && (times != 9))
        {
            char t = (turn ? 'B' : 'A');
            cout << "Please enter the "<<t<<" player’s selection: ";
            int sel;
            cin >> sel;
            sel--;
            *(sets+sel) = turn;
            turn = !turn;
            times++;
        }
        int w = who_win(sets);
        char t = (w ? 'B' : 'A');
        if (w == -1)
        {
            cout << "Oh NO~~~~ The game is tie.\n";
        }
        else
        {
            cout << "Congratulations! The "<<t<<" player is the Winner.\n";
        }
        cout << "Do you want to play again (y/n)? ";
        cin >> inp;
    } while (inp == 'y');
    cout << "Good-Bye!";
}
