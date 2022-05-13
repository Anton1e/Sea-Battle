#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Cell.h"

class Board {
public:
    // Con/Des
    Board();
    ~Board();
    
    // printing
    void printBoard();

    // put a ship down
    void setShip(std::string first_pos, std::string second_pos, char ship_type, int ship_number);

    // accessor
    Cell* getCell(int x, int y);

    // remove ship types as they are only shown during setting phase
    void withoutShipTypes();

private:
    // size of board
    static const int width_ = 10;
    static const int height_ = 10;

    // board
    std::vector<std::vector<Cell*>> board_;
};
