#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "Board.h"
#include "Game.h"

void run(Board &board, Game &game) {
    do {
        system("CLS");
        Sleep(50);
        board.show_board();
        if (Game::tries)
            game.feedback();
        game.play(board);
    } while (Game::fails <= 5 && !game.win(board));
}

int main() {
    char c;
    do {
        Board *board = new Board;
        Game *game = new Game;
        run(*board, *game);

        if (Game::fails < 4)
            std::cout << "Congratulations!!\nGG!" << std::endl;
        else
            std::cout << "Hard luck :(" << std::endl;

        std::cout << "\nDo you want to play again?\npress Y to play again and N to exit.\n";
        std::cin >> c;
        c = tolower(c);
        Game::fails = 0;
        delete board;
        delete game;
    } while (c == 'y');
}