#include <iostream>

using namespace std;

bool A_con = false, B_con = false, C_con = false;
char A = 'I', B = 'I', C = 'I';

void redecide_consciousness()
{
    cout << "Hi robots, do you have your own consciousness? (Y/N): ";
    char input;
    cin >> input;
    A_con = (input == 'Y');
    cin >> input;
    B_con = (input == 'Y');
    cin >> input;
    C_con = (input == 'Y');

    if (A_con || B_con || C_con) cout << "Hi robots, what would you like to do? ";
    if (A_con)
    {
        cin >> A;
    }
    if (B_con)
    {
        cin >> B;
    }
    if (C_con)
    {
        cin >> C;
    }
}

char ask_which_to_control()
{
    cout << "Hi human, which robot would you like to control? (A/B/C): ";
    char input;
    cin >> input;
    return input;
}

char Human_operation_Robot_without_consciousness()
{
    char input;
    cout << "Hi human, what would you like the robot to do? ";
    cin >> input;
    return input;
}

void Human_operation_Robot_with_consciousness()
{
    char ignore;
    cout << "Hi human, what would you like the robot to do? ";
    cin >> ignore;
}

void print_robot_status(char A, char B, char C)
{
    cout <<"robotA: "<<A<<"\nrobotB: "<<B<<"\nrobotC: "<<C<<"\n";
}



int main()
{
    while (true)
    {
        redecide_consciousness();
        char funct;
        bool ed = false;
        while (true)
        {
            funct = ask_which_to_control();
            switch (funct)
            {
            case 'A':
                if (A_con) Human_operation_Robot_with_consciousness();
                else A = Human_operation_Robot_without_consciousness();
                break;
            case 'B':
                if (B_con) Human_operation_Robot_with_consciousness();
                else B = Human_operation_Robot_without_consciousness();
                break;
            case 'C':
                if (C_con) Human_operation_Robot_with_consciousness();
                else C = Human_operation_Robot_without_consciousness();
                break;
            case 'R':
                break;
            default:
                cout << "Illegal input, end of control!";
                ed = true;
                break;
            }
            if (ed) break;
            if (funct == 'R') break;
            print_robot_status(A,B,C);
        }
        if (funct == 'R') continue;
        if (ed) return 0;
    }


    /*
    Hi human, which robot would you like to control? (A/B/C): A
    Hi human, what would you like the robot to do? E
    robotA: E
    robotB: S
    robotC: I
    Hi human, which robot would you like to control? (A/B/C): B
    Hi human, what would you like the robot to do? W
    robotA: E
    robotB: S
    robotC: I
    Hi human, which robot would you like to control? (A/B/C): R
    Hi robots, do you have your own consciousness? (Y/N): N N N
    Hi human, which robot would you like to control? (A/B/C): B
    Hi human, what would you like the robot to do? W
    robotA: E
    robotB: W
    robotC: I
    Hi human, which robot would you like to control? (A/B/C): R
    Hi robots, do you have your own consciousness? (Y/N): Y Y Y
    Hi robots, what would you like to do? W E S
    Hi human, which robot would you like to control? (A/B/C): C
    Hi human, what would you like the robot to do? N
    robotA: W
    robotB: E
    robotC: S
    Hi human, which robot would you like to control? (A/B/C): Q
    Illegal input, end of control!

    */
}
