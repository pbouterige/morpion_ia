#include <iostream>
#include "game/board.hpp"


int main() {
    std::cout << "===========  Morpion  ============" << std::endl << std::endl;

    // Initialize the game board and players
    Board gameBoard{};
    Human playerX("Player X", PLAYER_X);
    AI playerO("Player O", PLAYER_O);

    gameBoard.setPlayerX(&playerX);
    gameBoard.setPlayerO(&playerO);

    // Start the game
    int res;
    res = gameBoard.play_game();

    // Display the result
    if (res == 1) {
        std::cout << "Player X wins!" << std::endl;
    } else if (res == 2) {
        std::cout << "Player O wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}