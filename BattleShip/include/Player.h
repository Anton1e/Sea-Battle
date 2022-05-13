#pragma once
#include <vector>
#include <string>
#include "Board.h"
#include "Ship.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Battleship.h"
#include "Carrier.h"
#include "Interface.h"

class Player {
public:
    // Con/Des
    Player();
    ~Player();

    // set ships
    void setShips();
    
    // fire a cell
    void fire();

    // check if lost
    bool isGameover();

    // accessor 
    Board* getBoard();

private:
    // check whether a ship could be placed;
    bool checkPositions(std::string first_pos, std::string second_pos, int expected_length);

    // deleters
    void clearSubmarines();
    void clearDestroyers();
    void clearBattleships();
    void clearCarriers();

    // number of boats
    static const int total_number_of_ships_ = 10;
    static const int number_of_submarines_ = 4;
    static const int number_of_destroyers_ = 3;
    static const int number_of_battleships_ = 2;
    static const int number_of_carriers_ = 1;

    // set of boats for the player
    std::vector<Submarine*>  submarines_;
    std::vector<Destroyer*> destroyers_;
    std::vector<Battleship*> battleships_;
    std::vector<Carrier*> carriers_;

    // player has a game board)
    Board* board_;

    // player's parameters
    int number_of_dead_ships_;

    // interface
    Interface interface;
};
