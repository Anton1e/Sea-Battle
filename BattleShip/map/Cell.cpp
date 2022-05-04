#include "Cell.h"

// Des/Cpn
Cell::Cell(char cell_type, int x, int y, char ship_type, int ship_number): cell_type_(cell_type), 
                                                                           x_coor_(x), 
                                                                           y_coor_(y),
                                                                           ship_type_(ship_type),
                                                                           ship_number_(ship_number)
{}

Cell::~Cell() {}

// accessor functions
char Cell::getType() {
    return cell_type_;
}

bool Cell::isBoat() {
    return ship_type_ != ' ';
}

char Cell::getBoatType() {
    return ship_type_;
}

int Cell::getBoatNumber() {
    return ship_number_;
}

// change cell type
void Cell::changeCell() {
    cell_type_ = '.';
}

// put a ship down
void Cell::setTypeShip(char ship_type, int ship_number) {
    cell_type_ = ship_type;
    ship_type_ = ship_type;
    ship_number_ = ship_number;
}

// change cell accordingly when a boat is hit
void Cell::changeCellWhenHitWithBoat() {
    cell_type_ = 'X';
    ship_number_ = -1;
    ship_type_ = ' ';
}

// change cell when hit but there is no boat
void Cell::changeCellWhenHitWithNoBoat() {
    cell_type_ = 'O';
}
