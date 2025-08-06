#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>
#include "Human.hpp"
#include "AI.hpp"



class Board {
    private:
        std::vector<std::vector<symbols>> board;
        Player *playerX;
        Player *playerO;

    public:
        Board();
        ~Board();
        void displayBoard() const;
        int isFinished() const;

        const symbols & getCell(const int& x, const int& y) const;
        void setCell(const int& x, const int& y, const symbols symbol);

        void setPlayerX(Player *player) { playerX = player; }
        void setPlayerO(Player *player) { playerO = player; }

        Player* getPlayerX() const { return playerX; }
        Player* getPlayerO() const { return playerO; }

        int play_game();

        void resetBoard();

};



#endif