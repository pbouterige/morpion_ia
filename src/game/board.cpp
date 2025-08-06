#include "game/board.hpp"

Board::Board() {
    board.resize(3, std::vector<symbols>(3, EMPTY));
}

Board::~Board() {
    // Destructor
}

void Board::displayBoard() const{

    int i = 0;
    std::cout << "   |   0   |   1   |   2   |" << std::endl;
    for (const auto& row : board) {
        std::cout << "----------------------------" << std::endl;
        std::cout << "   |       |       |       |" << std::endl;
        std::cout << " " << i << " |";
        for (const auto& cell : row) {
            switch (cell) {
                case EMPTY:
                    std::cout << "       |";
                    break;
                case PLAYER_X:
                    std::cout << "   X   |";
                    break;
                case PLAYER_O:
                    std::cout << "   O   |";
                    break;
            }
        }
        std::cout << std::endl;
        std::cout << "   |       |       |       |" << std::endl;
        ++i;
    }
    std::cout << "----------------------------" << std::endl;
}

int Board::isFinished() const {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == PLAYER_X) {
                return 1; // Player X wins
            } else if (board[i][0] == PLAYER_O) {
                return 2; // Player O wins
            }
        }
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == PLAYER_X) {
                return 1; // Player X wins
            } else if (board[0][i] == PLAYER_O) {
                return 2; // Player O wins
            }
        }
    }
    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == PLAYER_X) {
            return 1; // Player X wins
        } else if (board[0][0] == PLAYER_O) {
            return 2; // Player O wins
        }
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == PLAYER_X) {
            return 1; // Player X wins
        } else if (board[0][2] == PLAYER_O) {
            return 2; // Player O wins
        }
    }
    // Check for draw
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == EMPTY) {
                return 0; // Game is still ongoing
            }
        }
    }
    return -1; // Draw
}

const symbols& Board::getCell(const int& x, const int& y) const {
    return board[x][y];
}

void Board::setCell(const int& x, const int& y, const symbols symbol) {
    board[x][y] = symbol;
}

void Board::resetBoard() {
    for (auto& row : board) {
        std::fill(row.begin(), row.end(), EMPTY);
    }
}

int Board::play_game() {
    int results = 0;
    while (!(results = isFinished())) {
        displayBoard();
        int x, y;
        playerX->makeMove(x, y, *this);
        // Validate move
        while (x < 0 || x >= 3 || y < 0 || y >= 3 || getCell(x, y) != EMPTY) {
            std::cout << "Invalid move. Try again: ";
            playerX->makeMove(x, y, *this);
        }
        setCell(x, y, playerX->getSymbol());
        
        displayBoard();
        if ((results = isFinished())) {
            break;
        }

        playerO->makeMove(x, y, *this);
        // Validate move
        while (x < 0 || x >= 3 || y < 0 || y >= 3 || getCell(x, y) != EMPTY) {
            std::cout << "Invalid move. Try again: ";
            playerO->makeMove(x, y, *this);
        }
        setCell(x, y, playerO->getSymbol());
    }

    displayBoard();
    return results;
}