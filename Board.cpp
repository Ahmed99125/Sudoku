//
// Created by at991 on 8/21/2023.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include "Board.h"
#include "Game.h"

Board::Board() {
    numbers.resize(9, std::vector <int> (9));
    generate_numbers(0, 0);
    draw_board(board);
}

void Board::show_board() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    std::cout << "\n";
    SetConsoleTextAttribute(h, 5);
    std::cout << "==========================================" << std::endl;
    SetConsoleTextAttribute(h, 15);
    std::cout << "                  SUDOKU                  " << std::endl;
    SetConsoleTextAttribute(h, 5);
    std::cout << "==========================================" << std::endl;
//    std::cout << "\n";

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 37; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                SetConsoleTextAttribute(h, 15);
            else if (board[i][j] == '#')
                SetConsoleTextAttribute(h, 8);
            else
                SetConsoleTextAttribute(h, 5);
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(h, 15);
    std::cout << "Mistakes: " << Game::fails << '/' << 5 << std::endl;
}

void Board::draw_board(char (&board)[19][37]) {
    int a = 0, b = 0;
    for (int i = 0; i < 19; i++) {
        board[i][0] = '$';
        if (i == 0 || i == 18 || i % 6 == 0) {
            for (int j = 1; j < 36; j++) board[i][j] = '$';
        }
        else if (i % 2 == 0) {
            for (int j = 1; j < 36; j++) {
                if (j == 12 || j == 24) {
                    board[i][j] = '$';
                }
                else {
                    board[i][j] = '-';
                }
            }
        }
        else {
            int x = 2;
            for (int j = 1; j < 36; j++) {
                if (j == 12 || j == 24) {
                    board[i][j] = '$';
                }
                else if (j == x) {
                    mapp[{a, b}] = {i, j};
                    if (highlight[a][b] == '1')
                        board[i][j] = numbers[a][b] + '0';
                    else
                        board[i][j] = '#';
                    x += 4;
                    b++;
                }
                else if (j % 4 == 0) {
                    board[i][j] = '|';
                }
                else {
                    board[i][j] = ' ';
                }
            }
            a++;
            b = 0;
        }

        board[i][36] = '$';
    }
}

bool Board::generate_numbers(int x, int y) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (nums, nums+9, std::default_random_engine(seed));

    if (y > 8)
        y = 0, x++;
    if (x > 8)
        return true;
    int a = x/3, b = y/3;

    if (numbers[x][y] != 0) {
        if (generate_numbers(x, y+1))
            return true;
    }

    for (int i = 0; i < 9; i++) {

        int rand = nums[i];
        if (rows[x].count(rand) || cols[y].count(rand) || box[{a, b}].count(rand))
            continue;

        numbers[x][y] = rand;
        rows[x].insert(rand), cols[y].insert(rand), box[{a, b}].insert(rand);

        if (generate_numbers(x, y+1))
            return true;

        rows[x].erase(rand);
        cols[y].erase(rand);
        box[{a, b}].erase(rand);
        numbers[x][y] = 0;
    }
    return false;
}