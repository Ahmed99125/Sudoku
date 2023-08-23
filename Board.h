//
// Created by at991 on 8/21/2023.
//

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <vector>
#include <string>
#include <map>
#include <set>


class Board {
    friend class Game;

private:
    char board[19][37];
    std::map <std::pair<int, int>, std::pair<int, int>> mapp;
    std::vector <std::vector <int>> numbers;
    std::vector <std::string> highlight = {
            "011100001",
            "101100100",
            "100010001",
            "010000110",
            "100000001",
            "011000010",
            "100010001",
            "001001101",
            "100001110"
    };
    bool generate_status;
    std::map <int, std::set<int>> rows, cols;
    std::map <std::pair<int, int>, std::set<int>> box;
    void draw_board(char (&board)[19][37]);
    bool generate_numbers(int x, int y);
public:
    Board();
    void show_board();
};


#endif //SUDOKU_BOARD_H
