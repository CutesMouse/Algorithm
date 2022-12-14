#include <iostream>
using namespace std;



void load_basic_info(string *name, long long int *bets)
{
    cout << "***Welcome to Guessing Position game***\n";
    cout << "Please enter player's name: ";
    getline(cin, *name);
    cout << "Please enter your total bets: ";
    cin >> *bets;
    cout << endl;
}

int main()
{
    int treasurePosition[2][4]= {{6, 8, 7, 9}, {4, 2, 3,1}};

    string name;
    int times = 0;
    long long int bets;
    long long int option;

    int guess_side;
    int guess_number;
    long long int guess_bet;

    load_basic_info(&name,&bets);
    while (true)
    {
        if (bets <=0)
        {
            cout << "Sorry "<<name<<"~>< You need money to play this game\n";
            cout << "Thank you for your playing~\n";
            cout << "Bye~Bye~";
            return 0;
        }

        cout << "------------------------------------------------------\n";
        cout << "Player: "<<name<<"   Total bets: " << bets << endl;
        cout << endl;
        cout << "Please type 1 for right position win\n";
        cout << "Please type 2 for left position win\n";
        cout << "Please type -1 to leave: ";

        while (true)
        {
            cin >> option;
            if (option == -1)
            {
                cout << "Hi "<<name<<", thank you for your playing~\n";
                cout << "Bye~Bye~";
                return 0;
            }
            if (option != 1 && option != 2)
            {
                cout << "Wrong input !!! Please enter again: ";
                continue;
            }
            guess_side = option-1;
            break;
        }
        cout << "Please enter your bets: ";
        while (true)
        {
            cin >> option;
            if (option > bets)
            {
                cout << "You don't have "<<option<<" dollars in your bet!!! Please enter again: ";
                continue;
            }
            if (option <= 0)
            {
                cout << "Wrong input !!! Please enter again: ";
                continue;
            }
            guess_bet = option;
            break;
        }
        cout << "Please enter your guess: ";
        while (true)
        {
            cin >> option;
            if (option < 0 || option > 10)
            {
                cout << "Invalid guess!!! Please enter again: ";
                continue;
            }
            guess_number = option;
            break;
        }
        int correct = *((*(treasurePosition + (guess_side)))+(times%4));
        bool same_side = (guess_side == 0 && guess_number > correct) || (guess_side == 1 && guess_number < correct);
        times++;
        cout <<"Your guess: "<<guess_number<<", Treasure position: "<<correct<<"\n";

        if (correct == guess_number)
        {
            cout << "Congratulations !!! You won "<<guess_bet*2<<" dollars\n";
            bets += guess_bet*2;
        }
        else if (same_side)
        {
            cout << "Congratulations !!! You won "<<guess_bet<<" dollars\n";
            bets += guess_bet;
        }
        else
        {
            cout << "Oh no !!! You lost "<<guess_bet<<" dollars\n";
            bets -= guess_bet;
        }
        cout << endl;
    }

}
