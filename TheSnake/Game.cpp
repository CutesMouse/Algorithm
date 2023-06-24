//
// Created by user on 2023/6/24.
//

#include "Game.h"
#include <iostream>

using namespace std;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const char food_type[8] = {'[', ']', '{', '}', '(', ')', '\"', '\''};

void Game::print_screen() {
    cout << endl;
    if (lose) cout << "--- Game Over ---" << endl;
    cout << "Mark: " << mark << endl;
    cout << "Step: " << step << endl;
    cout << "Size: " << snake.getSize() << endl;
    cout << endl;
    if (lose) return;
    cout << "Stomach Stack (" << stomach.getSize() << "/5): " << stomach_to_string() << endl;
    cout << "from bottom to top" << endl;
    cout << endl;
    cout << "  - - - - - - - - - -" << endl;
    for (int y = 0; y < 10; y++) {
        cout << "| ";
        for (int x = 0; x < 10; x++) {
            cout << plot[x][y] << " ";
        }
        cout << "|" << endl;
    }
    cout << "  - - - - - - - - - -" << endl;
    cout << endl;
    cout << "Control the snake (a,s,d,w): ";
}

void Game::game_thread() {
    init_snake();
    char move;
    while (true) {
        print_screen();
        if (lose) break;
        cin >> move;
        step++;
        mark++;
        food_counter++;
        int direction;
        switch (move) {
            case 'w':
                direction = 0;
                break;
            case 'a':
                direction = 1;
                break;
            case 's':
                direction = 2;
                break;
            case 'd':
                direction = 3;
                break;
            default:
                direction = 0;
                break;
        }
        auto first = snake.at(0);
        auto last = snake.getLast();

        first.first += dx[direction];
        first.second += dy[direction];
        snake.insert_front(first);
        auto fill = plot[first.first][first.second];
        if (fill != 'o' && fill != 'O' && fill != ' ') {
            consume(fill);
        } else {
            snake.remove_last();
        }

        if (first.first < 0 || first.second < 0 || first.first >= 10 || first.second >= 10
            || plot[first.first][first.second] == 'O' || plot[first.first][first.second] == 'o') {
            lose = true;
            continue;
        }

        plot[first.first][first.second] = 'O';
        plot[last.first][last.second] = ' ';
        render_snake();

        generate_food();
        cout << endl;
    }
}

string Game::stomach_to_string() {
    string builder = stomach.to_string();
    for (int i = stomach.getSize(); i < 5; i++) builder += "_ ";
    return builder;
}

void Game::init_snake() {
    snake.add({2, 0});
    snake.add({1, 0});
    snake.add({0, 0});

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            plot[x][y] = ' ';
        }
    }
    render_snake();
}

void Game::render_snake() {
    auto last = snake.getLastNode();
    while (last != nullptr) {
        pos p = last->value;
        last = last->last;
        plot[p.first][p.second] = (last == nullptr) ? 'O' : 'o';
    }
}

void Game::generate_food() {
    if (food_counter >= 1 && food_counter <= 28) {
        if (food_counter % 3 != 1) return;
    }
    if (food_counter >= 30 && food_counter <= 48){
        if (food_counter %2 != 0) return;
    }
    vector<int> pool;
    for (int i = 0; i < 100; i++) {
        int x = i % 10;
        int y = i / 10;
        if (plot[x][y] == ' ') pool.emplace_back(i);
    }
    if (pool.empty()) return;
    int blank = pool[rand() % pool.size()];
    char type = food_type[rand() % 8];
    plot[blank%10][blank/10] = type;
}

void Game::consume(char food) {
    mark += 3;
    if (stomach.empty()) {
        stomach.push(food);
        return;
    }
    int weight = 0;
    char matchfood;
    switch (food) {
        case ']':
            matchfood = '[';
            weight = 8;
            break;
        case '}':
            matchfood = '{';
            weight = 8;
            break;
        case ')':
            matchfood = '(';
            weight = 8;
            break;
        case '\'':
        case '\"':
            matchfood = food;
            weight = 5;
            break;
        default:
            matchfood = 0;
    }
    if (stomach.top() == matchfood) {
        stomach.pop();
        mark += weight;
    } else {
        stomach.push(food);
    }
    if (stomach.getSize() > 5) {
        lose = true;
    }
}
