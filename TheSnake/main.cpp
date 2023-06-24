#include <iostream>
#include <iomanip>
#include "Game.h"

using namespace std;

int main() {
    srand(time(0));
    Game game;
    game.game_thread();
    return 0;
}
