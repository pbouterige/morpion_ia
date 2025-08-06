#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

enum symbols {
    EMPTY = 0,
    PLAYER_X = 1,
    PLAYER_O = 2
};


class Player {
    protected:
        std::string name;
        symbols symbol;

    public:
        Player(const std::string& name, symbols symbol);
        virtual ~Player();

        std::string getName() const;
        symbols getSymbol() const;

        // Méthode virtuelle pure pour rendre la classe abstraite
        virtual void makeMove(int & x, int & y) = 0;
};

#endif