//
// Created by at991 on 8/22/2023.
//

#include "Game.h"
#include <iostream>

int Game::fails = 0, Game::tries = 0;
bool Game::valid_input = 1, Game::wrong_ans = 0;

void Game::play(Board &board) {
    valid_input = 1, wrong_ans = 0;
    tries++;
    std::cin >> x >> y >> value;
    x--, y--;
    if (x < 0 || y < 0 || x > 8 || y > 8 || board.highlight[x][y] == '1') {
        valid_input = 0;
        return;
    }
    if (board.numbers[x][y] != value) {
        fails++;
        wrong_ans = 1;
        return;
    }

    board.highlight[x][y] = 1;
    int a = board.mapp[{x,y}].first, b = board.mapp[{x,y}].second;
    board.board[a][b] = value + '0';
}

void Game::feedback() {
    if (!valid_input) {
        std::cout << "Please enter a valid coordinates." << std::endl;
    }
    else if (wrong_ans) {
        std::cout << "Wrong answer :(" << std::endl;
    }
    else {
        std::cout << "Correct!" << std::endl;
    }
}

bool Game::win(Board &board) {
    for (auto i : board.highlight) {
        for (auto j : i) {
            if (j == '0')
                return false;
        }
    }
    return true;
}