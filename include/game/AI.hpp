#ifndef AI_HPP
#define AI_HPP

#include "Player.hpp"

class AI : public Player {
    public:
        AI(const std::string& name, symbols symbol);
        virtual ~AI();

        virtual void makeMove(int & x, int & y, Board & board) override;
};

#endif