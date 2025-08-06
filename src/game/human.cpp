#include "game/human.hpp"
#include <iostream>

Human::Human(const std::string& name, symbols symbol) : Player(name, symbol) {}

Human::~Human() {}

void Human::makeMove(int & x, int & y) {
    std::cout << "Enter your move " << getName() << " (row and column): ";
    std::cin >> x >> y;
}
