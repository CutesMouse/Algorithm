//
// Created by user on 2023/6/24.
//

#ifndef THESNAKE_GAME_H
#define THESNAKE_GAME_H

#include "Stack.cpp"
#include "LinkedList.cpp"

typedef std::pair<int, int> pos;

class Game {
private:
    int mark = 0;
    int step = 0;
    bool lose = false;
    char plot[10][10];
    Stack<char> stomach;
    LinkedList<pos> snake;

    std::string stomach_to_string();

    int food_counter = 0;

public:
    void print_screen();
    void game_thread();
    void init_snake();
    void generate_food();
    void consume(char c);
    void render_snake();
};


#endif //THESNAKE_GAME_H
