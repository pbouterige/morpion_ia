#include "game/Player.hpp"

Player::Player(const std::string& name, symbols symbol) : name(name), symbol(symbol) {}

Player::~Player() {}

std::string Player::getName() const {
    return name;
}

symbols Player::getSymbol() const {
    return symbol;
}
