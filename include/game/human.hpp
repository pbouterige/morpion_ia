#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Player.hpp"

class Human : public Player {
    public:
        Human(const std::string& name, symbols symbol);
        virtual ~Human();

        virtual void makeMove(int & x, int & y) override;
};

#endif