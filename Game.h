//
// Created by at991 on 8/22/2023.
//

#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include "Board.h"


class Game {
private:
    int x, y, value;
    static bool valid_input, wrong_ans;
public:
    static int fails, tries;
    void play(Board &board);
    void feedback();
    bool win(Board &board);
};


#endif //SUDOKU_GAME_H
