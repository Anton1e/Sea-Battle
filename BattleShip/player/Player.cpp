#include "Player.h"
#include "DestroySquare.h"
#include "DestroyRow.h"

// Con/Des
Player::Player(): board_(new Board()), 
                  number_of_dead_ships_(0), 
                  points_(0),
                  skill_indicator_(-1)
{
    skills_.push_back(new DestroyRow());
    skills_.push_back(new DestroySquare());
}

Player::~Player() {
    delete board_;

    clearSubmarines();
    clearDestroyers();
    clearBattleships();
    clearCarriers();

    for (int i = 0; i < skills_.size(); ++i) {
        delete skills_[i];
    }
}

// set ships
void Player::setShips(std::string start_position, std::string end_position, char type) {
    switch (type) {
        case 'S':
            submarines_.push_back(new Submarine());
            board_->setShip(start_position, start_position, 'S', submarines_.size() - 1);
            break;

        case 'D':
            destroyers_.push_back(new Destroyer());
            board_->setShip(start_position, end_position, 'D', destroyers_.size() - 1);
            break;

        case 'B':
            battleships_.push_back(new Battleship());
            board_->setShip(start_position, end_position, 'B', battleships_.size() - 1);
            break;

        case 'C':
            carriers_.push_back(new Carrier());
            board_->setShip(start_position, end_position, 'C', carriers_.size() - 1);
    }
}

// fire a cell
void Player::fire(std::pair<int, int> coors) {
    int x_coor = coors.first, y_coor = coors.second;

    if (board_->getCell(x_coor, y_coor)->isBoat()) {
        checkWhatWasHit(x_coor, y_coor);
        board_->getCell(x_coor, y_coor)->changeCellWhenHitWithBoat();
    }
    else {
        if (board_->getCell(x_coor, y_coor)->getType() == 'X') {
            return;
        }
        
        board_->getCell(x_coor, y_coor)->changeCellWhenHitWithNoBoat();
    }
}

// check if lost
bool Player::isGameover() {
    return number_of_dead_ships_ == total_number_of_ships_;
}

// accessor
Board* Player::getBoard() {
    return board_;
}

int Player::getPoints() {
    return points_;
}

int Player::getSkillIndicator() {
    return skill_indicator_;
}

int Player::getSkillPoints() {
    return skills_[skill_indicator_]->getPoints();
}

// set the skill
void Player::setSkillIndicator(int x) {
    skill_indicator_ = x;
}

// use the chosen skill
void Player::useSkill(int row, int column) {
    if (skill_indicator_ == 0) {
        static_cast<DestroyRow*>(skills_[0])->activate(*this, row);
    }
    else {
        static_cast<DestroySquare*>(skills_[1])->activate(*this, row, column);
    }

    points_ -= skills_[skill_indicator_]->getPoints();
}

// check whether a ship could be placed
bool Player::checkIfValid(std::string first_pos, std::string second_pos, int expected_length) {
    if (first_pos.size() != 2 || second_pos.size() != 2) {
        return false;
    }

    if (first_pos[1] - '0' < 0 || first_pos[1] - '0' > 9 || first_pos[0] - 'A' < 0 || first_pos[0] - 'A' > 9 ||
        second_pos[1] - '0' < 0 || second_pos[1] - '0' > 9 || second_pos[0] - 'A' < 0 || second_pos[0] - 'A' > 9) {
        return false;
    }

    if (first_pos[0] != second_pos[0] && first_pos[1] != second_pos[1]) {
        return false;
    }

    if (first_pos[0] == second_pos[0] && std::max(first_pos[1] - second_pos[1], second_pos[1] - first_pos[1]) + 1 != expected_length ||
        first_pos[1] == second_pos[1] && std::max(first_pos[0] - second_pos[0], second_pos[0] - first_pos[0]) + 1 != expected_length) {
        return false;
    } 

    int first_x = first_pos[0] - 'A', first_y = first_pos[1] - '0';
    int second_x = second_pos[0] - 'A', second_y = second_pos[1] - '0';

    int first_start = std::min(first_x, second_x), first_end = std::min(first_y, second_y);
    int second_start = std::max(first_x, second_x), second_end = std::max(first_y, second_y);

    for (int i = first_start; i <= second_start; ++i) {
        for (int j = first_end; j <= second_end; ++j) {
            if (board_->getCell(i, j)->isBoat()) {
                return false;
            }
        }
    }

    return true;
}

// check which ship was hit
void Player::checkWhatWasHit(int x_coor, int y_coor) {
    char ship_type = board_->getCell(x_coor, y_coor)->getBoatType();
    int ship_number = board_->getCell(x_coor, y_coor)->getBoatNumber();
    
    switch(ship_type) {
        case 'S':

            submarines_[ship_number]->isHit();
            ++points_;
            if (submarines_[ship_number]->isDead()) {
                ++number_of_dead_ships_;
            } 
            break;
        
        case 'D':

            destroyers_[ship_number]->isHit();
            ++points_;
            if (destroyers_[ship_number]->isDead()) {
                ++number_of_dead_ships_;
            }
            break;

        case 'B':
            battleships_[ship_number]->isHit();
            ++points_;
            if (battleships_[ship_number]->isDead()) {
                ++number_of_dead_ships_;
            } 
            break;
        
        case 'C':
            carriers_[ship_number]->isHit();
            ++points_;
            if (carriers_[ship_number]->isDead()) {
                ++number_of_dead_ships_;
            }
            break;
    } 
}

// deleters
void Player::clearSubmarines() {
    for (int i = 0; i < submarines_.size(); ++i) {
        delete submarines_[i];
    }
}

void Player::clearDestroyers() {
    for (int i = 0; i < destroyers_.size(); ++i) {
        delete destroyers_[i];
    }
}

void Player::clearBattleships() {
    for (int i = 0; i < battleships_.size(); ++i) {
        delete battleships_[i];
    }
}

void Player::clearCarriers() {
    for (int i = 0; i < carriers_.size(); ++i) {
        delete carriers_[i];
    }
}
