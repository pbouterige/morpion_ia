#include "game/AI.hpp"
#include "game/board.hpp"
#include <cstdlib>
#include <ctime>

AI::AI(const std::string& name, symbols symbol) : Player(name, symbol) {
    std::srand(std::time(nullptr)); // Seed for random number generation
}

AI::~AI() {
    // Destructor
}

void AI::makeMove(int & x, int & y, Board & board) {
    // Randomly select an empty cell
    do {
        x = std::rand() % 3;
        y = std::rand() % 3;
    } while (board.getCell(x, y) != EMPTY);
}