#include "Player.h"

// Con/Des
Player::Player(): board_(new Board()), number_of_dead_ships_(0) {}

Player::~Player() {
    delete board_;

    clearSubmarines();
    clearDestroyers();
    clearBattleships();
    clearCarriers();
}

// set ships
void Player::setShips() {
    std::string start_position, end_position;

    for (int i = 0; i < number_of_submarines_; ++i) {
        start_position = interface.printSetSubmarine(board_, i);
        while (!checkPositions(start_position, start_position, 1)) {
            start_position = interface.printNotValidPosition().first;
        }
        submarines_.push_back(new Submarine());
        board_->setShip(start_position, start_position, 'S', i);
    }

    for (int i = 0; i < number_of_destroyers_; ++i) {
        std::pair<std::string, std::string> positions = interface.printSetDestroyer(board_, i);
        start_position = positions.first;
        end_position = positions.second;
        while (!checkPositions(start_position, end_position, 2)) {
            positions = interface.printNotValidPosition();
            start_position = positions.first;
            end_position = positions.second;
        }
        destroyers_.push_back(new Destroyer());
        board_->setShip(start_position, end_position, 'D', i);
    }

    for (int i = 0; i < number_of_battleships_; ++i) {
        std::pair<std::string, std::string> positions = interface.printSetBattleship(board_, i);
        start_position = positions.first;
        end_position = positions.second;
        while (!checkPositions(start_position, end_position, 3)) {
            positions = interface.printNotValidPosition();
            start_position = positions.first;
            end_position = positions.second;
        }
        battleships_.push_back(new Battleship());
        board_->setShip(start_position, end_position, 'B', i);
    } 

    for (int i = 0; i < number_of_carriers_; ++i) {
        std::pair<std::string, std::string> positions = interface.printSetCarrier(board_, i);
        start_position = positions.first;
        end_position = positions.second;
        while (!checkPositions(start_position, end_position, 4)) {
            positions = interface.printNotValidPosition();
            start_position = positions.first;
            end_position = positions.second;
        }
        carriers_.push_back(new Carrier());
        board_->setShip(start_position, end_position, 'C', i);
    }
    
    board_->withoutShipTypes();
}

// fire a cell
void Player::fire() {
    std::pair<int, int> coors = interface.getCoorForAttack(board_);
    int x_coor = coors.first, y_coor = coors.second;

    while (board_->getCell(x_coor, y_coor)->isBoat()) {
        interface.printWhenHit();
        
        char ship_type = board_->getCell(x_coor, y_coor)->getBoatType();
        int ship_number = board_->getCell(x_coor, y_coor)->getBoatNumber();
        
        switch(ship_type) {
            case 'S':
                submarines_[ship_number]->isHit();
                if (submarines_[ship_number]->isDead()) {
                    ++number_of_dead_ships_;
                } 
                break;
            
            case 'D':
                destroyers_[ship_number]->isHit();
                if (destroyers_[ship_number]->isDead()) {
                    ++number_of_dead_ships_;
                }
                break;

            case 'B':
                battleships_[ship_number]->isHit();
                if (battleships_[ship_number]->isDead()) {
                    ++number_of_dead_ships_;
                } 
                break;
            
            case 'C':
                carriers_[ship_number]->isHit();
                if (carriers_[ship_number]->isDead()) {
                    ++number_of_dead_ships_;
                }
                break;
        }

        if (isGameover()) {
            return;
        }

        board_->getCell(x_coor, y_coor)->changeCellWhenHitWithBoat();
            
        coors = interface.getCoorForAttack(board_);
        x_coor = coors.first;
        y_coor = coors.second;
    }

    if (!board_->getCell(x_coor, y_coor)->isBoat()) {
        interface.printWhenMissHit();
       
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

Board* Player::getBoard() {
    return board_;
}

// check whether a ship could be placed
bool Player::checkPositions(std::string first_pos, std::string second_pos, int expected_length) {
    if (first_pos.size() != 2 || second_pos.size() != 2) {
        return false;
    }

    if (first_pos[1] - '0' < 0 || first_pos[1] - '0' > 9 || first_pos[0] - 'A' < 0 || first_pos[0] - 'A' > 9 ||
        second_pos[1] - '0' < 0 || second_pos[1] - '0' > 9 || second_pos[0] - 'A' < 0 || second_pos[0] - 'A' > 9) {
        return false;
    }

    if (first_pos[0] != second_pos[0] && first_pos[1] != second_pos[1]) {
        std::cout << "3\n";
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
