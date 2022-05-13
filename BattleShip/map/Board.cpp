#include "Board.h"

// Con/Des
Board::Board() {
    for (int i = 0; i < height_; ++i) {
        board_.resize(width_);
        for (int j = 0; j < width_; ++j) {
            board_[i].push_back(new Cell('.', i, j, ' ', -1));
        }
    }
}

Board::~Board() {
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            delete board_[i][j];
        }
    }
}

// put a ship down
void Board::setShip(std::string first_pos, std::string second_pos, char ship_type, int ship_number) {
    int first_x = first_pos[0] - 'A', first_y = first_pos[1] - '0';
    int second_x = second_pos[0] - 'A', second_y = second_pos[1] - '0';

    int first_start = std::min(first_x, second_x), first_end = std::min(first_y, second_y);
    int second_start = std::max(first_x, second_x), second_end = std::max(first_y, second_y);

    for (int i = first_start; i <= second_start; ++i) {
        for (int j = first_end; j <= second_end; ++j) { 
            board_[i][j]->setTypeShip(ship_type, ship_number);
        }
    }
}

// accessor
Cell* Board::getCell(int x, int y) {
    return board_[x][y];
}

int Board::getWidth() {
    return width_;
}

int Board::getHeight() {
    return height_;
}

// remove ship types as they are only shown during setting phase
void Board::withoutShipTypes() {
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            if (board_[i][j]->isBoat()) {
                board_[i][j]->changeCell();
            }
        }
    }
}
